#
# Copyright (C) 2009 OpenWrt.org
#

SUBTARGET:=nuc970
BOARDNAME:=nuc970 based boards
FEATURES+=usb
CPU_TYPE:=arm926ej-s

DEFAULT_PACKAGES +=
KERNELNAME:=Image dtbs uImage

define Target/Description
	nuc970 target
endef
