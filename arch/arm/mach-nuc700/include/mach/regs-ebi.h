/*
 * arch/arm/mach-nuc700/include/mach/regs-ebi.h
 *
 * Copyright (C) 2009 Nuvoton Technology Corporation
 * Wan ZongShun <mcuos.com@gmail.com>
 *
 * Copyright (C) 2013 Adam Nielsen <a.nielsen@shikadi.net>
 *
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation;version 2 of the License.
 *
 */

#ifndef __ASM_ARCH_REGS_EBI_H
#define __ASM_ARCH_REGS_EBI_H

#include <mach/map.h>

/* EBI Control Registers */

#define REG_EBICON	NUC_IOMEM(EBI_BA + 0x0000)
#define REG_ROMCON	NUC_IOMEM(EBI_BA + 0x0004)
#define REG_SDRAMBANK	NUC_IOMEM(EBI_BA + 0x0008)
#define REG_EXTIO	NUC_IOMEM(EBI_BA + 0x0018)

#endif /* __ASM_ARCH_REGS_EBI_H */
