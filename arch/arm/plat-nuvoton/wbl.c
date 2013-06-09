/*
 * linux/arch/arm/plat-nuvoton/wbl.c
 *
 * Winbond/Nuvoton bootloader support
 *
 * Copyright (C) 2013 Adam Nielsen <a.nielsen@shikadi.net>
 *
 * This program is free software; you can redistribute it and/or
 * modify it under the terms of the GNU General Public License as
 * published by the Free Software Foundation; version 2 of the License.
 */

#define pr_fmt(fmt) "nuvoton_wbl: " fmt

#include <linux/init.h>
#include <linux/export.h>
#include <linux/kernel.h>
#include <linux/if_ether.h>

#include <linux/mtd/physmap.h>
#include <linux/mtd/mtd.h>
#include <linux/mtd/partitions.h>

#include <plat/wbl.h>

/* bootloader info block layout */
struct wbl_config {
	u32 len;
	u32 type;
	u8 eth0_mac[ETH_ALEN];
	u32 eth0_ip;
	u16 eth0_ip_pad;
	u8 eth1_mac[ETH_ALEN];
	u32 eth1_ip;
	u16 eth1_ip_pad;
	u32 use_cache;
	u32 use_dhcp;
	u32 tftp_iface;
	u32 phy_id;
	u32 buf_base;
	u32 buf_size;
	u32 baudrate;
	u32 rmii;
	u32 serial_num;
	u32 usb;
};

/* Values for wbl_config.type */
#define WBL_CONFIG_TYPE_BOOTLOADER_INFO  1

/* Minimum value for wbl_config.len for the data to be considered valid */
#define WBL_CONFIG_MIN_LENGTH sizeof(struct wbl_config)

/* Address in memory of bootloader info block */
#define WBL_BOOTLOADER_INFO_ADDR 0x7F010000

static struct wbl_config *config = (struct wbl_config *)WBL_BOOTLOADER_INFO_ADDR;

static int wbl_config_is_valid(void)
{
	if (config->type != WBL_CONFIG_TYPE_BOOTLOADER_INFO) {
		pr_err("invalid config signature byte\n");
		return 1;
	}
	if (config->len < WBL_CONFIG_MIN_LENGTH) {
		pr_err("config data truncated/corrupted\n");
		return 1;
	}
	return 0;
}

int wbl_get_mac_address(u8 *mac)
{
	if (!wbl_config_is_valid()) {
		memset(mac, 0, ETH_ALEN);
		return 1;
	}

	memcpy(mac, config->eth0_mac, ETH_ALEN);
	return 0;
}
EXPORT_SYMBOL(wbl_get_mac_address);
