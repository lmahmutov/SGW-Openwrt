include $(TOPDIR)/rules.mk

PKG_NAME:=rtl8723bu
PKG_RELEASE=2

PKG_LICENSE:=GPLv2
PKG_LICENSE_FILES:=

PKG_SOURCE_URL:=https://github.com/lwfinger/rtl8723bu.git
PKG_MIRROR_HASH:=5670c468867fcc31222607302ccda067c6de39d2097ed3c58e75f6b359a8a5b2
PKG_SOURCE_PROTO:=git
PKG_SOURCE_DATE:=2021-11-04
PKG_SOURCE_VERSION:=d34603a39a7c925d810fe17c6e8dea5063d43a33

PKG_MAINTAINER:=Lenar Mahmutov <lenz1986@gmail.com>
PKG_BUILD_PARALLEL:=1

STAMP_CONFIGURED_DEPENDS := $(STAGING_DIR)/usr/include/mac80211-backport/backport/autoconf.h

include $(INCLUDE_DIR)/kernel.mk
include $(INCLUDE_DIR)/package.mk

define KernelPackage/rtl8723bu
  SUBMENU:=Wireless Drivers
  TITLE:=Realtek RTL8723BU USB WiFi-BT support (out-of-tree)
  DEPENDS:=+kmod-mac80211 +kmod-cfg80211 +@DRIVER_11N_SUPPORT
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

NOSTDINC_FLAGS += -DCONFIG_IOCTL_CFG80211 -DRTW_USE_CFG80211_STA_EVENT

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
