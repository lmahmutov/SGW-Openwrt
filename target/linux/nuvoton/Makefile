#
# Copyright (C) 2008-2011 OpenWrt.org
#
# This is free software, licensed under the GNU General Public License v2.
# See /LICENSE for more information.
#
include $(TOPDIR)/rules.mk

ARCH:=arm
BOARD:=nuvoton
BOARDNAME:=Nuvoton ARM9
SUBTARGETS:=nuc970
FEATURES:=squashfs nand targz usb usbgadget ubifs gpio
MAINTAINER:=lmahmutov telegramm @lmahmutov

KERNEL_PATCHVER:=5.4

define Target/Description
	Nuvoton ARM9 Target.
endef

include $(INCLUDE_DIR)/target.mk

KERNELNAME:=uImage dtbs

DEFAULT_PACKAGES += \
	kmod-leds-gpio wpad-mini kmod-gpio-button-hotplug

$(eval $(call BuildTarget))
