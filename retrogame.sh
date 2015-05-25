#!/bin/sh -e
### BEGIN INIT INFO
# Provides:           retrogame
# Required-Start:  uinput evdev
# Required-Stop:
# Default-Start:     2
# Default-Stop:     6
# Short-Description: Virtual keyboard from GPIO
# Description:  Run retrogame from Adafruit Industries located in /opt/init to create a virtual keyboard which reads directly from GPIO to creates keypress events.
### END INIT INFO
case $1 in
  start)
    echo -n "Starting Retrogame..."
    nohup /opt/init/retrogame
    echo "Done!"
    ;;
  stop)
    echo -n "Killing Retrogame..."
    killall retrogame
    echo "Done!"
    ;;
  restart)
    echo -n "Stopping Retrogame..."
    killall retrogame
    echo "Done!"
    echo -n "Starting Retrogame..."
    nohup retrogame
    ;;
esac
