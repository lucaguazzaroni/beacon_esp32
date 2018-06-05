/*
   This example code is in the Public Domain (or CC0 licensed, at your option.)

   Unless required by applicable law or agreed to in writing, this
   software is distributed on an "AS IS" BASIS, WITHOUT WARRANTIES OR
   CONDITIONS OF ANY KIND, either express or implied.
*/
#include <stdint.h>
#include <string.h>
#include <stdbool.h>
#include <stdio.h>

#include "esp_gap_ble_api.h"
#include "esp_gattc_api.h"


/* For ALTBeacon packet format, please refer to https://github.com/AltBeacon/spec
 */

/* Major and Minor part are stored in big endian mode in iBeacon packet,
 * need to use this macro to transfer while creating or processing
 * iBeacon data */
//#define ENDIAN_CHANGE_U16(x) ((((x)&0xFF00)>>8) + (((x)&0xFF)<<8))

/* The big endian representation of the beacon identifier. For interoperability purposes, 
 * the first 16+ bytes of the beacon identifier should be unique to the advertiser's organizational unit.
 * Any remaining bytes of the beacon identifier may be subdivided as needed for the use case.
 */
#define BEACON_ID       {0xFD, 0xA5, 0x06, 0x93, 0xA4, 0xE2, 0x4F, 0xB1, 0xAF, 0xCF, 0xC6, 0xEB, 0x11, 0x11, 0x11, 0x11}
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

extern esp_ble_altbeacon_head_t altbeacon_common_head;

/**
 */
void altbeacon_config_data(uint8_t *uuid, uint8_t *uuid_extra, uint8_t ref_rssi, uint8_t mfg_reserved);

/**
 */
uint8_t *altbeacon_get_adv_data(void);