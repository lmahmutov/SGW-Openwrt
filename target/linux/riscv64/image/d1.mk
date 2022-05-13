# SPDX-License-Identifier: GPL-2.0-only
#
# Copyright (C) 2013-2016 OpenWrt.org
# Copyright (C) 2022 @lmahmutov

define Device/lichee_rv_86
  DEVICE_VENDOR := Lichee
  DEVICE_MODEL := RV86 Panel
  SOC := sun20iw1p1
endef
TARGET_DEVICES += lichee_rv_86

