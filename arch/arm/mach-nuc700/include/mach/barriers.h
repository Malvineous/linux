/*
 * arch/arm/mach-nuc700/mach/include/barriers.h
 *
 * Copyright (C) 2011 Nuvoton Corporation
 * Wan ZongShun <mcuos.com@gmail.com>
 *
 * Copyright (C) 2013 Adam Nielsen <a.nielsen@shikadi.net>
 *
 * Barriers redefined for NUC700 ARM7 platforms with a strange cache
 * controller to work around hardware errata causing the outer_sync()
 * operation to deadlock the system, by Wan zongsun mark.
 *
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License version 2 as
 * published by the Free Software Foundation.
 */

#ifndef __ASM_ARCH_BARRIERS_H
#define __ASM_ARCH_BARRIERS_H

#ifdef CONFIG_ARCH_NUC700

#include <linux/linkage.h>
#include <mach/regs-cache.h>

#define mb()	flush_cache();
#define rmb()	do { flush_dcache(); barrier(); } while(0);
#define wmb()	do { flush_dcache(); barrier(); } while(0);

#endif /* CONFIG_ARCH_NUC700 */

#endif /* __ASM_ARCH_BARRIERS_H */
