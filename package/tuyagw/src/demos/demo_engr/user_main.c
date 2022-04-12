#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#include <getopt.h>

#include "tuya_gw_infra_api.h"

/* must apply for uuid, authkey and product key from tuya iot develop platform */
/* #define UUID         "003tuyatestf7f149185" */
/* #define AUTHKEY      "NeA8Wc7srpAZHEMuru867oblOLN2QCC1" */
/* #define PRODUCT_KEY  "GXxoKf27eVjA7x1c" */
#define UUID         "65df704231d1b1b5"
#define AUTHKEY      "RjEDo7swB9cFIvB5R5eViw2E2OLPBTdz"

static int engr_mode = 0;

int iot_get_uuid_authkey_cb(char *uuid, int uuid_size, char *authkey, int authkey_size)
{
    strncpy(uuid, UUID, uuid_size);
    strncpy(authkey, AUTHKEY, authkey_size);

    return 0;
}

int iot_get_product_key_cb(char *pk, int pk_size)
{
    if (engr_mode) {
        strncpy(pk, "gpy8uw1iqwooyg9j", pk_size);
    } else {
        strncpy(pk, "dn6an7mvbrnxgpi7", pk_size);
    }

    return 0;
}

int iot_fetch_local_log_cb(char *path, int path_len)
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

void iot_engineer_finished_cb(void)
{
    log_debug("reboot the program, and switch to normal mode");
}

int main(int argc, char **argv)
{
    int opt = 0, ret = 0;

    while ((opt = getopt(argc, argv, "e")) != -1) {
        switch (opt) {
        case 'e':
            /* switch to engineering mode */
            engr_mode = 1;
            break;
        default:
            break;
        }
    }

    /* must reset the opt */
    optind = 0;

    ty_gw_attr_s gw_attr = {
        .storage_path = "./",
        .cache_path = "/tmp/",
        .tty_device = "/dev/ttyS6",
        .tty_baudrate = 57600,
        .eth_ifname = "eth0",
        .ver = "1.0.0",
        .is_engr = engr_mode,
        .log_level = TY_LOG_DEBUG
    };

    ty_gw_infra_cbs_s gw_infra_cbs = {
        .get_uuid_authkey_cb = iot_get_uuid_authkey_cb,
        .get_product_key_cb = iot_get_product_key_cb,
        .gw_fetch_local_log_cb = iot_fetch_local_log_cb,
        .gw_engineer_finished_cb = iot_engineer_finished_cb,
    };

    ret = tuya_user_iot_init(&gw_attr, &gw_infra_cbs);
    if (ret != 0) {
        log_err("tuya_user_iot_init failed");
        return ret;
    }

    while (1) {
        sleep(10);
    }

    return 0;
}
