/*
   This example code is in the Public Domain (or CC0 licensed, at your option.)

   Unless required by applicable law or agreed to in writing, this
   software is distributed on an "AS IS" BASIS, WITHOUT WARRANTIES OR
   CONDITIONS OF ANY KIND, either express or implied.
*/



/****************************************************************************
*
* This file is for iBeacon definitions. It supports both iBeacon sender and receiver
* which is distinguished by macros IBEACON_SENDER and IBEACON_RECEIVER,
*
* iBeacon is a trademark of Apple Inc. Before building devices which use iBeacon technology,
* visit https://developer.apple.com/ibeacon/ to obtain a license.
*
****************************************************************************/

#include <stdint.h>
#include <string.h>
#include <stdbool.h>
#include <stdio.h>

#include "esp_gap_ble_api.h"
#include "esp_gattc_api.h"


/* Because current ESP IDF version doesn't support scan and adv simultaneously,
 * so iBeacon sender and receiver should not run simultaneously */
#define ALTBEACON_SENDER      0
#define ALTBEACON_RECEIVER    1
#define ALTBEACON_MODE ALTBEACON_SENDER

/* Major and Minor part are stored in big endian mode in iBeacon packet,
 * need to use this macro to transfer while creating or processing
 * iBeacon data */
#define ENDIAN_CHANGE_U16(x) ((((x)&0xFF00)>>8) + (((x)&0xFF)<<8))

/* Espressif WeChat official account can be found using WeChat "Yao Yi Yao Zhou Bian", 
 * if device advertises using ESP defined UUID. 
 * Please refer to http://zb.weixin.qq.com for further information. */
#define BEACON_ID    {0xFD, 0xA5, 0x06, 0x93, 0xA4, 0xE2, 0x4F, 0xB1, 0xAF, 0xCF, 0xC6, 0xEB, 0x11, 0x11, 0x11, 0x11}
#define BEACON_ID_EXTRA {0x00,0x00,0x00,0x00}


typedef struct {
    uint8_t flags[3];
    uint8_t length;
    uint8_t type;
    uint16_t company_id;
    uint16_t beacon_type;
}__attribute__((packed)) esp_ble_altbeacon_head_t;

typedef struct {
    uint8_t beacon_id[16];
    uint8_t beacon_id_extra[4];
    int8_t reference_rssi;
    uint8_t mfg_reserved;
}__attribute__((packed)) esp_ble_altbeacon_vendor_t;


typedef struct {
    esp_ble_altbeacon_head_t   altbeacon_head;
    esp_ble_altbeacon_vendor_t altbeacon_vendor;
}__attribute__((packed)) esp_ble_altbeacon_t;


/* For iBeacon packet format, please refer to Apple "Proximity Beacon Specification" doc */
/* Constant part of iBeacon data */
extern esp_ble_altbeacon_head_t altbeacon_common_head;

bool esp_ble_is_ibeacon_packet (uint8_t *adv_data, uint8_t adv_data_len);

esp_err_t esp_ble_config_altbeacon_data (esp_ble_altbeacon_vendor_t *vendor_config, esp_ble_altbeacon_t *altbeacon_adv_data);
