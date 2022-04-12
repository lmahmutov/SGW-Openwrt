#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#include <stdbool.h>

#include "tuya_gw_infra_api.h"
#include "tuya_gw_z3_api.h"
#include "tuya_gw_dp_api.h"

/* must apply for uuid, authkey and product key from tuya iot develop platform */
#define UUID         "003tuyatestf7f149185"
#define AUTHKEY      "NeA8Wc7srpAZHEMuru867oblOLN2QCC1"
#define PRODUCT_KEY  "GXxoKf27eVjA7x1c"

#define Z3_PROFILE_ID_HA           0x0104

#define ZCL_ON_OFF_CLUSTER_ID      0x0006

#define Z3_CMD_TYPE_GLOBAL         0x01
#define Z3_CMD_TYPE_PRIVATE        0x02
#define Z3_CMD_TYPE_ZDO            0x03

#define ZCL_OFF_COMMAND_ID         0x00
#define ZCL_ON_COMMAND_ID          0x01

#define ZCL_READ_ATTRIBUTES_COMMAND_ID      0x00
#define READ_ATTRIBUTES_RESPONSE_COMMAND_ID 0x01
#define REPORT_ATTRIBUTES_COMMAND_ID        0x0A
#define READ_ATTRIBUTER_RESPONSE_HEADER     3 /* Attributer ID: 2 Bytes, Status: 1 Btye */
#define REPORT_ATTRIBUTES_HEADER            2 /* Attributer ID: 2 Bytes */

static void usage(void)
{
    printf("usage:\r\n");
    printf("  u: unactive gw unittest\r\n");
    printf("  p: permit device join unittest\r\n");
    printf("  s: send zcl commnad unittest\r\n");
    printf("  d: delete device unittest\r\n");
    printf("  q: exit \r\n");
    printf("\r\n"); 
}

static void test_switch_onoff(const char *id, uint8_t dst_ep, int on)
{
    int ret = 0;
    ty_z3_aps_frame_s data = {0};

    memset(&data, 0x00, sizeof(ty_z3_aps_frame_s));

    strncpy(data.id, id, sizeof(data.id));
    data.profile_id = Z3_PROFILE_ID_HA;
    data.cluster_id = ZCL_ON_OFF_CLUSTER_ID;
    data.cmd_type = Z3_CMD_TYPE_PRIVATE;
    data.src_endpoint = 0x01;
    data.dst_endpoint = dst_ep;

    data.msg_length = 0;

    if (on)
        data.cmd_id = ZCL_ON_COMMAND_ID;
    else 
        data.cmd_id = ZCL_OFF_COMMAND_ID;

    ret = tuya_user_iot_z3_dev_send_zcl_cmd(&data);
    if (ret != 0) {
        log_err("tuya_user_iot_z3_dev_send_zcl_cmd error, ret: %d", ret);
        return;
    }

    return ;
}

static int _iot_get_uuid_authkey_cb(char *uuid, int uuid_size, char *authkey, int authkey_size)
{
    strncpy(uuid, UUID, uuid_size);
    strncpy(authkey, AUTHKEY, authkey_size);

    return 0;
}

static int _iot_get_product_key_cb(char *pk, int pk_size)
{
    strncpy(pk, PRODUCT_KEY, pk_size);

    return 0;
}

static int _gw_configure_op_mode_cb(ty_op_mode_t mode)
{
    log_debug("gw configure operation mode callback");

    /* USER TODO */
    switch (mode) {
    case TY_OP_MODE_ADD_START:
        log_debug("add device start");
        break;
    case TY_OP_MODE_ADD_STOP:
        log_debug("add device stop");
        break;
    }
    
    return 0;
}

static int _gw_active_status_changed_cb(ty_gw_status_t status)
{
    log_debug("active status changed, status: %d", status);

    return 0;
}

static int _gw_online_status_changed_cb(bool registered, bool online)
{
    log_debug("online status changed, registerd: %d, online: %d", registered, online);

    return 0;
}

