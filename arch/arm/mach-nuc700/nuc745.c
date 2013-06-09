/*
 * arch/arm/mach-nuc700/nuc745.c
 *
 * Copyright (C) 2011 Nuvoton Corporation
 * Wan ZongShun <mcuos.com@gmail.com>
 *
 * NUC745 CPU support
 *
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License version 2 as
 * published by the Free Software Foundation.
 */

#include <mach/regs-gpio.h>
#include "cpu.h"

/* NUC745 GPIO group */
static struct nuc700_gpio_chip nuc745_gpio[] = {
	NUC700_GPIO_CHIP("PORT0", 0, 5, 0),
	NUC700_GPIO_CHIP("PORT1", 18, 2, 0),
	NUC700_GPIO_CHIP("PORT2", 20, 10, 0),
	NUC700_GPIO_CHIP("PORT3", 0, 0, 1),
	NUC700_GPIO_CHIP("PORT4", 30, 1, 0),
	NUC700_GPIO_CHIP("PORT5", 5, 13, 0),
	NUC700_GPIO_CHIP("PORT6", 0, 0, 1),
};

void __init nuc745_read_id(void)
{
	nuc700_read_id();
}

void __init nuc745_gpio_init(void)
{
	nuc700_gpio_init(nuc745_gpio, ARRAY_SIZE(nuc745_gpio));
}

void __init nuc745_init_clocks(void)
{
	nuc700_init_clocks();
}

void __init nuc745_board_init(void)
{
	nuc700_board_init();
}
