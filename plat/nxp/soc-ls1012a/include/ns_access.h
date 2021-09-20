/*
 * Copyright (c) 2015, 2016 Freescale Semiconductor, Inc.
 * Copyright 2017-2018, 2021 NXP
 *
 * SPDX-License-Identifier: BSD-3-Clause
 */

#ifndef NS_ACCESS_H
#define NS_ACCESS_H

#include <csu.h>

enum csu_cslx_ind {
	CSU_CSLX_PCIE2_IO = 0,
	CSU_CSLX_PCIE1_IO,
	CSU_CSLX_MG2TPR_IP,
	CSU_CSLX_IFC_MEM,
	CSU_CSLX_OCRAM,
	CSU_CSLX_GIC,
	CSU_CSLX_PCIE1,
	CSU_CSLX_OCRAM2,
	CSU_CSLX_QSPI_MEM,
	CSU_CSLX_PCIE2,
	CSU_CSLX_SATA,
	CSU_CSLX_USB1,
	CSU_CSLX_QM_BM_SWPORTAL,
	CSU_CSLX_PCIE3 = 16,
	CSU_CSLX_PCIE3_IO,
	CSU_CSLX_USB3 = 20,
	CSU_CSLX_USB2,
	CSU_CSLX_PFE = 23,
	CSU_CSLX_SERDES = 32,
	CSU_CSLX_QDMA,
	CSU_CSLX_LPUART2,
	CSU_CSLX_LPUART1,
	CSU_CSLX_LPUART4,
	CSU_CSLX_LPUART3,
	CSU_CSLX_LPUART6,
	CSU_CSLX_LPUART5,
	CSU_CSLX_DSPI1 = 41,
	CSU_CSLX_QSPI,
	CSU_CSLX_ESDHC,
	CSU_CSLX_IFC = 45,
	CSU_CSLX_I2C1,
	CSU_CSLX_USB_2,
	CSU_CSLX_I2C3 = 48,
	CSU_CSLX_I2C2,
	CSU_CSLX_DUART2 = 50,
	CSU_CSLX_DUART1,
	CSU_CSLX_WDT2,
	CSU_CSLX_WDT1,
	CSU_CSLX_EDMA,
	CSU_CSLX_SYS_CNT,
	CSU_CSLX_DMA_MUX2,
	CSU_CSLX_DMA_MUX1,
	CSU_CSLX_DDR,
	CSU_CSLX_QUICC,
	CSU_CSLX_DCFG_CCU_RCPM = 60,
	CSU_CSLX_SECURE_BOOTROM,
	CSU_CSLX_SFP,
	CSU_CSLX_TMU,
	CSU_CSLX_SECURE_MONITOR,
	CSU_CSLX_SCFG,
	CSU_CSLX_FM = 66,
	CSU_CSLX_SEC5_5,
	CSU_CSLX_BM,
	CSU_CSLX_QM,
	CSU_CSLX_GPIO2 = 70,
	CSU_CSLX_GPIO1,
	CSU_CSLX_GPIO4,
	CSU_CSLX_GPIO3,
	CSU_CSLX_PLATFORM_CONT,
	CSU_CSLX_CSU,
	CSU_CSLX_IIC4 = 77,
	CSU_CSLX_WDT4,
	CSU_CSLX_WDT3,
	CSU_CSLX_ESDHC2 = 80,
	CSU_CSLX_WDT5 = 81,
	CSU_CSLX_SAI2,
	CSU_CSLX_SAI1,
	CSU_CSLX_SAI4,
	CSU_CSLX_SAI3,
	CSU_CSLX_FTM2 = 86,
	CSU_CSLX_FTM1,
	CSU_CSLX_FTM4,
	CSU_CSLX_FTM3,
	CSU_CSLX_FTM6 = 90,
	CSU_CSLX_FTM5,
	CSU_CSLX_FTM8,
	CSU_CSLX_FTM7,
	CSU_CSLX_DSCR = 121,
};

