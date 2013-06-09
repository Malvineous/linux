/*
 * arch/arm/mach-nuc700/include/mach/regs-i2c.h
 *
 * Copyright (C) 2011 Nuvoton Technology Corporation
 * Wan ZongShun <mcuos.com@gmail.com>
 *
 * Copyright (C) 2013 Adam Nielsen <a.nielsen@shikadi.net>
 *
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License version 2 as
 * published by the Free Software Foundation.
 */

#ifndef __ASM_ARCH_REGS_I2C_H
#define __ASM_ARCH_REGS_I2C_H

#include <mach/map.h>

/* I2C Control Registers */
#define I2C1_BA			NUC_IOMEM(I2C_BA + 0x100)

/* I2C-0 */
#define REG_I2CCSR		NUC_IOMEM(I2C_BA + 0x00)
#define REG_I2CDIVIDER		NUC_IOMEM(I2C_BA + 0x04)
#define REG_I2CCMDR		NUC_IOMEM(I2C_BA + 0x08)
#define REG_I2CSWR		NUC_IOMEM(I2C_BA + 0x0C)
#define REG_I2CRXR		NUC_IOMEM(I2C_BA + 0x10)
#define REG_I2CTXR		NUC_IOMEM(I2C_BA + 0x14)

/* I2C-1 */
#define REG_I2CCSR1		NUC_IOMEM(I2C1_BA + 0x00)
#define REG_I2CDIVIDER1		NUC_IOMEM(I2C1_BA + 0x04)
#define REG_I2CCMDR1		NUC_IOMEM(I2C1_BA + 0x08)
#define REG_I2CSWR1		NUC_IOMEM(I2C1_BA + 0x0C)
#define REG_I2CRXR1		NUC_IOMEM(I2C1_BA + 0x10)
#define REG_I2CTXR1		NUC_IOMEM(I2C1_BA + 0x14)

#endif /*  __ASM_ARCH_REGS_I2C_H */
