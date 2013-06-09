/*
 * linux/arch/arm/boot/compressed/head-nuc700.S
 *
 * Copyright (C) 2013 Adam Nielsen <a.nielsen@shikadi.net>
 *
 * Need to supply machine IDs.
 */

#include <linux/linkage.h>
#include <asm/mach-types.h>

		.section        ".start", "ax"

__nuc700_start:

		ldr	r7, .MACH_TYPE
		b	.NUC700END

.MACH_TYPE:

#ifdef CONFIG_CPU_NUC710
		.word	MACH_TYPE_NUC710EVB
#endif

#ifdef CONFIG_CPU_NUC740
		.word	MACH_TYPE_NUC740EVB
#endif

#ifdef CONFIG_CPU_NUC745
		.word	MACH_TYPE_NUC745EVB
#endif

.NUC700END:
