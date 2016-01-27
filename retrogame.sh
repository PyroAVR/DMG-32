#!/bin/sh -e
### BEGIN INIT INFO
# Provides:           retrogame
# Required-Start:
# Required-Stop:
# Default-Start:     2
# Default-Stop:     6
# Short-Description: Virtual keyboard from GPIO
# Description:  Run retrogame from Adafruit Industries/Pixel located in /opt/init to create a virtual keyboard which reads directly from GPIO to creates keypress events.
### END INIT INFO
modprobe evdev
modprobe uinput
do_start()  {
  start-stop-daemon -S /opt/system/retrogame
  exit 0
}
case "$1" in
  start|"")
    echo -n "Starting Retrogame..."
    do_start
    echo "Done!"
    ;;
  stop)
    echo -n "Killing Retrogame..."
    start-stop-daemon -K retrogame
    echo "Done!"
    ;;
  restart)
    echo -n "Stopping Retrogame..."
    start-stop-daemon -K retrogame
    echo "Done!"
    echo -n "Starting Retrogame..."
    do_start
    ;;
  *)
  echo "Usage: retrogame {start|stop|restart}"
  exit 3
  ;;
esac
