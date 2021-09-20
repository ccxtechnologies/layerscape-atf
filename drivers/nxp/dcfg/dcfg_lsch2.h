/*
 * Copyright 2018-2020 NXP
 *
 * SPDX-License-Identifier: BSD-3-Clause
 *
 */

#ifndef DCFG_LSCH2_H
#define DCFG_LSCH2_H

/* dcfg block register offsets and bitfields */
#define DCFG_PORSR1_OFFSET		0x00
#define DCFG_DEVDISR1_OFFSET		0x070
#define DCFG_DEVDISR2_OFFSET		0x074
#define DCFG_DEVDISR3_OFFSET		0x078
#define DCFG_DEVDISR4_OFFSET		0x07C
#define DCFG_DEVDISR5_OFFSET		0x080
#define DCFG_COREDISR_OFFSET		0x094
#define RCWSR0_OFFSET			0x100
#define RCWSR5_OFFSET			0x118
#define DCFG_BOOTLOCPTRL_OFFSET		0x400
#define DCFG_BOOTLOCPTRH_OFFSET		0x404
#define DCFG_COREDISABLEDSR_OFFSET	0x990
#define DCFG_SCRATCH4_OFFSET		0x20C
#define DCFG_SVR_OFFSET			0x0A4
#define DCFG_BRR_OFFSET			0x0E4

#define DCFG_RSTCR_OFFSET		0x0B0
#define RSTCR_RESET_REQ			0x2

#define DCFG_RSTRQSR1_OFFSET		0x0C8
#define DCFG_RSTRQMR1_OFFSET		0x0C0

/* PORSR1 bit mask */
#define PORSR1_RCW_MASK			0xff800000
#define PORSR1_RCW_SHIFT		23

/* DCFG DCSR Macros */
#define DCFG_DCSR_PORCR1_OFFSET		0x0

#define SVR_MFR_ID_MASK			0xF0000000
#define SVR_MFR_ID_SHIFT		28
#define SVR_DEV_ID_MASK			0xFFF0000
#define SVR_DEV_ID_SHIFT		16
#define SVR_PERSONALITY_MASK		0xFF00
#define SVR_PERSONALITY_SHIFT		8
#define SVR_SEC_MASK			0x100
#define SVR_SEC_SHIFT			8
#define SVR_MAJ_REV_MASK		0xF0
#define SVR_MAJ_REV_SHIFT		4
#define SVR_MIN_REV_MASK		0xF
#define SVR_MINOR_REV_0			0x00
#define SVR_MINOR_REV_1			0x01

#define DISR5_DDRC1_MASK		0x1
#define DISR5_OCRAM_MASK		0x40

/* DCFG regsiters bit masks */
#define RCWSR0_SYS_PLL_RAT_SHIFT	25
#define RCWSR0_SYS_PLL_RAT_MASK		0x1f
#define RCWSR0_MEM_PLL_RAT_SHIFT	16
#define RCWSR0_MEM_PLL_RAT_MASK		0x3f
#define RCWSR0_MEM2_PLL_RAT_SHIFT	18
#define RCWSR0_MEM2_PLL_RAT_MASK	0x3f

#define RCWSR_SB_EN_OFFSET		RCWSR5_OFFSET
#define RCWSR_SBEN_MASK			0x1
#define RCWSR_SBEN_SHIFT		21

/* RCW SRC NAND */
#define RCW_SRC_NAND_MASK		(0x100)
#define RCW_SRC_NAND_VAL		(0x100)
#define NAND_RESERVED_MASK		(0xFC)
#define NAND_RESERVED_1			(0x0)
#define NAND_RESERVED_2			(0x80)

/* RCW SRC NOR */
#define RCW_SRC_NOR_MASK		(0x1F0)
#define NOR_8B_VAL			(0x10)
#define NOR_16B_VAL			(0x20)
#define SD_VAL				(0x40)
#define QSPI_VAL1			(0x44)
#define QSPI_VAL2			(0x45)

#endif /*	DCFG_LSCH2_H	*/