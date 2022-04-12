#
# Copyright (C) 2016 Ben Whitten <ben.whitten@gmail.com>
#
# This is free software, licensed under the GNU General Public License v2.
# See /LICENSE for more information.
#

include $(TOPDIR)/rules.mk

PKG_VERSION:=NUC970_U-Boot_v2016.11
PKG_RELEASE:=1

PKG_SOURCE_PROTO:=git
PKG_SOURCE_URL:=https://github.com/OpenNuvoton/NUC970_U-Boot_v2016.11.git
PKG_MIRROR_HASH:=4f106d215c01c4d024c4612bbd3ef189188d19abc1ab2cc316b257d308534feb
PKG_SOURCE_VERSION:=ca47203cd21107174ee2d16a68b394e0f99516bd

include $(INCLUDE_DIR)/u-boot.mk
include $(INCLUDE_DIR)/package.mk
include $(INCLUDE_DIR)/kernel.mk

define U-Boot/Default
  BUILD_TARGET:=nuc970
  UBOOT_IMAGE:=u-boot.bin
endef

define U-Boot/nuc970
  NAME:=nuc970
  BUILD_SUBTARGET:=nuc970
  BUILD_DEVICES:=nuc970
endef

UBOOT_TARGETS := nuc970	

define Build/Compile
	+$(MAKE) $(PKG_JOBS) -C $(PKG_BUILD_DIR) \
		CROSS_COMPILE=$(TARGET_CROSS) \
		DTC=$(PKG_BUILD_DIR)/scripts/dtc/dtc \
		KCFLAGS="$(filter-out -fstack-protector \
		-mfloat-abi=hard, $(TARGET_CFLAGS)) -mfloat-abi=soft"
endef

$(eval $(call BuildPackage/U-Boot))