static int _gw_fetch_local_log_cb(char *path, int path_len)
{
    char cmd[256] = {0};

    log_debug("gw fetch local log callback");
    /* USER TODO */

    /*
    snprintf(file, len, "/tmp/log.tgz");

    snprintf(cmd, sizeof(cmd), "tar -zvcf %s --absolute-names /tmp/tuya.log", file);
    system(cmd);
    */

    return 0;
}

static void _gw_reboot_cb(void)
{
    log_debug("gw reboot callback");
    /* USER TODO */

    return;
}

static void _gw_reset_cb(void)
{
    log_debug("gw reset callback");
    /* USER TODO */

    return;
}

static int _gw_upgrade_cb(const char *img)
{
    log_debug("gw upgrade callback");
    /* USER TODO */

    return 0;
}

static int _dev_obj_cmd_cb(ty_obj_cmd_s *dp)
{
    int i = 0;

    log_debug("device obj cmd callback");
    log_debug("cmd_tp: %d, dtt_tp: %d, dps_cnt: %u", dp->cmd_tp, dp->dtt_tp, dp->dps_cnt);

    for (i = 0; i < dp->dps_cnt; i++) {
        log_debug("dpid: %d", dp->dps[i].dpid);
        switch (dp->dps[i].type) {
        case DP_TYPE_BOOL:
            log_debug("dp_bool value: %d", dp->dps[i].value.dp_bool);
            break;
        case DP_TYPE_VALUE:
            log_debug("dp_value value: %d", dp->dps[i].value.dp_value);
            break;
        case DP_TYPE_ENUM:
            log_debug("dp_enum value: %d", dp->dps[i].value.dp_enum);
            break;
        case DP_TYPE_STR:
            log_debug("dp_str value: %s", dp->dps[i].value.dp_str);
            break;
        }
    }
    /* USER TODO */

    if (dp->cid != NULL) {
        tuya_user_iot_report_obj_dp(dp->cid, dp->dps, dp->dps_cnt);
        /* test on smart switch */
        test_switch_onoff(dp->cid, 0x01, dp->dps[0].value.dp_bool);
	}

    return 0; 
}

static int _dev_raw_cmd_cb(ty_raw_cmd_s *dp)
{
    int i = 0;

    log_debug("device raw cmd callback");
    log_debug("cmd_tp: %d, dtt_tp: %d, dpid: %d, len: %u", dp->cmd_tp, dp->dtt_tp, dp->dpid, dp->len);

    log_debug("data: ");
    for (i = 0; i < dp->len; i++)
        printf("%02x ", dp->data[i]);

    printf("\n");
    /* USER TODO */

    return 0;
}

static int _z3_dev_active_state_changed_cb(const char *id, int state)
{
    log_debug("device active state changed callback");
    log_debug("id: %s, state: %d", id, state);
    /* USER TODO */

    return 0;
}

static int _z3_dev_init_data_cb(void)
{
    int ret = 0;
    const char *id = "000d6ffffe6d81ec";
    ty_z3_aps_frame_s data = {0};
    uint16_t atrr_buf[5] = {0x0000, 0x4001, 0x4002, 0x8001, 0x5000};

    log_debug("device read attribute callback");
    /* USER TODO */

    memset(&data, 0x00, sizeof(ty_z3_aps_frame_s));

    strncpy(data.id, id, sizeof(data.id));
    data.profile_id = Z3_PROFILE_ID_HA;
    data.cluster_id = ZCL_ON_OFF_CLUSTER_ID;
    data.cmd_type = Z3_CMD_TYPE_GLOBAL;
    data.src_endpoint = 0x01;
    data.dst_endpoint = 0xff;
    data.cmd_id = ZCL_READ_ATTRIBUTES_COMMAND_ID;

    data.msg_length = sizeof(atrr_buf);
    data.message = (uint8_t *)atrr_buf;

    ret = tuya_user_iot_z3_dev_send_zcl_cmd(&data);
    if (ret != 0) {
        log_err("tuya_user_iot_z3_dev_send_zcl_cmd error, ret: %d", ret);
        return ret;
    }

    return 0;
}

