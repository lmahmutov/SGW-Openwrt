# Copyright (C) 2022 @lmahmutov
#
#
# This is free software, licensed under the GNU General Public License v2.
# See /LICENSE for more information.
#

include $(TOPDIR)/rules.mk

PKG_NAME:=lvgl
PKG_VERSION:=1.0.0
PKG_RELEASE:=$(AUTORELEASE)

PKG_MAINTAINER:=Lenar Mahmutov <lenz1986@gmail.com>
PKG_LICENSE:=CC0-1.0

PKG_BUILD_DIR:=$(BUILD_DIR)/$(PKG_NAME)-$(PKG_VERSION)

include $(INCLUDE_DIR)/package.mk

# application package
define Package/lvgl
	CATEGORY:=LVGL
	TITLE:=A template for LittleV Graphics Library
endef

define Package/lvgl/description
A template for LittleV Graphics Library
endef

define Build/Prepare
	mkdir -p $(PKG_BUILD_DIR)
	$(CP) ./src/* $(PKG_BUILD_DIR)/
endef

#TARGET_CFLAGS += -I$(STAGING_DIR)/usr/include
#TARGET_LDFLAGS += -L$(STAGING_DIR)/usr/lib

#define Build/Compile
#	$(MAKE) -C $(PKG_BUILD_DIR)/ \
#	CC="$(TARGET_CC)" \
#	CFLAGS="$(TARGET_CFLAGS)" \
#	LDFLAGS="$(TARGET_LDFLAGS)"
#endef

define Package/lvgl/install
	$(CP) ./files/* $(1)/
	$(INSTALL_DIR) $(1)/usr/bin
	# install the binary
	$(INSTALL_BIN) $(PKG_BUILD_DIR)/lv_bin $(1)/usr/bin/lvgl
endef

$(eval $(call BuildPackage,$(PKG_NAME)))
