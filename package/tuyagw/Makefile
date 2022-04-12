#
# This software is licensed under the Public Domain.
#

include $(TOPDIR)/rules.mk

PKG_NAME:=tuyagw
PKG_VERSION:=0.1
PKG_RELEASE:=1

PKG_MAINTAINER:=lmahmutov <lenz1986@gmail.com>
PKG_LICENSE:=MIT

include $(INCLUDE_DIR)/package.mk

define Package/tuyagw
	SECTION:=utils
	# Select package by default
	#DEFAULT:=y
	CATEGORY:=Utilities
	TITLE:=tuyagw.
        #DEPENDS:=+libreadline \
		+libncurses
endef

define Package/tuyagw/description
	tuyagw.
endef

define Build/Prepare
	mkdir -p $(PKG_BUILD_DIR)
	$(CP) ./src/* $(PKG_BUILD_DIR)/
endef

define Package/tuyagw/install
	$(INSTALL_DIR) $(1)/usr/bin
	$(INSTALL_BIN) $(PKG_BUILD_DIR)/build/exe/tuyagw$(1)/usr/bin/
endef

$(eval $(call BuildPackage,tuyagw))
