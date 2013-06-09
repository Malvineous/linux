/*
 * arch/arm/mach-nuc700/time.c
 *
 * Copyright (C) 2011 Nuvoton Technology Corporation
 * Wan ZongShun <mcuos.com@gmail.com>
 *
 * Copyright (C) 2013 Adam Nielsen <a.nielsen@shikadi.net>
 *
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 2 of the License, or
 * (at your option) any later version.
 */

#include <linux/interrupt.h>
#include <linux/clk.h>
#include <linux/io.h>
#include <asm/mach/irq.h>
#include <asm/mach/time.h>
#include <mach/regs-timer.h>
#include "time.h"

#define RESETINT	0x01
#define PERIOD		(0x01 << 27)
#define ONESHOT		(0x00 << 27)
#define COUNTEN		(0x01 << 30)
#define INTEN		(0x01 << 29)

#define TICKS_PER_SEC	CONFIG_HZ
#define PRESCALE	0x63 /* Divider = prescale + 1 */

/* IRQ handler for the timer */
static irqreturn_t nuc700_timer_interrupt(int irq, void *dev_id)
{
	timer_tick();
	__raw_writel(0x01, REG_TISR); /* clear TIF0 */
	return IRQ_HANDLED;
}

static struct irqaction nuc700_timer_irq = {
	.name		= "NUC700 Timer Tick",
	.flags		= IRQF_DISABLED | IRQF_TIMER | IRQF_IRQPOLL,
	.handler	= nuc700_timer_interrupt,
};

static void __init nuc700_timer_setup(void)
{
	unsigned int timer0_load;

	struct clk *ck_ext = clk_get(NULL, "ext");
	struct clk *ck_timer = clk_get(NULL, "timer");
	unsigned int rate, val = 0;

	BUG_ON(IS_ERR(ck_ext) || IS_ERR(ck_timer));

	clk_enable(ck_timer);
	rate = clk_get_rate(ck_ext);
	clk_put(ck_ext);
	rate = rate / (PRESCALE + 0x01);

	/* Set a known state */
	__raw_writel(0x00, REG_TCSR0);
	__raw_writel(RESETINT, REG_TISR);

	timer0_load = (rate / TICKS_PER_SEC);
	__raw_writel(timer0_load, REG_TICR0);

	val |= (PERIOD | COUNTEN | INTEN | PRESCALE);;
	__raw_writel(val, REG_TCSR0);

}

void __init nuc700_timer_init(void)
{
	nuc700_timer_setup();
	setup_irq(IRQ_TIMER0, &nuc700_timer_irq);
}
