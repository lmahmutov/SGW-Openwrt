#!/bin/sh
# Copyright (C) 2010-2013 OpenWrt.org

. /lib/functions/leds.sh
. /lib/nuc970.sh

get_status_led() {
	board=$(nuc970_board_name)

	case $board in

	NUC970-GateWay)
		status_led="nuc970:green:power"
		;;

	esac
}

set_state() {
	get_status_led $1

	case "$1" in
	preinit)
		status_led_blink_preinit
		;;
	failsafe)
		status_led_blink_failsafe
		;;
	upgrade | \
	preinit_regular)
		status_led_blink_preinit_regular
		;;
	done)
		status_led_on
		;;
	esac
}
