/*
 * linux/arch/arm/mach-nuc700/irq.c
 *
 * based on linux/arch/arm/plat-s3c24xx/irq.c by Ben Dooks
 *
 * Copyright (C) 2008 Nuvoton Technology Corporation
 * All rights reserved.
 * Wan ZongShun <mcuos.com@gmail.com>
 *
 * Copyright (C) 2013 Adam Nielsen <a.nielsen@shikadi.net>
 *
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License version 2 as
 * published by the Free Software Foundation.
 */

#include <linux/io.h>
#include <asm/irq.h>
#include <asm/mach/irq.h>
#include <mach/regs-irq.h>

/* CPU IRQ mode and priority */
#define NUC700_IRQM_LOWLEVEL  0
#define NUC700_IRQM_HIGHLEVEL 1
#define NUC700_IRQM_NEGDE     2
#define NUC700_IRQM_PEGDE     3

int nuc700_set_aic_scr(unsigned int mode, unsigned int priority,
	unsigned int irqnum)
{
	if ((priority < 0) || (priority > 7) || (irqnum <= 0)) {
		return -1;
	}

	__raw_writel(mode << 6 | priority, REG_AIC_SCR + (irqnum << 2));
	return 0;
}

static void nuc700_irq_mask(struct irq_data *d)
{
	__raw_writel(1 << d->irq, REG_AIC_MDCR);
}

/*
 * By the w90p910 spec,any irq,only write 1
 * to REG_AIC_EOSCR for ACK
 */
static void nuc700_irq_ack(struct irq_data *d)
{
	__raw_writel(0x01, REG_AIC_EOSCR);
}

static void nuc700_irq_unmask(struct irq_data *d)
{
	__raw_writel(1 << d->irq, REG_AIC_MECR);
}

static struct irq_chip nuc700_irq_chip = {
	.irq_ack	= nuc700_irq_ack,
	.irq_mask	= nuc700_irq_mask,
	.irq_unmask	= nuc700_irq_unmask,
};

void __init nuc700_init_irq(void)
{
	int irqno;

	__raw_writel(0x7FFFE, REG_AIC_MDCR);

	for (irqno = IRQ_WDT; irqno < NR_IRQS; irqno++) {
		irq_set_chip_and_handler(irqno, &nuc700_irq_chip,
			handle_level_irq);
		set_irq_flags(irqno, IRQF_VALID);
	}

	nuc700_set_aic_scr(NUC700_IRQM_HIGHLEVEL, 1, IRQ_TIMER0);
	nuc700_set_aic_scr(NUC700_IRQM_HIGHLEVEL, 1, IRQ_UART0);
}
