/*
 * linux/arch/arm/plat-nuvoton/wbl.h
 *
 * Winbond/Nuvoton bootloader support
 *
 * Copyright (C) 2013 Adam Nielsen <a.nielsen@shikadi.net>
 *
 * This program is free software; you can redistribute it and/or
 * modify it under the terms of the GNU General Public License as
 * published by the Free Software Foundation; version 2 of the License.
 */

/* Address of the Winbond bootloader's information structure */
#define WBL_BOOTLOADER_INFO_ADDR 0x7F010000

/* Get the MAC address for the first network device */
int wbl_get_mac_address(u8 *mac);
