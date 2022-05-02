#
# This software is licensed under the Public Domain.
#

include $(TOPDIR)/rules.mk

PKG_NAME:=InfoNes
PKG_VERSION:=1.0.0
PKG_RELEASE:=$(AUTORELEASE)

PKG_MAINTAINER:=Lenar Mahmutov <lenz1986@gmail.com>
PKG_LICENSE:=CC0-1.0

include $(INCLUDE_DIR)/package.mk

define Package/InfoNes
	CATEGORY:=Game
	TITLE:=InfoNes.
	DEPENDS:= +alsa-lib +libpthread +libstdcpp +zlib
	URL:=https://www.infones.com
endef

define Package/InfoNes/description
	InfoNes demo.
endef

define Build/Prepare
	mkdir -p $(PKG_BUILD_DIR)
	$(CP) ./src/* $(PKG_BUILD_DIR)/
endef

define Package/InfoNes/install
	$(INSTALL_DIR) $(1)/usr/bin
	$(INSTALL_BIN) $(PKG_BUILD_DIR)/InfoNES $(1)/usr/bin/
endef

$(eval $(call BuildPackage,InfoNes))
