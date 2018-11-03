# USAGE: python FileSender.py [file]

import sys, socket

HOST = 'localhost'
CPORT = 9091
MPORT = 9090
FILE = sys.argv[1]

cs = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
cs.connect((HOST, CPORT))
cs.send("SEND " + FILE)
cs.close()

ms = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
ms.connect((HOST, MPORT))

f = open(FILE, "rb")
data = f.read()
f.close()

ms.send(data)
ms.close()
