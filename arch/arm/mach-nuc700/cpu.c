/*
 * arch/arm/mach-nuc700/cpu.c
 *
 * Copyright (C) 2009 Nuvoton Technology Corporation
 * Wan ZongShun <mcuos.com@gmail.com>
 *
 * Copyright (C) 2013 Adam Nielsen <a.nielsen@shikadi.net>
 *
 * NUC700 series CPU common support
 *
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License version 2 as
 * published by the Free Software Foundation.
 */

#include <linux/io.h>
#include <linux/clk.h>
#include <mach/regs-serial.h>
#include <mach/regs-gpio.h>

#include "cpu.h"
#include "clock.h"

/* Initial clock declarations */
static DEFINE_CLK(uart0,   5);
static DEFINE_CLK(timer,   6);
static DEFINE_CLK(ohci,    7);
static DEFINE_CLK(wdt,     8);
static DEFINE_CLK(emc,    10);
static DEFINE_CLK(lcd,    11);
static DEFINE_CLK(sd,     12);
static DEFINE_CLK(gdma,   13);
static DEFINE_CLK(usbd,   14);
static DEFINE_CLK(usbcks, 15);
static DEFINE_CLK(ac97,   16);
static DEFINE_CLK(pwm,    17);
static DEFINE_CLK(rtc,    18);
static DEFINE_CLK(i2c0,   19);
static DEFINE_CLK(i2c1,   20);
static DEFINE_CLK(uart1,  21);
static DEFINE_CLK(uart2,  22);
static DEFINE_CLK(uart3,  23);
static DEFINE_CLK(usi,    24);
static DEFINE_CLK(sch0,   25);
static DEFINE_CLK(sch1,   26);
static DEFINE_CLK(kpi,    27);
static DEFINE_CLK(ps2,    28);
static DEFINE_CLK(ext,     0);

static struct clk_lookup nuc700_clkregs[] = {
	DEF_CLKLOOK(&clk_uart0,  NULL, "uart0"),
	DEF_CLKLOOK(&clk_timer,  NULL, "timer"),
	DEF_CLKLOOK(&clk_ohci,   "nuc700-ohci", NULL),
	DEF_CLKLOOK(&clk_wdt,    "nuc700-wdt", NULL),
	DEF_CLKLOOK(&clk_emc,    "nuc900-emc", NULL),
	DEF_CLKLOOK(&clk_lcd,    "nuc700-lcd", NULL),
	DEF_CLKLOOK(&clk_sd,     "nuc700-sd", NULL),
	DEF_CLKLOOK(&clk_gdma,   "nuc700-gdma", NULL),
	DEF_CLKLOOK(&clk_usbd,   "nuc700-usbd", NULL),
	DEF_CLKLOOK(&clk_usbcks, "nuc700-usbcks", NULL),
	DEF_CLKLOOK(&clk_rtc,    "nuc700-rtc", NULL),
	DEF_CLKLOOK(&clk_i2c0,   "nuc700-i2c-p0", NULL),
	DEF_CLKLOOK(&clk_i2c1,   "nuc700-i2c-p1", NULL),
	DEF_CLKLOOK(&clk_uart1,  NULL, "uart1"),
	DEF_CLKLOOK(&clk_uart2,  NULL, "uart2"),
	DEF_CLKLOOK(&clk_uart3,  NULL, "uart3"),
	DEF_CLKLOOK(&clk_usi,    "nuc900-spi", NULL),
	DEF_CLKLOOK(&clk_sch0,   "nuc700-sch0", NULL),
	DEF_CLKLOOK(&clk_sch1,   "nuc700-sch1", NULL),
	DEF_CLKLOOK(&clk_kpi,    "nuc700-kpi", NULL),
	DEF_CLKLOOK(&clk_ac97,   "nuc900-ac97", NULL),
	DEF_CLKLOOK(&clk_pwm,    "nuc700-pwm", NULL),
	DEF_CLKLOOK(&clk_ps2,    "nuc700-ps2", NULL),
	DEF_CLKLOOK(&clk_ext,    NULL, "ext"),
};

void __init nuc700_read_id(void)
{
	unsigned long idcode;

	idcode = __raw_readl(REG_NUC700_PDID) & 0x0FFF;

	printk(KERN_INFO "CPU type 0x%08lx is ", idcode);

	switch (idcode) {
	case NUC710_CPUID:
		printk("NUC710\n");
		break;
	case NUC740_CPUID:
		printk("NUC740\n");
		break;
	case NUC745_CPUID:
		printk("NUC745\n");
		break;
	default:
		printk("unknown!\n");
		break;
	}
}

void __init nuc700_init_clocks(void)
{
	clkdev_add_table(nuc700_clkregs, ARRAY_SIZE(nuc700_clkregs));
}

void __init nuc700_gpio_init(struct nuc700_gpio_chip *gpio_chip, int num)
{
	nuc700_init_gpio_port(gpio_chip, num);
}

void __init nuc700_uart_clk_enable(int uart_num)
{
	char *name;
	struct clk *ck_uart;

	switch (uart_num & 0x03) {
	case 0x00:
		printk(KERN_WARNING "NUC700 UART0 has been initialized in bootloader!\n");
		return;
	case 0x01:
		name = "uart1";
		break;
	case 0x02:
		name = "uart2";
		break;
	case 0x03:
		name = "uart3";
		break;
	/* No other cases possible */
	}

	ck_uart = clk_get(NULL, name);
	if (IS_ERR(ck_uart)) {
		printk(KERN_WARNING "NUC700 UART%d get clock failed!\n", uart_num);
	} else {
		clk_enable(ck_uart);
	}
}
