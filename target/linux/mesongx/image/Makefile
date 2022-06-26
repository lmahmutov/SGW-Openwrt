#
# Copyright (C) 2017-2018 Stijn Tintel <stijn@linux-ipv6.be>
#
# This is free software, licensed under the GNU General Public License v2.
# See /LICENSE for more information.
#
include $(TOPDIR)/rules.mk
include $(INCLUDE_DIR)/image.mk

FAT32_BLOCK_SIZE=1024
FAT32_BLOCKS=$(shell echo $$(($(CONFIG_MESONGX_SD_BOOT_PARTSIZE)*1024*1024/$(FAT32_BLOCK_SIZE))))

define Build/bootloader-ntv-s905x
	fip_create \
		--bl30  $(STAGING_DIR_IMAGE)/odroidc2/bl30.bin \
		--bl301 $(STAGING_DIR_IMAGE)/odroidc2/bl301.bin \
		--bl31  $(STAGING_DIR_IMAGE)/odroidc2/bl31.bin \
		--bl33  $(BIN_DIR)/u-boot-odroid-c2/u-boot.bin \
		$(BIN_DIR)/u-boot-odroid-c2/fip.bin

	cat $(STAGING_DIR_IMAGE)/odroidc2/bl2.package $(BIN_DIR)/u-boot-odroid-c2/fip.bin > $(BIN_DIR)/u-boot-odroid-c2/boot_new.bin

	amlbootsig $(BIN_DIR)/u-boot-odroid-c2/boot_new.bin $(BIN_DIR)/u-boot-odroid-c2/u-boot.bin.signed

	dd if=$(BIN_DIR)/u-boot-odroid-c2/u-boot.bin.signed of=$(BIN_DIR)/u-boot-odroid-c2/u-boot.gxbb bs=512 skip=96
	dd if=$(STAGING_DIR_IMAGE)/odroidc2/bl1.bin.hardkernel of=$@ conv=fsync,notrunc bs=1 count=440
	dd if=$(STAGING_DIR_IMAGE)/odroidc2/bl1.bin.hardkernel of=$@ conv=fsync,notrunc bs=512 skip=1 seek=1
	dd if=$(BIN_DIR)/u-boot-odroid-c2/u-boot.gxbb of=$@ conv=fsync,notrunc bs=512 seek=97
endef

define Build/sdcard-img
	$(INSTALL_DIR) $(KDIR)/boot.ext4
	$(CP) $(KDIR)/boot.$1.scr $(KDIR)/boot.ext4/boot.scr
	$(CP) $(KDIR_KERNEL_IMAGE) $(KDIR)/boot.ext4/uImage
	$(foreach dts,$(DEVICE_DTS),$(CP) $(DTS_DIR)/$(dts).dtb $(KDIR)/boot.ext4/)
	PADDING="$(CONFIG_TARGET_IMAGES_PAD)" \
	PATH="$(TARGET_PATH)" \
	$(SCRIPT_DIR)/gen_image_generic.sh $@ \
		$(CONFIG_TARGET_KERNEL_PARTSIZE) $(KDIR)/boot.ext4 \
		$(CONFIG_TARGET_ROOTFS_PARTSIZE) $(IMAGE_ROOTFS) \
		4096
endef

define Build/uImage-meson
	$(call Build/uImage,none)
	mkimage -A arm64 -T script -C none -n "boot.scr uImage" -d boot.$1.txt $(KDIR)/boot.$1.scr
endef

define Build/mesongx-sdcard
	rm -f $@.boot
	mkfs.fat $@.boot -C $(FAT32_BLOCKS)

	mcopy -i $@.boot $(KDIR)/aml_autoscript ::aml_autoscript
	mcopy -i $@.boot $(KDIR)/image-meson-gxl-s905x-uhd300x.dtb ::dtb
	mcopy -i $@.boot $(IMAGE_KERNEL) ::uImage
	./gen_mesongx_sdcard_img.sh $@ \
		$@.boot \
		$(IMAGE_ROOTFS) \
		$(CONFIG_MESONGX_SD_BOOT_PARTSIZE) \
		$(CONFIG_TARGET_ROOTFS_PARTSIZE)
	rm -f $@.boot
endef

define Build/aml_autoscript
	$(call Build/uImage,none)
	mkimage -A arm64 -O linux -T script -C none -n "Amlogic OpenWrt loader" -d boot.$1.txt $(KDIR)/aml_autoscript
endef


### Devices ###
define Device/Default
  CONSOLE := ttyAML0,115200
  FILESYSTEMS := ext4 squashfs
  #IMAGES := sdcard.img
  #IMAGE/sdcard.img := sdcard-img $$(DEVICE_NAME) | bootloader-$$(DEVICE_NAME)
  KERNEL_DEPENDS = $$(wildcard $(DTS_DIR)/$$(DEVICE_DTS).dts)
  KERNEL_LOADADDR := 0x01080000
  KERNEL_NAME := Image
  PROFILES = Default $$(DEVICE_NAME)
endef

define Device/ntv-s905x
  DEVICE_DTS := amlogic/meson-gxl-s905x-uhd300x
  DEVICE_PACKAGES += odroid-firmware-c2 u-boot-odroid-c2
  DEVICE_TITLE := NTV+ S905X
  IMAGES := sdcard.img.gz
  IMAGE/sdcard.img.gz := mesongx-sdcard | append-metadata | gzip
  KERNEL := kernel-bin | aml_autoscript $$(DEVICE_NAME)
endef
TARGET_DEVICES += ntv-s905x

$(eval $(call BuildImage))