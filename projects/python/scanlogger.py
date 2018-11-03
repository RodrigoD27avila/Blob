#!/usr/bin/env python
"""
pyscanlogger: Simple port scan detector/logger tool, inspired
by scanlogd {http://www.openwall.com/scanlogd}

Author: Anand B Pillai <abpillai at gmail dot com>
Copyright: Public Domain, No warranty

Have fun :-) !

"""

import sys, os
import dpkt, pcap
import struct
import socket
import time
import threading

__author__ = "Anand B Pillai"
__maintainer__ = "Anand B Pillai"
__version__ = 0.1
__modified__ = "Sat Mar 14 14:12:49 IST 2009"

SCAN_TIMEOUT = 5
WEIGHT_THRESHOLD = 25
PIDFILE="/var/run/pyscanlogger.pid"

# TCP flag constants
TH_URG=dpkt.tcp.TH_URG
TH_ACK=dpkt.tcp.TH_ACK
TH_PSH=dpkt.tcp.TH_PUSH
TH_RST=dpkt.tcp.TH_RST
TH_SYN=dpkt.tcp.TH_SYN
TH_FIN=dpkt.tcp.TH_FIN

get_timestamp = lambda : time.strftime('%Y-%m-%d %H:%M:%S', time.localtime())

class ScanEntry(object):
    """ Port scan entry """
    
    def __init__(self, hash):
        self.src = 0
        self.timestamp = 0
        self.logged = False
        self.type = ''
        self.tcpflags = 0
        self.weight = 0
        self.ports = []
        self.next = None
        self.hash = hash

class EntryLog(dict):
    """ Modified dictionary class with fixed size, which
    automatically removes oldest items """

    # This will work only if the value is an object storing
    # its key in the 'hash' attribute and links to other
    # objects usin the 'next' attribute.
    def __init__(self, maxsz):
        self.oldest = None
        self.last = None
        self.maxsz = maxsz
        super(EntryLog, self).__init__()

    def __setitem__(self, key, value):
        if not self.__contains__(key) and len(self)==self.maxsz:
            # Remove oldest
            if self.oldest:
                self.__delitem__(self.oldest.hash)
                self.oldest = self.oldest.next
        
        super(EntryLog, self).__setitem__(key,value)

        if self.last:
            self.last.next = value
            self.last = value
        else:
            self.last = value
            self.oldest = self.last

class ScanLogger(object):
    """ Port scan detector/logger """
    
    # TCP flags to scan type mapping
    scan_types = {0: 'null', TH_FIN: 'fin', TH_SYN: 'syn', TH_ACK: 'ack',
                  TH_URG|TH_PSH|TH_FIN: 'x-mas', TH_SYN|TH_FIN: 'syn/fin',
                  TH_FIN|TH_ACK: 'fin/ack',
                  TH_URG|TH_PSH|TH_ACK|TH_RST|TH_SYN|TH_FIN: 'all-flags' } 
                  
    def __init__(self, timeout, threshold, maxsize, daemon=True, logfile='/var/log/scanlog'):
        self.scans = EntryLog(maxsize)
        # Port scan weight threshold
        self.threshold = threshold
        # Timeout for scan entries
        self.timeout = timeout
        # Daemonize ?
        self.daemon = daemon
        # Log file
        self.scanlog = open(logfile,'a')
        
    def hash_func(self, addr):
        """ Hash a host address """
        
        value = addr
        h = 0
    
        while value:
            # print value
            h ^= value
            value = value >> 9
        
        return h & (8192-1)

    def host_hash(self, src, dst):
        """ Hash mix two host addresses """

        return self.hash_func(src)^self.hash_func(dst)

    def process(self, pkt):

        if not hasattr(pkt, 'ip'):
            return

        ip = pkt.ip
        # Ignore non-tcp packets
        if type(ip.data) != dpkt.tcp.TCP:
            return

        tcp = ip.data
        src,dst,dport,flags = int(struct.unpack('I',ip.src)[0]),int(struct.unpack('I', ip.dst)[0]),int(tcp.dport),tcp.flags
        srcip, dstip = socket.inet_ntoa(ip.src),socket.inet_ntoa(ip.dst)
        key = self.host_hash(src,dst)

        curr=time.time()

        if key in self.scans:
            scan = self.scans[key]

            if scan.src != src:
                # Skip packets in reverse direction
                return
                
            # Update only if not too old, else skip and remove entry
            if curr - scan.timestamp > self.timeout:
                del self.scans[key]

            if scan.logged: return
            
            # Update TCP flags if existing port
            if dport in scan.ports:
                # Same port, update flags
                scan.tcpflags |= flags
                return
                
            scan.timestamp = curr
            scan.tcpflags |= flags
            scan.ports.append(dport)

            # Add weight for port
            if dport < 1024:
                scan.weight += 3
            else:
                scan.weight += 1
            
            if scan.weight>=self.threshold:
                scan.logged = True
                scan.type = self.scan_types.get(scan.tcpflags,'unknown')
                ports = ','.join([str(port) for port in scan.ports])
                
                self.scanlog.write('[%s]: %s port scan(flags:%d) from %s to %s on ports %s\n' % (get_timestamp(),
                                                                                                 scan.type,
                                                                                                 scan.tcpflags,
                                                                                                 srcip,dstip,
                                                                                                 ports))
                self.scanlog.flush()

                if not self.daemon:
                    print '[%s]: %s port scan(flags:%d) from %s to %s on ports %s' % (get_timestamp(),
                                                                                      scan.type,
                                                                                      scan.tcpflags,
                                                                                      srcip,dstip,
                                                                                      ports)

        else:
            # Add new entry
            scan = ScanEntry(key)
            scan.src = src
            scan.timestamp = curr
            scan.tcpflags |= flags
            scan.ports.append(dport)
            self.scans[key] = scan
            
    def log(self):
        
        pc = pcap.pcap()
        decode = { pcap.DLT_LOOP:dpkt.loopback.Loopback,
                   pcap.DLT_NULL:dpkt.loopback.Loopback,
                   pcap.DLT_EN10MB:dpkt.ethernet.Ethernet } [pc.datalink()]

        try:
            print 'listening on %s: %s' % (pc.name, pc.filter)
            for ts, pkt in pc:
                self.process(decode(pkt))
        except KeyboardInterrupt:
            if not self.daemon:
                nrecv, ndrop, nifdrop = pc.stats()
                print '\n%d packets received by filter' % nrecv
                print '%d packets dropped by kernel' % ndrop

    def run_dameon(self):
        # Disconnect from tty
        try:
            pid = os.fork()
            if pid>0:
                sys.exit(0)
        except OSError, e:
            print >>sys.stderr, "fork #1 failed", e
            sys.exit(1)

        os.setsid()
        os.umask(0)

        # Second fork
        try:
            pid = os.fork()
            if pid>0:
                open(PIDFILE,'w').write(str(pid))
                sys.exit(0)
        except OSError, e:
            print >>sys.stderr, "fork #2 failed", e
            sys.exit(1)
            
        self.log()
        
    def run(self):
        # If dameon, then create a new thread and wait for it
        if self.daemon:
            print 'Daemonizing...'
            self.run_dameon()
        else:
            # Run in foreground
            self.log()
            
if __name__ == '__main__':
    s=ScanLogger(SCAN_TIMEOUT, WEIGHT_THRESHOLD, 8192, False)
    s.run()
