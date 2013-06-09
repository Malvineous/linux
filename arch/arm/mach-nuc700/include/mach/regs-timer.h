/*
 * arch/arm/mach-nuc700/include/mach/regs-timer.h
 *
 * Copyright (c) 2011 Nuvoton technology corporation
 * All rights reserved.
 * Wan ZongShun <mcuos.com@gmail.com>
 *
 * Copyright (C) 2013 Adam Nielsen <a.nielsen@shikadi.net>
 *
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 2 of the License, or
 * (at your option) any later version.
 */

#ifndef __ASM_ARCH_REGS_TIMER_H
#define __ASM_ARCH_REGS_TIMER_H

#include <mach/map.h>

/* Timer Registers */

#define REG_TCSR0	NUC_IOMEM(TMR_BA + 0x00)
#define REG_TCSR1	NUC_IOMEM(TMR_BA + 0x04)
#define REG_TICR0	NUC_IOMEM(TMR_BA + 0x08)
#define REG_TICR1	NUC_IOMEM(TMR_BA + 0x0C)
#define REG_TDR0	NUC_IOMEM(TMR_BA + 0x10)
#define REG_TDR1	NUC_IOMEM(TMR_BA + 0x14)
#define REG_TISR	NUC_IOMEM(TMR_BA + 0x18)
#define REG_WTCR	NUC_IOMEM(TMR_BA + 0x1C)

#endif /*  __ASM_ARCH_REGS_TIMER_H */
