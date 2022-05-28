include $(TOPDIR)/rules.mk

PKG_NAME:=rtl8723bu
PKG_RELEASE=2

PKG_LICENSE:=GPLv2
PKG_LICENSE_FILES:=

PKG_SOURCE_URL:=https://github.com/lwfinger/rtl8723bu.git
PKG_MIRROR_HASH:=6faaa2f0ad088873cbcb8bd39b99851720380d7940b87ec1002aa62c60e69cb2
PKG_SOURCE_PROTO:=git
PKG_SOURCE_DATE:=2022-05-21
PKG_SOURCE_VERSION:=ff22a9fc

PKG_MAINTAINER:=Lenar Mahmutov <lenz1986@gmail.com>
PKG_BUILD_PARALLEL:=1

STAMP_CONFIGURED_DEPENDS := $(STAGING_DIR)/usr/include/mac80211-backport/backport/autoconf.h

include $(INCLUDE_DIR)/kernel.mk
include $(INCLUDE_DIR)/package.mk

define KernelPackage/rtl8723bu
  SUBMENU:=Wireless Drivers
  TITLE:=Realtek RTL8723BU USB WiFi-BT support (out-of-tree)
  DEPENDS:=+kmod-mac80211 +kmod-cfg80211 +@DRIVER_11N_SUPPORT +libstdcpp +kmod-usb-core
  FILES:=\
	$(PKG_BUILD_DIR)/rtl8723bu.ko
  AUTOLOAD:=$(call AutoProbe,rtl8723bu)
  PROVIDES:=kmod-rtl8723bu
endef

NOSTDINC_FLAGS := \
	$(KERNEL_NOSTDINC_FLAGS) \
	-I$(PKG_BUILD_DIR) \
	-I$(PKG_BUILD_DIR)/include \
	-I$(STAGING_DIR)/usr/include/mac80211-backport \
	-I$(STAGING_DIR)/usr/include/mac80211-backport/uapi \
	-I$(STAGING_DIR)/usr/include/mac80211 \
	-I$(STAGING_DIR)/usr/include/mac80211/uapi \
	-include backport/backport.h

NOSTDINC_FLAGS += -DCONFIG_IOCTL_CFG80211 -DRTW_USE_CFG80211_STA_EVENT -DCONFIG_CONCURRENT_MODE -DBUILD_OPENWRT

define Build/Compile
	rm -f $(PKG_BUILD_DIR)/include/linux/wireless.h
	+$(MAKE) $(PKG_JOBS) -C "$(LINUX_DIR)" \
		$(KERNEL_MAKE_FLAGS) \
		M="$(PKG_BUILD_DIR)" \
		NOSTDINC_FLAGS="$(NOSTDINC_FLAGS)" \
		CONFIG_RTL8723BU=m \
		USER_MODULE_NAME=rtl8723bu \
		modules
endef

$(eval $(call KernelPackage,rtl8723bu))