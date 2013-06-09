/*
 * arch/arm/mach-nuc700/mach-nuc745evb.c
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

#include <linux/console.h>
#include <linux/platform_device.h>
#include <linux/serial_8250.h>

#include <asm/mach/arch.h>
#include <asm/mach/map.h>
#include <asm/mach-types.h>
#include <mach/map.h>
#include <mach/mfp-nuc745.h>
#include <mach/regs-serial.h>

#include "time.h"
#include "nuc745.h"

static unsigned long nuc745_multi_pin_config[] __initdata = {

	/* enable ethernet */
	GPIO20_PHYRXERR,
	GPIO21_PHYCRSDV,
	GPIO22_PHYRXD0,
	GPIO23_PHYRXD1,
	GPIO24_PHYREFCLK,
	GPIO25_PHYTXEN,
	GPIO26_PHYTXD0,
	GPIO27_PHYTXD1,
	GPIO28_PHYMDIO,
	GPIO29_PHYMDC,
#ifdef CONFIG_NUC700_UART1
	GPIO7_TXD1,
	GPIO8_RXD1,
#endif

#ifdef CONFIG_NUC700_UART2
	GPIO9_TXD2,
	GPIO10_RXD2,
#endif

#ifdef CONFIG_NUC700_UART1_CTSRTS
	GPIO9_CTS1,
	GPIO10_RTS1,
#endif

#ifdef CONFIG_NUC700_UART3
	GPIO1_UART_DTR3,
	GPIO2_UART_DSR3,
	GPIO3_UART_TXD3,
	GPIO4_UART_RXD3,
#endif

};

/* Initial serial platform data */
struct plat_serial8250_port nuc745_uart_data[] = {
	NUC700_8250PORT(UART0),
#ifdef CONFIG_NUC700_UART1
	NUC700_8250PORT(UART1),
#endif
#ifdef CONFIG_NUC700_UART2
	NUC700_8250PORT(UART2),
#endif
#ifdef CONFIG_NUC700_UART3
	NUC700_8250PORT(UART3),
#endif
	{},
};

void __init nuc745_uart_clk_enable(void) {

#ifdef CONFIG_NUC700_UART1
	nuc700_uart_clk_enable(1);
#endif
#ifdef CONFIG_NUC700_UART2
	nuc700_uart_clk_enable(2);
#endif
#ifdef CONFIG_NUC700_UART3
	nuc700_uart_clk_enable(3);
#endif

}

static void __init nuc745evb_init_board(void)
{
	platform_device_register_resndata(NULL, "serial8250", PLAT8250_DEV_PLATFORM,
				NULL, 0, nuc745_uart_data, sizeof(nuc745_uart_data));

	nuc745_uart_clk_enable();
	nuc745_board_init();
}

static int __init nuc745evb_console_init(void)
{
	if (!machine_is_nuc745evb())
		return 0;

	return add_preferred_console("ttyS", 0, "115200");
}
console_initcall(nuc745evb_console_init);

static void __init nuc745evb_init(void)
{
	nuc745_read_id();
	nuc745_init_clocks();
	nuc745_gpio_init();
	nuc700_mfp_config(ARRAY_AND_SIZE(nuc745_multi_pin_config));
}

MACHINE_START(NUC745EVB, "NUC745EVB")
	/* Maintainer: Wan ZongShun */
	.init_irq	= nuc700_init_irq,
	.init_machine	= nuc745evb_init_board,
	.init_early	= nuc745evb_init,
	.init_time	= nuc700_timer_init,
MACHINE_END