static int _z3_dev_join_cb(ty_z3_desc_s *desc)
{
    int ret = 0;
    char *pid = "nPGIPl5D";
    char *ver = "1.0.7";
    uint32_t uddd = 0x8000200;

    log_debug("device join callback");
    log_debug("          id: %s", desc->id);
    log_debug("     node_id: 0x%04x", desc->node_id);
    log_debug("   manu_name: %s", desc->manu_name);
    log_debug("    model_id: %s", desc->model_id);
    log_debug(" rejoin_flag: %d", desc->rejoin_flag);
    /* USER TODO */

    ret = tuya_user_iot_z3_dev_bind(uddd, desc->id, pid, ver);
    if (ret != 0) {
        log_err("tuya_user_iot_z3_dev_bind failed, ret: %d", ret);
        return ret;
    }

    return 0;
}

static int _z3_dev_leave_cb(const char *id)
{
    log_debug("device leave callback");
    /* USER TODO */

    return 0;
}

static int _z3_dev_zcl_report_cb(ty_z3_aps_frame_s *frame)
{
    int i = 0, ret = 0;
    int dps_cnt = 1;
    ty_dp_s *dps = NULL;
    
    log_debug("device zcl report callback");
    log_debug("        id: %s", frame->id);
    log_debug("profile_id: 0x%04x", frame->profile_id);
    log_debug("cluster_id: 0x%04x", frame->cluster_id);
    log_debug("   node_id: 0x%04x", frame->node_id);
    log_debug("    src_ep: %d", frame->src_endpoint);
    log_debug("    dst_ep: %d", frame->dst_endpoint);
    log_debug("  group_id: %d", frame->group_id);
    log_debug("  cmd_type: %d", frame->cmd_type);
    log_debug("   command: 0x%02x", frame->cmd_id);
    log_debug("frame_type: %d", frame->frame_type);
    log_debug("   msg_len: %d", frame->msg_length);
    log_debug("       msg: ");
    for (i = 0; i < frame->msg_length; i++)
        printf("%02x ", frame->message[i]);
    
    printf("\n");
    /* USER TODO */

    /* test one switch */
    dps = (ty_dp_s *)malloc(dps_cnt * sizeof(ty_dp_s));
    if (dps == NULL) {
        log_err("malloc failed");
        return -1;
    }

    dps[0].dpid = 0x01;
    dps[0].type = DP_TYPE_BOOL;

    if ((frame->profile_id == Z3_PROFILE_ID_HA) && \
        (frame->cluster_id == ZCL_ON_OFF_CLUSTER_ID)) {
        if (frame->cmd_id == REPORT_ATTRIBUTES_COMMAND_ID) {
            dps[0].value.dp_bool = frame->message[REPORT_ATTRIBUTES_HEADER+1];
        } else if (frame->cmd_id == READ_ATTRIBUTES_RESPONSE_COMMAND_ID) {
            dps[0].value.dp_bool = frame->message[READ_ATTRIBUTER_RESPONSE_HEADER+1];
        } else {
            free(dps);
            return -1;
        }
    }
    
    ret = tuya_user_iot_report_obj_dp(frame->id, dps, dps_cnt);
    if (ret != 0) {
        log_err("tuya_user_iot_report_obj_dp error, ret: %d", ret);
        free(dps);
        return ret;
    }

    if (dps != NULL)
        free(dps);

    return 0;
}

static void test_tuya_user_iot_unactive_gw(void)
{
    tuya_user_iot_unactive_gw();

    return;
}

static void test_tuya_user_iot_permit_join(void)
{
    static bool permit = false;
    int ret = 0;

    permit ^= 1;

    ret = tuya_user_iot_permit_join(permit);
    if (ret != 0) {
        log_err("tuya_user_iot_permit_join error, ret: %d", ret);
        return;
    }

    return;
}

