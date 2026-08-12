/*
 * Copyright 2021-2022 CCX Technologies
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
	.cs[0].bnds     = 0x000000FF,
	.cs[0].config   = 0x80010322,
	.cs[0].config_2 = 0x00000000,
	.sdram_cfg[0]   = 0x45208000,
	.sdram_cfg[1]   = 0x00401070,
	.sdram_cfg[2]   = 0x00000000,
	.timing_cfg[0]  = 0xFA770018,
	.timing_cfg[1]  = 0xE2EA9235,
	.timing_cfg[2]  = 0x00595197,
	.timing_cfg[3]  = 0x02101100,
	.timing_cfg[4]  = 0x00220002,
	.timing_cfg[5]  = 0x04401400,
	.timing_cfg[6]  = 0x00000000,
	.timing_cfg[7]  = 0x26640000,
	.timing_cfg[8]  = 0x00446A00,
	.dq_map[0]      = 0x32BB4458,
	.dq_map[1]      = 0xD6336C2C,
	.dq_map[2]      = 0x0E4D4C0C,
	.dq_map[3]      = 0xB4000000,
	.sdram_mode[0]  = 0x01010625,
	.sdram_mode[1]  = 0x00100000,
	.sdram_mode[2]  = 0x00000000,
	.sdram_mode[3]  = 0x00000000,
	.sdram_mode[4]  = 0x00000000,
	.sdram_mode[5]  = 0x00000000,
	.sdram_mode[6]  = 0x00000000,
	.sdram_mode[7]  = 0x00000000,
	.sdram_mode[8]  = 0x00000701,
	.sdram_mode[9]  = 0x08800000,
	.sdram_mode[10] = 0x00000000,
	.sdram_mode[11] = 0x00000000,
	.sdram_mode[12] = 0x00000000,
	.sdram_mode[13] = 0x00000000,
	.sdram_mode[14] = 0x00000000,
	.sdram_mode[15] = 0x00000000,
	.md_cntl        = 0x00000000,
	.interval       = 0x1FFE07FF,
	.zq_cntl        = 0x8A090705,
	.clk_cntl       = 0x02400000,
	.cdr[0]         = 0x80080000,
	.cdr[1]         = 0x00000080,
	.wrlvl_cntl[0]  = 0x86550608,
	.wrlvl_cntl[1]  = 0x08090A0B,
	.wrlvl_cntl[2]  = 0x0B0B0B0C,
	.err_disable    = 0x00000100,
	.err_int_en     = 0x0000001D,
	.debug[28]      = 0x0000004e,
};

const struct ddr_cfg_regs static_8g_2666 = {
	.cs[0].bnds     = 0x000001FF,
	.cs[0].config   = 0x80010422,
	.cs[0].config_2 = 0x00000000,
	.sdram_cfg[0]   = 0x45208000,
	.sdram_cfg[1]   = 0x00401070,
	.sdram_cfg[2]   = 0x00000000,
	.timing_cfg[0]  = 0xFA770018,
	.timing_cfg[1]  = 0xE2EA8235,
	.timing_cfg[2]  = 0x00595197,
	.timing_cfg[3]  = 0x02161100,
	.timing_cfg[4]  = 0x00220002,
	.timing_cfg[5]  = 0x04401400,
	.timing_cfg[6]  = 0x00000000,
	.timing_cfg[7]  = 0x26640000,
	.timing_cfg[8]  = 0x00446A00,
	.dq_map[0]      = 0x32BB4458,
	.dq_map[1]      = 0xD6336C2C,
	.dq_map[2]      = 0x0E4D4C0C,
	.dq_map[3]      = 0xB4000000,
	.sdram_mode[0]  = 0x01010625,
	.sdram_mode[1]  = 0x00100000,
	.sdram_mode[2]  = 0x00000000,
	.sdram_mode[3]  = 0x00000000,
	.sdram_mode[4]  = 0x00000000,
	.sdram_mode[5]  = 0x00000000,
	.sdram_mode[6]  = 0x00000000,
	.sdram_mode[7]  = 0x00000000,
	.sdram_mode[8]  = 0x00000701,
	.sdram_mode[9]  = 0x08800000,
	.sdram_mode[10] = 0x00000000,
	.sdram_mode[11] = 0x00000000,
	.sdram_mode[12] = 0x00000000,
	.sdram_mode[13] = 0x00000000,
	.sdram_mode[14] = 0x00000000,
	.sdram_mode[15] = 0x00000000,
	.md_cntl        = 0x00000000,
	.interval       = 0x1FFE07FF,
	.zq_cntl        = 0x8A090705,
	.clk_cntl       = 0x02400000,
	.cdr[0]         = 0x80080000,
	.cdr[1]         = 0x00000080,
	.wrlvl_cntl[0]  = 0x86550608,
	.wrlvl_cntl[1]  = 0x08090A0B,
	.wrlvl_cntl[2]  = 0x0B0C0C0C,
	.err_disable    = 0x00000100,
	.err_int_en     = 0x0000001D,
	.debug[28]      = 0x0000004e,
};

const struct ddr_cfg_regs static_8g_3200 = {
    .cs[0].bnds     = 0x000001FF,
    .cs[0].config   = 0x80010422,
    .cs[0].config_2 = 0x00000000,
    .sdram_cfg[0]   = 0x45208000,
    .sdram_cfg[1]   = 0x00401070,
    .sdram_cfg[2]   = 0x00000000,
    .timing_cfg[0]  = 0xFA770018,
    .timing_cfg[1]  = 0xE2EA8235,
    .timing_cfg[2]  = 0x00595197,
    .timing_cfg[3]  = 0x02161100,
    .timing_cfg[4]  = 0x00220002,
    .timing_cfg[5]  = 0x04401400,
    .timing_cfg[6]  = 0x00000000,
    .timing_cfg[7]  = 0x26640000,
    .timing_cfg[8]  = 0x00446A00,
    .dq_map[0]      = 0xB16B44B0,
    .dq_map[1]      = 0x5AD0EB54,
    .dq_map[2]      = 0x12DB0CB4,
    .dq_map[3]      = 0x0C000000,
    .sdram_mode[0]  = 0x01010625,
    .sdram_mode[1]  = 0x00100000,
    .sdram_mode[2]  = 0x00000000,
    .sdram_mode[3]  = 0x00000000,
    .sdram_mode[4]  = 0x00000000,
    .sdram_mode[5]  = 0x00000000,
    .sdram_mode[6]  = 0x00000000,
    .sdram_mode[7]  = 0x00000000,
    .sdram_mode[8]  = 0x00000701,
    .sdram_mode[9]  = 0x08800000,
    .sdram_mode[10] = 0x00000000,
    .sdram_mode[11] = 0x00000000,
    .sdram_mode[12] = 0x00000000,
    .sdram_mode[13] = 0x00000000,
    .sdram_mode[14] = 0x00000000,
    .sdram_mode[15] = 0x00000000,
    .md_cntl        = 0x00000000,
    .interval       = 0x1FFE07FF,
    .zq_cntl        = 0x8A090705,
    .clk_cntl       = 0x02400000,
    .cdr[0]         = 0x80080000,
    .cdr[1]         = 0x00000080,
    .wrlvl_cntl[0]  = 0x86550608,
    .wrlvl_cntl[1]  = 0x090A0A0C,
    .wrlvl_cntl[2]  = 0x0C0C0C0C,
    .err_disable    = 0x00000100,
    .err_int_en     = 0x0000001D,
    .debug[28]      = 0x0000004e,
};


enum ram_type {
    RAM_TYPE_4G_2100 = 0,
    RAM_TYPE_8G_2666,
    RAM_TYPE_8G_3200
};

long long board_static_ddr(struct ddr_info *priv)
{
	int ret; 
	enum ram_type type;
	struct ddr4_spd spd;
	unsigned char mpart[20] = {0};

	ret = read_spd(NXP_SPD_EEPROM0, &spd, sizeof(spd));
	if (ret) {
		ERROR("Failed to read DIMM SPD, assuming 4G module.\n");
		type = RAM_TYPE_4G_2100;
	} else {
		memcpy(mpart, &(spd.mpart), sizeof(mpart) - 1);
		NOTICE("RAM Part Number: %s\n", mpart);
		NOTICE("RAM Density: 0x%x\n", spd.density_banks);
		NOTICE("RAM Addressing: 0x%x\n", spd.addressing);
		NOTICE("RAM tCK min: 0x%x\n", spd.tck_min);

		if ((spd.density_banks == 0x85) && (spd.addressing == 0x21)) {
            switch (spd.tck_min) {
            case 0x6:
                type = RAM_TYPE_8G_2666;
                break;
            case 0x5:
                type = RAM_TYPE_8G_3200;
                break;
            default:
                type = RAM_TYPE_4G_2100;
                break;
            }
        } else {
            type = RAM_TYPE_4G_2100;
        }
	}

	switch (type) {
    case RAM_TYPE_8G_2666:
        NOTICE("RAM Type: 8GB DDR4-2666\n");
        memcpy(&priv->ddr_reg, &static_8g_2666, sizeof(struct ddr_cfg_regs));
        return 0x200000000UL;

    case RAM_TYPE_8G_3200:
        NOTICE("RAM Type: 8GB DDR4-3200\n");
        memcpy(&priv->ddr_reg, &static_8g_3200, sizeof(struct ddr_cfg_regs));
        return 0x200000000UL;

    case RAM_TYPE_4G_2100:
    default:
        NOTICE("RAM Type: 4GB DDR4-2100\n");
        memcpy(&priv->ddr_reg, &static_4g_2100, sizeof(struct ddr_cfg_regs));
        return 0x100000000UL;
    }
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
