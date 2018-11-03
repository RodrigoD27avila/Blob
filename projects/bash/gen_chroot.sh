#!/bin/bash
e2fsck /dev/hda1
mount /dev/hda3 /mnt/gentoo
mount /dev/hda1 /mnt/gentoo/boot
mount -t proc none /mnt/gentoo/proc
mount -o bind /dev /mnt/gentoo/dev
chroot /mnt/gentoo /bin/bash
env-update
source /etc/profile
export PS1="(CHROOT) $PS1"

