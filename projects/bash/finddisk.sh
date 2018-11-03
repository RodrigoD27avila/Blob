#!/bin/bash
finddisks() {
    workdir="$PWD"
    cd /sys/block
    # ide devices
    for dev in $(ls | egrep '^hd'); do
        if [ "$(cat $dev/device/media)" = "disk" ]; then
            if [ "$(dmesg | grep sectors | grep $dev)" ]; then
                echo "/dev/$dev"
                [ "$1" ] && echo $1
            fi
        fi
    done
    #scsi/sata devices
    for dev in $(ls | egrep '^sd'); do
        if ! [ "$(cat $dev/device/type)" = "5" ]; then
            if [ "$(dmesg | grep sectors | grep $dev)" ]; then
                echo "/dev/$dev"
                [ "$1" ] && echo $1
            fi
        fi
    done
    # cciss controllers
    if [ -d /dev/cciss ] ; then
        cd /dev/cciss
        for dev in $(ls | egrep -v 'p'); do
            echo "/dev/cciss/$dev"
            [ "$1" ] && echo $1
        done
    fi
    # Smart 2 controllers
        if [ -d /dev/ida ] ; then
                cd /dev/ida
                for dev in $(ls | egrep -v 'p'); do
                        echo "/dev/ida/$dev"
                        [ "$1" ] && echo $1
                done
        fi
    cd "$workdir"
}

findpartitions() {
    workdir="$PWD"
    for devpath in $(finddisks); do
        disk=$(echo $devpath | sed 's|.*/||')
        cd /sys/block/$disk
        for part in $disk*; do
        #    if [ -d $part ]; then
                echo "/dev/$part"
                [ "$1" ] && echo $1
         #   fi
        done
    done
    
	cd "$workdir"
}

finddisks
echo ""
findpartitions

