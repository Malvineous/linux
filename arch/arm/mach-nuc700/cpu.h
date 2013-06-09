/*
 * arch/arm/mach-nuc700/cpu.h
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

#ifndef __ARCH_MACH_CPU_H
#define __ARCH_MACH_CPU_H

#include <mach/map.h>

#define NUC700_8250PORT(name) { \
	.membase	= NUC_IOMEM(name##_PA), \
	.mapbase	= name##_PA, \
	.irq		= IRQ_##name, \
	.uartclk	= 11313600, \
	.regshift	= 2, \
	.iotype		= UPIO_MEM, \
	.flags		= UPF_BOOT_AUTOCONF | UPF_SKIP_TEST, \
}

/* CPU identifier register */
#define REG_NUC700_PDID	NUC_IOMEM(NUC700_PA_GCR)
#define NUC710_CPUID	0x0710
#define NUC740_CPUID	0x0740
#define NUC745_CPUID	0x0745

extern void nuc700_init_clocks(void);
extern void nuc700_read_id(void);
extern void nuc700_board_init(void);
extern void nuc700_uart_clk_enable(int uart_num);

/* for either public between 710 and 745, or between 745 and 740 */
extern struct platform_device nuc700_serial_device;
extern struct platform_device nuc700_device_fmi;
extern struct platform_device nuc700_device_rtc;

#endif /* __ARCH_MACH_CPU_H */