static void test_tuya_user_iot_z3_dev_send_zcl_cmd(void)
{
    int i = 0, val = 0;
    uint8_t ep = 0x01;
    char *id = "000d6ffffe6d81ec";

    val ^= 1;
    test_switch_onoff(id, ep, val);

    val ^= 1;
    test_switch_onoff(id, ep, val);

    for (i = 0; i < 10; i++) { 
        val ^= 1;     
        test_switch_onoff(id, ep, val);
        sleep(1);

        val ^= 1; 
        test_switch_onoff(id, ep, val);
        sleep(1);
    }

    return;
}

static void test_tuya_user_iot_z3_dev_del(void)
{
    int ret = 0;
    char *id = "000d6ffffe6d81ec";

    ret = tuya_user_iot_z3_dev_del(id);
    if (ret != 0) {
        log_err("tuya_user_iot_z3_dev_del error, ret: %d", ret);
        return;
    }

    return;
}

int main(int argc, char **argv)
{
    int ret = 0;
    bool debug = true;
    char line[256] = {0};

    ty_gw_attr_s gw_attr = {
        .storage_path = "./",
        .cache_path = "/tmp/",
        .tty_device = "/dev/ttyS1",
        .tty_baudrate = 115200,
        .eth_ifname = "br0",
        .ver = "1.0.0",
        .uz_cfg = "./devices.json",
        .log_level = TY_LOG_DEBUG
    };

    ty_gw_infra_cbs_s gw_infra_cbs = {
        .get_uuid_authkey_cb = _iot_get_uuid_authkey_cb,
        .get_product_key_cb = _iot_get_product_key_cb,
        .gw_fetch_local_log_cb = _gw_fetch_local_log_cb,
        .gw_configure_op_mode_cb = _gw_configure_op_mode_cb,
        .gw_reboot_cb = _gw_reboot_cb,
        .gw_reset_cb = _gw_reset_cb,
        .gw_upgrade_cb = _gw_upgrade_cb,
        .gw_active_status_changed_cb = _gw_active_status_changed_cb,
        .gw_online_status_changed_cb = _gw_online_status_changed_cb,
    };

    ty_dev_cmd_cbs_s dev_cmd_cbs = {
        .dev_obj_cmd_cb = _dev_obj_cmd_cb,
        .dev_raw_cmd_cb = _dev_raw_cmd_cb,
    };

    ty_z3_dev_cbs_s z3_dev_cbs = {
        .z3_dev_active_state_changed_cb = _z3_dev_active_state_changed_cb,
        .z3_dev_init_data_cb = _z3_dev_init_data_cb,
        .z3_dev_join_cb = _z3_dev_join_cb,
        .z3_dev_leave_cb = _z3_dev_leave_cb,
        .z3_dev_zcl_report_cb = _z3_dev_zcl_report_cb,
    };

    ret = tuya_user_iot_reg_dev_cmd_cb(&dev_cmd_cbs);
    if (ret != 0) {
        log_err("tuya_user_iot_reg_dev_cmd_cb failed, ret: %d", ret);
        return ret;
    }

    ret = tuya_user_iot_reg_z3_dev_cb(&z3_dev_cbs);
    if (ret != 0) {
        log_err("tuya_user_iot_reg_z3_dev_cb failed, ret: %d", ret);
        return ret;
    }

    ret = tuya_user_iot_init(&gw_attr, &gw_infra_cbs);
    if (ret != 0) {
        log_err("tuya_user_iot_init failed");
        return ret;
    }

    while (1) {
        memset(line, 0, sizeof(line));
        fgets(line, sizeof(line), stdin);
        printf("Your input: %c\r\n", line[0]);
        switch (line[0]) {
        case 'u':
            test_tuya_user_iot_unactive_gw();
            break;
        case 'p':
            test_tuya_user_iot_permit_join();
            break;
        case 's':
            test_tuya_user_iot_z3_dev_send_zcl_cmd();
            break;
        case 'd':
            test_tuya_user_iot_z3_dev_del();
            break;
        case 'q':
            exit(EXIT_SUCCESS);
            break;
        default:
            usage();
            break;
        }
    }

    return 0;
}
