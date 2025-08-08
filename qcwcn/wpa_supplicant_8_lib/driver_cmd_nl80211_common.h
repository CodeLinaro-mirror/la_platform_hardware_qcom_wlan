/*
 * Driver interaction with extended Linux CFG80211
 *
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License version 2 as
 * published by the Free Software Foundation.
 *
 * Alternatively, this software may be distributed under the terms of BSD
 * license.
 * Changes from Qualcomm Technologies, Inc. are provided under the following license:
 * Copyright (c) Qualcomm Technologies, Inc. and/or its subsidiaries.
 * SPDX-License-Identifier: BSD-3-Clause-Clear
 */

#include <net/if.h>
#include <netlink/genl/genl.h>
#include <netlink/genl/ctrl.h>
#include <netlink/object-api.h>
#include <linux/pkt_sched.h>

#define OBSS_PD_THRESHOLD_MIN -82
#define OBSS_PD_THRESHOLD_MAX -62
#define MAX_NUM_MLO_LINKS 15
#define NL80211_ATTR_MAX_INTERNAL 256

struct wpa_driver_nl80211_data *drv;
struct i802_bss *bss;

struct nl_msg *prepare_vendor_nlmsg(struct wpa_driver_nl80211_data *drv,
		                    char *ifname, int subcmd);

int send_nlmsg(struct nl_sock *cmd_sock, struct nl_msg *nlmsg,
	       nl_recvmsg_msg_cb_t customer_cb, void *arg);

char *result_copy_to_buf(char *src, char *dst_buf, int *dst_len);
int wpa_driver_sr_cmd(struct i802_bss *bss, char *cmd, char *buf, size_t buf_len);
int sr_response_handler(struct resp_info *info, struct nlattr *vendata, int datalen);
int response_handler(struct nl_msg *msg, void *arg);
int wpa_driver_sr_event(struct wpa_driver_nl80211_data *drv,
		        u32 vendor_id, u32 subcmd, u8 *data, size_t len);
char *skip_white_space(char *cmd);
char *get_next_arg(char *cmd);
s32 get_s32_from_string(char *cmd_string, int *ret);
char *move_to_next_str(char *cmd);
u8 get_u8_from_string(char *cmd_string, int *ret);
