#
# NUC970 Profiles
#

define Device/nuc970
  DEVICE_DTS:= nuc970-gateway
  DTS := nuc970-gateway
  DEVICE_TITLE := nuc970
  DEVICE_PACKAGES := kmod-usb2 kmod-usb-ohci
  DEVICE_NAME := nuc970
  DEVICE_PROFILE := nuc970
#  IMAGES := root.ubifs
#  IMAGES += sysupgrade.bin
  PAGESIZE := 2048
  BLOCKSIZE := 128k
  MKUBIFS_OPTS := -m $$(PAGESIZE) -e 124KiB
  DEVICE_DTS_DIR := ../dts
  KERNEL_DEPENDS := $$(wildcard ../dts/$$(DTS).dts)
#  KERNEL += kernel-bin | patch-dtb | none | uImage
#  KERNEL += kernel-bin | patch-dtb | none | uImage
#  KERNEL_NAME := zImage
  FILESYSTEMS += ubifs
endef
TARGET_DEVICES += nuc970


