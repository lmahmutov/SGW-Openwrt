#
# This software is licensed under the Public Domain.
#

include $(TOPDIR)/rules.mk

PKG_NAME:=Z3GatewayHost
PKG_VERSION:=0.1
PKG_RELEASE:=1

PKG_MAINTAINER:=lmahmutov <lenz1986@gmail.com>
PKG_LICENSE:=MIT

include $(INCLUDE_DIR)/package.mk

define Package/Z3GatewayHost
	SECTION:=utils
	# Select package by default
	#DEFAULT:=y
	CATEGORY:=Utilities
	TITLE:=Z3GatewayHost.
        DEPENDS:=+libreadline \
		+libncurses
endef

define Package/Z3GatewayHost/description
	Z3GatewayHost.
endef

define Build/Prepare
	mkdir -p $(PKG_BUILD_DIR)
	$(CP) ./src/* $(PKG_BUILD_DIR)/
endef

define Package/Z3GatewayHost/install
	$(INSTALL_DIR) $(1)/usr/bin
	$(INSTALL_BIN) $(PKG_BUILD_DIR)/build/exe/Z3GatewayHost $(1)/usr/bin/
endef

$(eval $(call BuildPackage,Z3GatewayHost))