struct csu_ns_dev_st ns_dev[] = {
	 {CSU_CSLX_PCIE2_IO, CSU_ALL_RW},
	 {CSU_CSLX_PCIE1_IO, CSU_ALL_RW},
	 {CSU_CSLX_MG2TPR_IP, CSU_ALL_RW},
	 {CSU_CSLX_IFC_MEM, CSU_ALL_RW},
	 {CSU_CSLX_OCRAM, CSU_S_SUP_RW},
	 {CSU_CSLX_GIC, CSU_ALL_RW},
	 {CSU_CSLX_PCIE1, CSU_ALL_RW},
	 {CSU_CSLX_OCRAM2, CSU_S_SUP_RW},
	 {CSU_CSLX_QSPI_MEM, CSU_ALL_RW},
	 {CSU_CSLX_PCIE2, CSU_ALL_RW},
	 {CSU_CSLX_SATA, CSU_ALL_RW},
	 {CSU_CSLX_USB1, CSU_ALL_RW},
	 {CSU_CSLX_QM_BM_SWPORTAL, CSU_ALL_RW},
	 {CSU_CSLX_PCIE3, CSU_ALL_RW},
	 {CSU_CSLX_PCIE3_IO, CSU_ALL_RW},
	 {CSU_CSLX_USB3, CSU_ALL_RW},
	 {CSU_CSLX_USB2, CSU_ALL_RW},
	 {CSU_CSLX_PFE, CSU_ALL_RW},
	 {CSU_CSLX_SERDES, CSU_ALL_RW},
	 {CSU_CSLX_QDMA, CSU_ALL_RW},
	 {CSU_CSLX_LPUART2, CSU_ALL_RW},
	 {CSU_CSLX_LPUART1, CSU_ALL_RW},
	 {CSU_CSLX_LPUART4, CSU_ALL_RW},
	 {CSU_CSLX_LPUART3, CSU_ALL_RW},
	 {CSU_CSLX_LPUART6, CSU_ALL_RW},
	 {CSU_CSLX_LPUART5, CSU_ALL_RW},
	 {CSU_CSLX_DSPI1, CSU_ALL_RW},
	 {CSU_CSLX_QSPI, CSU_ALL_RW},
	 {CSU_CSLX_ESDHC, CSU_ALL_RW},
	 {CSU_CSLX_IFC, CSU_ALL_RW},
	 {CSU_CSLX_I2C1, CSU_ALL_RW},
	 {CSU_CSLX_USB_2, CSU_ALL_RW},
	 {CSU_CSLX_I2C3, CSU_ALL_RW},
	 {CSU_CSLX_I2C2, CSU_ALL_RW},
	 {CSU_CSLX_DUART2, CSU_ALL_RW},
	 {CSU_CSLX_DUART1, CSU_ALL_RW},
	 {CSU_CSLX_WDT2, CSU_ALL_RW},
	 {CSU_CSLX_WDT1, CSU_ALL_RW},
	 {CSU_CSLX_EDMA, CSU_ALL_RW},
	 {CSU_CSLX_SYS_CNT, CSU_ALL_RW},
	 {CSU_CSLX_DMA_MUX2, CSU_ALL_RW},
	 {CSU_CSLX_DMA_MUX1, CSU_ALL_RW},
	 {CSU_CSLX_DDR, CSU_ALL_RW},
	 {CSU_CSLX_QUICC, CSU_ALL_RW},
	 {CSU_CSLX_DCFG_CCU_RCPM, CSU_ALL_RW},
	 {CSU_CSLX_SECURE_BOOTROM, CSU_ALL_RW},
	 {CSU_CSLX_SFP, CSU_ALL_RW},
	 {CSU_CSLX_TMU, CSU_ALL_RW},
	 {CSU_CSLX_SECURE_MONITOR, CSU_ALL_RW},
	 {CSU_CSLX_SCFG, CSU_ALL_RW},
	 {CSU_CSLX_FM, CSU_ALL_RW},
	 {CSU_CSLX_SEC5_5, CSU_ALL_RW},
	 {CSU_CSLX_BM, CSU_ALL_RW},
	 {CSU_CSLX_QM, CSU_ALL_RW},
	 {CSU_CSLX_GPIO2, CSU_ALL_RW},
	 {CSU_CSLX_GPIO1, CSU_ALL_RW},
	 {CSU_CSLX_GPIO4, CSU_ALL_RW},
	 {CSU_CSLX_GPIO3, CSU_ALL_RW},
	 {CSU_CSLX_PLATFORM_CONT, CSU_ALL_RW},
	 {CSU_CSLX_CSU, CSU_ALL_RW},
	 {CSU_CSLX_IIC4, CSU_ALL_RW},
	 {CSU_CSLX_WDT4, CSU_ALL_RW},
	 {CSU_CSLX_WDT3, CSU_ALL_RW},
	 {CSU_CSLX_ESDHC2, CSU_ALL_RW},
	 {CSU_CSLX_WDT5, CSU_ALL_RW},
	 {CSU_CSLX_SAI2, CSU_ALL_RW},
	 {CSU_CSLX_SAI1, CSU_ALL_RW},
	 {CSU_CSLX_SAI4, CSU_ALL_RW},
	 {CSU_CSLX_SAI3, CSU_ALL_RW},
	 {CSU_CSLX_FTM2, CSU_ALL_RW},
	 {CSU_CSLX_FTM1, CSU_ALL_RW},
	 {CSU_CSLX_FTM4, CSU_ALL_RW},
	 {CSU_CSLX_FTM3, CSU_ALL_RW},
	 {CSU_CSLX_FTM6, CSU_ALL_RW},
	 {CSU_CSLX_FTM5, CSU_ALL_RW},
	 {CSU_CSLX_FTM8, CSU_ALL_RW},
	 {CSU_CSLX_FTM7, CSU_ALL_RW},
	 {CSU_CSLX_DSCR, CSU_ALL_RW},
};

#endif /* NS_ACCESS_H */
