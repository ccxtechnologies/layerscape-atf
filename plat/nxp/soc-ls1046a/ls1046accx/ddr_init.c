/*
 * Copyright 2021 CCX Technologies
 *
 * SPDX-License-Identifier: BSD-3-Clause
 *
 * Charles Eidsness <charles@ccxtechnologies.com>
 */

#include <assert.h>
#include <errno.h>
#include <stdbool.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include <common/debug.h>
#include <ddr.h>
#include <errata.h>
#include <lib/utils.h>

#include "plat_common.h"
#include <platform_def.h>

const struct ddr_cfg_regs static_4g_2100 = {
	.cs[0].bnds = 0xFF,
	.cs[0].config = 0x80010322,
	.cs[0].config_2 = 0x00,
	.sdram_cfg[0] = 0x45208000,
	.sdram_cfg[1] = 0x00401070,
	.sdram_cfg[2] = 0x00,
	.timing_cfg[0] = 0xFA770018,
	.timing_cfg[1] = 0xE3EA9245,
	.timing_cfg[2] = 0x00595197,
	.timing_cfg[3] = 0x02101100,
	.timing_cfg[4] = 0x00220002,
	.timing_cfg[5] = 0x04401400,
	.timing_cfg[7] = 0x26640000,
	.timing_cfg[8] = 0x00446A00,
	.dq_map[0] = 0x32BB4458,
	.dq_map[1] = 0xD6336C2C,
	.dq_map[2] = 0x0E4D4C0C,
	.dq_map[3] = 0xB4000000,
	.sdram_mode[0] = 0x01010625,
	.sdram_mode[1] = 0x00100000,
	.sdram_mode[2] = 0x00,
	.sdram_mode[3] = 0x00,
	.sdram_mode[4] = 0x00,
	.sdram_mode[5] = 0x00,
	.sdram_mode[6] = 0x00,
	.sdram_mode[7] = 0x00,
	.sdram_mode[8] = 0x0701,
	.sdram_mode[9] = 0x08800000,
	.sdram_mode[10] = 0x00,
	.sdram_mode[11] = 0x00,
	.sdram_mode[12] = 0x00,
	.sdram_mode[13] = 0x00,
	.sdram_mode[14] = 0x00,
	.sdram_mode[15] = 0x00,
	.md_cntl = 0x00,
	.interval = 0x1FFE07FF,
	.zq_cntl = 0x8A090705,
	.clk_cntl = 0x02800000,
	.cdr[0] = 0x80080000,
	.cdr[1] = 0x80,
	.wrlvl_cntl[0] = 0x86550609,
	.wrlvl_cntl[1] = 0x0A0B0B0D,
	.wrlvl_cntl[2] = 0x0D0D0D0D,
	.err_disable = 0x0100,
	.err_int_en = 0x1D,
	.debug[28] = 0x4e,
};


long long board_static_ddr(struct ddr_info *priv)
{
	int ret;
	struct ddr4_spd spd;
	unsigned char mpart[20] = {0};

	ret = read_spd(NXP_SPD_EEPROM0, &spd, sizeof(spd));
	if (ret) {
		ERROR("Failed to read DIMM SPD, assuming 4G module.\n");
	} else {
		memcpy(mpart, &(spd.mpart), sizeof(mpart) - 1);
		NOTICE("RAM Part Number: %s\n", mpart);
		NOTICE("RAM Manufacturer Module ID: 0x%x%x\n", spd.mmid_msb, spd.mmid_lsb);
		NOTICE("RAM Manufacturer DRAM ID: 0x%x%x\n", spd.dmid_msb, spd.dmid_lsb);
	}

	memcpy(&priv->ddr_reg, &static_4g_2100, sizeof(struct ddr_cfg_regs));
	return 0x100000000UL;
}

long long init_ddr(void)
{
	int spd_addr[] = { NXP_SPD_EEPROM0 };
	struct ddr_info info;
	struct sysinfo sys;
	long long dram_size;

	zeromem(&sys, sizeof(sys));
	if (get_clocks(&sys)) {
		ERROR("System clocks are not set\n");
		assert(0);
	}
	debug("platform clock %lu\n", sys.freq_platform);
	debug("DDR PLL1 %lu\n", sys.freq_ddr_pll0);
	debug("DDR PLL2 %lu\n", sys.freq_ddr_pll1);

	zeromem(&info, sizeof(struct ddr_info));
	info.num_ctlrs = 1;
	info.dimm_on_ctlr = 1;
	info.clk = get_ddr_freq(&sys, 0);
	info.spd_addr = spd_addr;
	info.ddr[0] = (void *)NXP_DDR_ADDR;

	dram_size = dram_init(&info);

	if (dram_size < 0)
		ERROR("DDR init failed.\n");

	erratum_a008850_post();

	return dram_size;
}
