/*
 * arch/arm/mach-nuc700/include/mach/regs-gcr.h
 *
 * Copyright (C) 2010 Nuvoton Technology Corporation
 * All rights reserved.
 * Wan ZongShun <mcuos.com@gmail.com>
 *
 * Copyright (C) 2013 Adam Nielsen <a.nielsen@shikadi.net>
 *
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 2 of the License, or
 * (at your option) any later version.
 *
 */

#ifndef __ASM_ARCH_REGS_GCR_H
#define __ASM_ARCH_REGS_GCR_H

#include <mach/map.h>

/* Global control registers */

#define REG_PDID	NUC_IOMEM(GCR_BA)
#define REG_ARBCON	NUC_IOMEM(GCR_BA + 0x04)
#define REG_PLLCON0	NUC_IOMEM(GCR_BA + 0x08)
#define REG_CLKSEL	NUC_IOMEM(GCR_BA + 0x0c)
#define REG_PLLCON1	NUC_IOMEM(GCR_BA + 0x10)
#define REG_I2SCKCON	NUC_IOMEM(GCR_BA + 0x14)
#define REG_IRQWAKECON	NUC_IOMEM(GCR_BA + 0x20)
#define REG_IRQWAKEFLG	NUC_IOMEM(GCR_BA + 0x24)
#define REG_PMCON	NUC_IOMEM(GCR_BA + 0x28)
#define REG_USBTXCON	NUC_IOMEM(GCR_BA + 0x30)

#endif /*  __ASM_ARCH_REGS_GCR_H */
