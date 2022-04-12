/**
 * @file tuya_gw_dp_api.h
 * @author lwl@tuya.com
 * @brief 
 * @version 0.1
 * @date 2020-03-20
 * 
 * @copyright Copyright (c) tuya.inc 2020
 * 
 */
#ifndef TUYA_GW_DP_API_H
#define TUYA_GW_DP_API_H

#include <stdint.h>

#ifdef __cplusplus
extern "C" {
#endif

typedef enum {
	DP_TYPE_BOOL   = 0,
	DP_TYPE_VALUE  = 1,
	DP_TYPE_STR    = 2,
	DP_TYPE_ENUM   = 3,
	DP_TYPE_BITMAP = 4,
} TY_DP_TYPE_E;

typedef struct {
	uint8_t dpid;
	uint8_t type;
	union {
		int       dp_value;
		uint32_t  dp_enum;
		char     *dp_str;
		int       dp_bool;
		uint32_t  dp_bitmap;
	} value;
	uint32_t time_stamp;
} ty_dp_s;

typedef struct {
    uint8_t      cmd_tp; 
    uint8_t      dtt_tp;
    char        *cid; 
    char        *mb_id;
    uint32_t     dps_cnt;
    ty_dp_s      dps[0];
} ty_obj_cmd_s;

typedef struct {
	uint8_t   cmd_tp;
	uint8_t   dtt_tp;
	char     *cid;
	uint8_t   dpid;
	char     *mb_id;
	uint32_t  len;
	uint8_t   data[0];
} ty_raw_cmd_s;

typedef struct {
	int (*dev_obj_cmd_cb)(ty_obj_cmd_s *dp);
	int (*dev_raw_cmd_cb)(ty_raw_cmd_s *dp);
} ty_dev_cmd_cbs_s;

/**
 * @brief  register device command callback.
 *
 * @param[in] cbs. a series of callback function.
 * 
 * @retval  0: success
 * @retval !0: failure
 */
int tuya_user_iot_reg_dev_cmd_cb(ty_dev_cmd_cbs_s *cbs);

/**
 * @brief  report obj dp to tuay cloud.
 *
 * @param[in] dev_id.  device unique ID.
 * @param[in] dps.     dp array.
 * @param[in] dps_cnt. length of dp array.
 * 
 * @retval  0: success
 * @retval !0: failure
 */
int tuya_user_iot_report_obj_dp(const char *dev_id,
                                ty_dp_s *dps,
                                uint32_t dps_cnt);

/**
 * @brief  report raw dp to tuya cloud.
 *
 * @param[in] dev_id.  device unique ID.
 * @param[in] dpid.    dp ID.
 * @param[in] dps.     raw data.
 * @param[in] len.     length of raw data.
 * 
 * @retval  0: success
 * @retval !0: failure
 */
int tuya_user_iot_report_raw_dp(const char *dev_id,
                                uint32_t dpid,
                                uint8_t *data,
                                uint32_t len);
#ifdef __cplusplus
}
#endif
#endif // TUYA_GW_DP_API_H