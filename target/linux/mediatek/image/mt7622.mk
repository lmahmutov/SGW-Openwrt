KERNEL_LOADADDR := 0x44080000


define Build/bl2
	cat $(STAGING_DIR_IMAGE)/mt7622-$1-bl2.img >> $@
endef

define Build/bl31-uboot
	cat $(STAGING_DIR_IMAGE)/mt7622_$1-u-boot.fip >> $@
endef

define Build/mt7622-gpt
	cp $@ $@.tmp 2>/dev/null || true
	ptgen -g -o $@.tmp -a 1 -l 1024 \
		$(if $(findstring sdmmc,$1), \
			-H \
			-t 0x83	-N bl2		-r	-p 512k@512k \
		) \
			-t 0xef	-N fip		-r	-p 2M@2M \
			-t 0x83	-N ubootenv	-r	-p 1M@4M \
				-N recovery	-r	-p 32M@6M \
		$(if $(findstring sdmmc,$1), \
				-N install	-r	-p 7M@38M \
			-t 0x2e -N production		-p 211M@45M \
		) \
		$(if $(findstring emmc,$1), \
			-t 0x2e -N production		-p 980M@40M \
		)
	cat $@.tmp >> $@
	rm $@.tmp
endef

define Build/trx-nand
	# kernel: always use 4 MiB (-28 B or TRX header) to allow upgrades even
	#	  if it grows up between releases
	# root: UBI with one extra block containing UBI mark to trigger erasing
	#	rest of partition
	$(STAGING_DIR_HOST)/bin/otrx create $@.new \
		-M 0x32504844 \
		-f $(IMAGE_KERNEL) -a 0x20000 -b 0x400000 \
		-f $@ \
		-A $(KDIR)/ubi_mark -a 0x20000
	mv $@.new $@
endef

define Device/bananapi_bpi-r64
  DEVICE_VENDOR := Bananapi
  DEVICE_MODEL := BPi-R64
  DEVICE_DTS := mt7622-bananapi-bpi-r64
  DEVICE_DTS_OVERLAY := mt7622-bananapi-bpi-r64-pcie1 mt7622-bananapi-bpi-r64-sata
  DEVICE_PACKAGES := kmod-ata-ahci-mtk kmod-btmtkuart kmod-usb3 e2fsprogs mkf2fs f2fsck
  ARTIFACTS := emmc-preloader.bin emmc-bl31-uboot.fip sdcard.img.gz snand-preloader.bin snand-bl31-uboot.fip
  IMAGES := sysupgrade.itb
  KERNEL_INITRAMFS_SUFFIX := -recovery.itb
  ARTIFACT/emmc-preloader.bin	:= bl2 emmc-2ddr
  ARTIFACT/emmc-bl31-uboot.fip	:= bl31-uboot bananapi_bpi-r64-emmc
  ARTIFACT/snand-preloader.bin	:= bl2 snand-2ddr
  ARTIFACT/snand-bl31-uboot.fip	:= bl31-uboot bananapi_bpi-r64-snand
  ARTIFACT/sdcard.img.gz	:= mt7622-gpt sdmmc |\
				   pad-to 512k | bl2 sdmmc-2ddr |\
				   pad-to 2048k | bl31-uboot bananapi_bpi-r64-sdmmc |\
				   pad-to 6144k | append-image-stage initramfs-recovery.itb |\
				   pad-to 38912k | mt7622-gpt emmc |\
				   pad-to 39424k | bl2 emmc-2ddr |\
				   pad-to 40960k | bl31-uboot bananapi_bpi-r64-emmc |\
				   pad-to 43008k | bl2 snand-2ddr |\
				   pad-to 43520k | bl31-uboot bananapi_bpi-r64-snand |\
				   pad-to 46080k | append-image squashfs-sysupgrade.itb | gzip
  KERNEL			:= kernel-bin | gzip
  KERNEL_INITRAMFS		:= kernel-bin | lzma | fit lzma $$(DTS_DIR)/$$(DEVICE_DTS).dtb with-initrd | pad-to 128k
  IMAGE/sysupgrade.itb		:= append-kernel | fit gzip $$(DTS_DIR)/$$(DEVICE_DTS).dtb external-static-with-rootfs | append-metadata
endef
TARGET_DEVICES += bananapi_bpi-r64

define Device/bpi_bananapi-r64-rootdisk
  DEVICE_VENDOR := Bpi
  DEVICE_MODEL := Banana Pi R64 (rootdisk)
  DEVICE_DTS := mt7622-bananapi-bpi-r64-rootdisk
  DEVICE_DTS_DIR := $(DTS_DIR)/mediatek
  SUPPORTED_DEVICES := bananapi,bpi-r64
  DEVICE_PACKAGES := kmod-usb-ohci kmod-usb2 kmod-usb3 kmod-ata-ahci-mtk
  IMAGES := sysupgrade-emmc.bin.gz
  IMAGE/sysupgrade-emmc.bin.gz := sysupgrade-emmc | gzip | append-metadata
endef
TARGET_DEVICES += bpi_bananapi-r64-rootdisk

define Device/elecom_wrc-2533gent
  DEVICE_VENDOR := Elecom
  DEVICE_MODEL := WRC-2533GENT
  DEVICE_DTS := mt7622-elecom-wrc-2533gent
  DEVICE_DTS_DIR := $(DTS_DIR)/mediatek
  DEVICE_PACKAGES := kmod-usb-ohci kmod-usb2 kmod-usb3 kmod-mt7615e \
	kmod-mt7615-firmware kmod-btmtkuart swconfig
endef
TARGET_DEVICES += elecom_wrc-2533gent

define Device/mediatek_mt7622-rfb1
  DEVICE_VENDOR := MediaTek
  DEVICE_MODEL := MTK7622 rfb1 AP
  DEVICE_DTS := mt7622-rfb1
  DEVICE_DTS_DIR := $(DTS_DIR)/mediatek
  DEVICE_PACKAGES := kmod-usb-ohci kmod-usb2 kmod-usb3 kmod-ata-ahci-mtk
endef
TARGET_DEVICES += mediatek_mt7622-rfb1

define Device/mediatek_mt7622-ubi
  DEVICE_VENDOR := MediaTek
  DEVICE_MODEL := MTK7622 AP (UBI)
  DEVICE_DTS := mt7622-rfb1-ubi
  DEVICE_DTS_DIR := $(DTS_DIR)/mediatek
  UBINIZE_OPTS := -E 5
  BLOCKSIZE := 128k
  PAGESIZE := 2048
  KERNEL_SIZE := 4194304
  IMAGE_SIZE := 32768k
  IMAGES += factory.bin
  IMAGE/factory.bin := append-kernel | pad-to $$(KERNEL_SIZE) | append-ubi | \
                check-size $$$$(IMAGE_SIZE)
  IMAGE/sysupgrade.bin := sysupgrade-tar
  DEVICE_PACKAGES := kmod-usb-ohci kmod-usb2 kmod-usb3 kmod-ata-ahci-mtk
endef
TARGET_DEVICES += mediatek_mt7622-ubi

define Device/ubnt_unifi-6-lr
  DEVICE_VENDOR := Ubiquiti
  DEVICE_MODEL := UniFi 6 LR
  DEVICE_DTS := mt7622-ubnt-unifi-6-lr
  DEVICE_DTS_DIR := $(DTS_DIR)/mediatek
  DEVICE_PACKAGES := kmod-mt7915e
endef
TARGET_DEVICES += ubnt_unifi-6-lr
