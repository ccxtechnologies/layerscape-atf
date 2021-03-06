#
# Copyright 2018, 2020-2021 NXP
#
# SPDX-License-Identifier: BSD-3-Clause
#
# Platform Errata Build flags.
# These should be enabled by the platform if the erratum workaround needs to be
# applied.

ERRATA := \
  ERRATA_SOC_A008850 \
  ERRATA_SOC_A009660 \
  ERRATA_SOC_A010539 \
  ERRATA_SOC_A050426

define add_errata_define
  $(1) ?= 0
  ifeq ($$($(1)),1)
    SOC_ERRATA_SOURCES := yes
    $$(eval $$(call add_define,$(1)))
  endif
endef

$(foreach e,$(ERRATA),$(eval $(call add_errata_define,$(e))))

BL2_SOURCES += $(PLAT_COMMON_PATH)/soc_errata/errata.c
