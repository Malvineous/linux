/*
 * arch/arm/mach-nuc700/include/mach/entry-macro.S
 *
 * Low-level IRQ helper macros for NUC700-based platforms.
 *
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License version 2 as
 * published by the Free Software Foundation.
 */

#include <mach/regs-irq.h>

	.macro  get_irqnr_preamble, base, tmp
	.endm

	.macro	get_irqnr_and_base, irqnr, irqstat, base, tmp

		ldr	\base, =AIC_BA

		ldr	\irqnr, [\base, #AIC_IPER]
		ldr	\irqnr, [\base, #AIC_ISNR]
		cmp	\irqnr, #0

	.endm
