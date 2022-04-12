#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#include <stdbool.h>

#include "tuya_gw_dp_api.h"
#include "tuya_gw_misc_api.h"
#include "tuya_gw_infra_api.h"

/* must apply for uuid, authkey and product key from tuya iot develop platform */
#define UUID         "003tuyatestf7f149185"
#define AUTHKEY      "NeA8Wc7srpAZHEMuru867oblOLN2QCC1"
#define PRODUCT_KEY  "GXxoKf27eVjA7x1c"

static void usage(void)
{
    printf("usage:\r\n");
    printf("  u: unactive gw unittest\r\n");
    printf("  p: permit device join unittest\r\n");
    printf("  B: bind device unittest\r\n");
    printf("  U: unbind device unittest\r\n");
    printf("  r: report obj cmd unittest\r\n");
    printf("  k: keepalive unittest\r\n");
    printf("  q: exit \r\n");
    printf("\r\n"); 
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

static int _misc_dev_add_cb(bool permit, uint32_t timeout)
{
    log_debug("misc device add callback");
    log_debug("permit: %d, timeout: %d", permit, timeout);
    /* USER TODO */

    return 0;
}

static int _misc_dev_del_cb(const char *dev_id)
{
    log_debug("misc device del callback");
    log_debug("dev_id: %s", dev_id);
    /* USER TODO */

    return 0;
}

static int _misc_dev_bind_ifm_cb(const char *dev_id, int result)
{
    log_debug("misc device bind inform callback");
    log_debug("dev_id: %s, result: %d", dev_id, result);
    /* USER TODO */

    return 0;
}

static int _misc_dev_upgrade_cb(const char *dev_id, const char *img)
{
    log_debug("misc device upgrade callback");
    log_debug("dev_id: %s, image: %s", dev_id, img);
    /* USER TODO */

    return 0;
}

static int _misc_dev_reset_cb(const char *dev_id)
{
    log_debug("misc device reset callback");
    log_debug("dev_id: %s", dev_id);
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

    if (dp->cid != NULL)
        tuya_user_iot_report_obj_dp(dp->cid, dp->dps, dp->dps_cnt);

    /* USER TODO */

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

static void test_tuya_user_iot_misc_dev_bind(void)
{
    int ret = 0;
    uint32_t uddd = 0x83000101;
    char *dev_id = "000d6ffffe67e2ca";
    char *pid = "d1xabwgg";
    char *ver = "1.0.0";

    ret = tuya_user_iot_misc_dev_bind(uddd, dev_id, pid, ver);
    if (ret != 0) {
        log_err("tuya_user_iot_misc_dev_bind error, ret: %d", ret);
        return;
    }

    return;
}

static void test_tuya_user_iot_misc_dev_unbind(void)
{
    int ret = 0;
    char *dev_id = "000d6ffffe67e2ca";

    ret = tuya_user_iot_misc_dev_unbind(dev_id);
    if (ret != 0) {
        log_err("tuya_user_iot_misc_dev_unbind error, ret: %d", ret);
        return;
    }

    return;
}

static void test_tuya_user_iot_misc_dev_fresh_hb(void)
{
    int ret = 0;
    char *dev_id = "000d6ffffe67e2ca";

    ret = tuya_user_iot_misc_dev_fresh_hb(dev_id, 120);
    if (ret != 0) {
        log_err("tuya_user_iot_misc_dev_fresh_hb error, ret: %d", ret);
        return;
    }

    return;
}

static void test_tuya_user_iot_report_obj_dp(void)
{
    int ret = 0, i = 0;
    static int val = 0;
    char *dev_id = "000d6ffffe67e2ca";
    int dps_cnt = 1;
    ty_dp_s *dps = NULL;

    dps = (ty_dp_s *)malloc(dps_cnt * sizeof(ty_dp_s));
    if (dps == NULL) {
        log_err("malloc failed");
        return;
    }

    val ^= 1;

    dps[0].dpid = 1;
    dps[0].type = DP_TYPE_BOOL;
    dps[0].value.dp_bool = val;

    ret = tuya_user_iot_report_obj_dp(dev_id, dps, dps_cnt);
    if (ret != 0) {
        log_err("tuya_user_iot_report_obj_dp error, ret: %d", ret);
    }

    if (dps != NULL)
        free(dps);

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

    ty_misc_dev_cbs_s misc_dev_cbs = {
        .misc_dev_add_cb = _misc_dev_add_cb,
        .misc_dev_del_cb = _misc_dev_del_cb,
        .misc_dev_bind_ifm_cb = _misc_dev_bind_ifm_cb,
        .misc_dev_upgrade_cb = _misc_dev_upgrade_cb,
        .misc_dev_reset_cb = _misc_dev_reset_cb,
    };

    ret = tuya_user_iot_reg_dev_cmd_cb(&dev_cmd_cbs);
    if (ret != 0) {
        log_err("tuya_user_iot_reg_dev_cmd_cb failed, ret: %d", ret);
        return ret;
    }

    ret = tuya_user_iot_reg_misc_dev_cb(&misc_dev_cbs);
    if (ret != 0) {
        log_err("tuya_user_iot_reg_misc_dev_cb failed, ret: %d", ret);
        return ret;
    }

    ret = tuya_user_iot_init(&gw_attr, &gw_infra_cbs);
    if (ret != 0) {
        log_err("tuya_user_iot_init failed, ret: %d", ret);
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
        case 'B':
            test_tuya_user_iot_misc_dev_bind();
            break;
        case 'U':
            test_tuya_user_iot_misc_dev_unbind();
            break;
        case 'r':
            test_tuya_user_iot_report_obj_dp();
            break;
        case 'k':
            test_tuya_user_iot_misc_dev_fresh_hb();
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
