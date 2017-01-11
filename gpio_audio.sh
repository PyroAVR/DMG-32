#!/bin/sh -e
### BEGIN INIT INFO
# Provides:	gpio_audio
# Required-Start:
# Required-Stop:
# Default-Start:	2
# Default-Stop:		6
# Short-Description:	Change alt modes on gpio to provide pi0 audio out
# Description:		Change alt modes on gpio to provide PWM audio on GPIO13 and 18.

do_start()	{
	/opt/system/gpio_alt -p 18 -f 5
	/opt/system/gpio_alt -p 13 -f 0
	exit 0
}

case "$1" in
	start|"")
		echo -n "switching gpio modes..."
		do_start
		echo "Done!"
	;;
	*)
		echo "Reboot to unset GPIO modes"
	;;
esac
