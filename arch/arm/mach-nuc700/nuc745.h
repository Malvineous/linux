/*
 * arch/arm/mach-nuc700/nuc745.h
 *
 * Copyright (C) 2011 Nuvoton Corporation
 * Wan ZongShun <mcuos.com@gmail.com>
 *
 * Copyright (C) 2013 Adam Nielsen <a.nielsen@shikadi.net>
 *
 * NUC745 CPU support
 *
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License version 2 as
 * published by the Free Software Foundation.
 */

#include "cpu.h"

/* mach-nuc745evb.c */

extern void nuc700_init_irq(void);
extern struct sys_timer nuc700_timer;

/* nuc745.c */

extern void nuc745_read_id(void);
extern void nuc745_gpio_init(void);
extern void nuc745_init_clocks(void);
extern void nuc745_board_init(void);
