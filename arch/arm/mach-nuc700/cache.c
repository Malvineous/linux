/*
 * arch/arm/mach-nuc700/cache.c
 *
 * Copyright (C) 2008 Nuvoton Technology Corporation
 * Wan ZongShun <mcuos.com@gmail.com>
 *
 * Copyright (C) 2013 Adam Nielsen <a.nielsen@shikadi.net>
 *
 * Internal cache control for NUC700.
 *
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License version 2 as
 * published by the Free Software Foundation.
 */

#include <linux/kernel.h>
#include <linux/io.h>
#include <mach/regs-cache.h>

#ifdef CONFIG_CACHE_NUC700

asmlinkage void open_cache(void)
{
	__raw_writel(__raw_readl(REG_CAHCNF) | ICAEN | DCAEN | WRBEN,
		REG_CAHCNF);
}

asmlinkage void close_cache(void)
{
	__raw_writel(__raw_readl(REG_CAHCNF) & (~(ICAEN | DCAEN | WRBEN)),
		REG_CAHCNF);
}

asmlinkage void flush_cache(void)
{
	__raw_writel(__raw_readl(REG_CAHCON) | ICAH | DCAH | DRWB | FLHA,
		REG_CAHCON);
	while (__raw_readl(REG_CAHCON) != 0);
}

asmlinkage void flush_icache(void)
{
	__raw_writel(__raw_readl(REG_CAHCON) | ICAH | FLHA, REG_CAHCON);
	while (__raw_readl(REG_CAHCON) != 0);
}

asmlinkage void flush_dcache(void)
{
	__raw_writel(__raw_readl(REG_CAHCON) | DRWB | DCAH | FLHA, REG_CAHCON);
	while (__raw_readl(REG_CAHCON) != 0);
}

#else /* CONFIG_CACHE_NUC700 undefined */

asmlinkage void open_cache(void)
{
}

asmlinkage void close_cache(void)
{
}

asmlinkage void flush_cache(void)
{
}

asmlinkage void flush_icache(void)
{
}

asmlinkage void flush_dcache(void)
{
}

#endif /* CONFIG_CACHE_NUC700 */
