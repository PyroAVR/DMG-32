#!/bin/sh -e
### BEGIN INIT INFO
# Provides:           syncservice
# Required-Start:
# Required-Stop:
# Default-Start:     2
# Default-Stop:     6
# Short-Description: Sync /opt files from USB
# Description: Mount and sync files from a USB stick using rsync for updates and new roms. 
### END INIT INFO
MOUNT_DIR='/home/andy/mnt'
SOURCE_DIR='dmg32-patch/'
DEST_DIR='/home/andy/test'
mount_device()   {
    if [ -e /dev/sda1 ]; then
        mount /dev/sda1 $MOUNT_DIR
        return 0
    else
        return 1
    fi
}
unmount_device() {
    if [ -n "`mount | grep $MOUNT_DIR`" ];then
        umount $MOUNT_DIR
    fi
}
check_path()    {
    if [ -d $MOUNT_DIR/$SOURCE_DIR ]; then
        return 1
    else
        return 0
    fi
}
do_sync()   {
    echo -n "Mounting..."
    mount_device
    echo "Done!"
    if [ check_path ]; then
        echo -n "Found source path - syncing..."
        echo " Done!"
        rsync -rv $MOUNT_DIR/$SOURCE_DIR $DEST_DIR
    else
        echo "Device found - source path not found.  Could not sync."
    fi
    unmount_device
    echo "Operations complete - Safe to remove media."
    sleep 5
}

do_sync
