#
# Copyright (C) 2017-2018 Stijn Tintel <stijn@linux-ipv6.be>
#
# This is free software, licensed under the GNU General Public License v2.
# See /LICENSE for more information.
#

include $(TOPDIR)/rules.mk
include $(INCLUDE_DIR)/kernel.mk

PKG_VERSION:=2018.09
PKG_RELEASE:=1

PKG_HASH:=839bf23cfe8ce613a77e583a60375179d0ad324e92c82fbdd07bebf0fd142268

include $(INCLUDE_DIR)/u-boot.mk
include $(INCLUDE_DIR)/package.mk

define U-Boot/Default
  ARCH:=arm
  BUILD_TARGET:=mesongx
  HIDDEN:=1
endef

define U-Boot/odroid-c2
  TITLE:=ODROID C2
  BUILD_DEVICES:=odroid-c2
endef

UBOOT_TARGETS:= \
	odroid-c2

$(eval $(call BuildPackage/U-Boot))