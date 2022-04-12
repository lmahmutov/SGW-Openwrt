#!/bin/sh
#
# Copyright (C) 2014 OpenWrt.org
#

NUC970_BOARD_NAME=
NUC970_MODEL=

nuc970_board_detect() {

	local machine
	local name

	machine=$(cat /proc/device-tree/model)
	#machine=$(awk 'BEGIN{FS="[ \t]+:[ \t]"} /Hardware/ {print $2}' /proc/cpuinfo)

	case "$machine" in
	*"NUC970 GateWay"*)
		name="NUC970-GateWay"
		;;
	esac

	[ -z "$name" ] && name="unknown"

	[ -z "$NUC970_BOARD_NAME" ] && NUC970_BOARD_NAME="$name"
	[ -z "$NUC970_MODEL" ] && NUC970_MODEL="$machine"

	[ -e "/tmp/sysinfo/" ] || mkdir -p "/tmp/sysinfo/"

	echo "$NUC970_BOARD_NAME" > /tmp/sysinfo/board_name
	echo "$NUC970_MODEL" > /tmp/sysinfo/model
}

nuc970_board_name() {
	local name

	[ -f /tmp/sysinfo/board_name ] && name=$(cat /tmp/sysinfo/board_name)
	[ -n "$name" ] || name="unknown"

	echo "$name"
}
