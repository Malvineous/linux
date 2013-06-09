/*
 * arch/arm/mach-nuc700/clock.h
 *
 * Copyright (C) 2008 Nuvoton Technology Corporation
 * Wan ZongShun <mcuos.com@gmail.com>
 *
 * Copyright (C) 2013 Adam Nielsen <a.nielsen@shikadi.net>
 *
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License version 2 as
 * published by the Free Software Foundation.
 */

#ifndef __ARCH_CLOCK_H
#define __ARCH_CLOCK_H

#include <linux/clkdev.h>

void nuc700_clk_enable(struct clk *clk, int enable);

struct clk {
	unsigned long cken;
	unsigned int enabled;
	void (*enable)(struct clk *, int enable);
};

#define DEFINE_CLK(_name, _ctrlbit)			\
struct clk clk_##_name = {				\
		.enable	= nuc700_clk_enable,		\
		.cken	= (1 << _ctrlbit),		\
	}

#define DEF_CLKLOOK(_clk, _devname, _conname)		\
	{						\
		.clk		= _clk,			\
		.dev_id		= _devname,		\
		.con_id		= _conname,		\
	}

#endif /*  __ARCH_CLOCK_H */
