/*
 * arch/arm/mach-nuc700/include/mach/irqs.h
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

#ifndef __ASM_ARCH_IRQS_H
#define __ASM_ARCH_IRQS_H

#include <mach/map.h>

/* Main CPU interrupts */

#define IRQ_WDT		NUC700_IRQ(1)

#define IRQ_EXTINT0	NUC700_IRQ(2)
#define IRQ_EXTINT1	NUC700_IRQ(3)
#define IRQ_EXTINT2	NUC700_IRQ(4)
#define IRQ_EXTINT3	NUC700_IRQ(5)

#define IRQ_ACTL	NUC700_IRQ(6)
#define IRQ_LCD		NUC700_IRQ(7)
#define IRQ_RTC		NUC700_IRQ(8)

#define IRQ_UART0	NUC700_IRQ(9)
#define IRQ_UART1	NUC700_IRQ(10)
#define IRQ_UART2	NUC700_IRQ(11)
#define IRQ_UART3	NUC700_IRQ(12)

#define IRQ_TIMER0	NUC700_IRQ(13)
#define IRQ_TIMER1	NUC700_IRQ(14)

#define IRQ_USBH0	NUC700_IRQ(15)
#define IRQ_USBH1	NUC700_IRQ(16)

#define IRQ_EMCTX	NUC700_IRQ(17)
#define IRQ_EMCRX	NUC700_IRQ(18)

#define IRQ_GDMA0	NUC700_IRQ(19)
#define IRQ_GDMA1	NUC700_IRQ(20)

#define IRQ_SD		NUC700_IRQ(21)
#define IRQ_USBD	NUC700_IRQ(22)
#define IRQ_SC0		NUC700_IRQ(23)
#define IRQ_SC1		NUC700_IRQ(24)

#define IRQ_I2C0	NUC700_IRQ(25)
#define IRQ_I2C1	NUC700_IRQ(26)

#define IRQ_SPI		NUC700_IRQ(27)
#define IRQ_PWM		NUC700_IRQ(28)
#define IRQ_KPI		NUC700_IRQ(29)
#define IRQ_PS2		NUC700_IRQ(30)
#define IRQ_IRQ45	NUC700_IRQ(31)
#define NR_IRQS		IRQ_IRQ45

#endif /* __ASM_ARCH_IRQS_H */
