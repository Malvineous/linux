/*
 * arch/arm/mach-nuc700/include/mach/regs-irq.h
 *
 * Copyright (C) 2008 Nuvoton Technology Corporation
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

#ifndef __ASM_ARCH_REGS_IRQ_H
#define __ASM_ARCH_REGS_IRQ_H

#include <mach/map.h>

/* Advanced Interrupt Controller (AIC) Registers */
#define REG_AIC_SCR		NUC_IOMEM(AIC_BA + 0x000)
#define REG_AIC_IRSR		NUC_IOMEM(AIC_BA + 0x100)
#define REG_AIC_IASR		NUC_IOMEM(AIC_BA + 0x104)
#define REG_AIC_ISR		NUC_IOMEM(AIC_BA + 0x108)
#define REG_AIC_IPER		NUC_IOMEM(AIC_BA + 0x10C)
#define REG_AIC_ISNR		NUC_IOMEM(AIC_BA + 0x110)
#define REG_AIC_IMR		NUC_IOMEM(AIC_BA + 0x114)
#define REG_AIC_OISR		NUC_IOMEM(AIC_BA + 0x118)
#define REG_AIC_MECR		NUC_IOMEM(AIC_BA + 0x120)
#define REG_AIC_MDCR		NUC_IOMEM(AIC_BA + 0x124)
#define REG_AIC_SSCR		NUC_IOMEM(AIC_BA + 0x128)
#define REG_AIC_SCCR		NUC_IOMEM(AIC_BA + 0x12C)
#define REG_AIC_EOSCR		NUC_IOMEM(AIC_BA + 0x130)
#define AIC_IPER		(0x10C)
#define AIC_ISNR		(0x110)

/* Bits 16-18 in REG_AIC_GEN define IRQ 2-4 group */

#define TIMER2_IRQ		(1 << 16)
#define TIMER3_IRQ		(1 << 17)
#define TIMER4_IRQ		(1 << 18)
#define TIME_GROUP_IRQ		(TIMER2_IRQ|TIMER3_IRQ|TIMER4_IRQ)

#endif /* __ASM_ARCH_REGS_IRQ_H */
