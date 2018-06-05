/*
   This example code is in the Public Domain (or CC0 licensed, at your option.)

   Unless required by applicable law or agreed to in writing, this
   software is distributed on an "AS IS" BASIS, WITHOUT WARRANTIES OR
   CONDITIONS OF ANY KIND, either express or implied.
*/



/****************************************************************************
*
* This file is for iBeacon APIs. It supports both iBeacon encode and decode. 
*
* iBeacon is a trademark of Apple Inc. Before building devices which use iBeacon technology,
* visit https://developer.apple.com/ibeacon/ to obtain a license.
*
****************************************************************************/
#include <stdint.h>
#include <string.h>
#include <stdbool.h>
#include <stdio.h>
#include "esp_log.h"

#include "esp_altbeacon_api.h"

static const char* TAG = "ALTBEACON_API";

const uint8_t uuid_zeros[ESP_UUID_LEN_128] = {0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00};
uint8_t BEACON_ID[] =       {0xFD, 0xA5, 0x06, 0x93, 0xA4, 0xE2, 0x4F, 0xB1, 0xAF, 0xCF, 0xC6, 0xEB, 0x11, 0x11, 0x11, 0x11}
uint8_t BEACON_ID_EXTRA[] = {0x00,0x00,0x00,0x00}

/* For iBeacon packet format, please refer to Apple "Proximity Beacon Specification" doc */
/* Constant part of iBeacon data */
/*esp_ble_altbeacon_head_t altbeacon_common_head = {
    .flags = {0x02, 0x01, 0x00},
    .length = 0x1B,
    .type = 0xFF,
    .company_id = 0xFFFF,
    .beacon_type = 0xACBE
};*/

/* Vendor part of iBeacon data*//*
esp_ble_altbeacon_vendor_t vendor_config = {
    .beacon_id = BEACON_ID,
    .beacon_id_extra = BEACON_ID_EXTRA,
    .reference_rssi = 0xC5,
    .mfg_reserved = 0x11
};*/

static esp_ble_altbeacon_t raw_advertising_data = {
    .altbeacon_head = {
        .flags = {0x02, 0x01, 0x00},
        .length = 0x1B,
        .type = 0xFF,
        .company_id = 0xFFFF,
        .beacon_type = 0xACBE
    },
    .altbeacon_vendor = {
        .beacon_id = BEACON_ID,
        .beacon_id_extra = BEACON_ID_EXTRA,
        .reference_rssi = 0xC5,
        .mfg_reserved = 0x11
    }
};

void altbeacon_config_data(uint8_t *uuid, uint8_t *uuid_extra, uint8_t ref_rssi, uint8_t mfg_reserved){

    esp_log_buffer_hex("IBEACON_DEMO: :", uuid, 16 );
    esp_log_buffer_hex("IBEACON_DEMO: :", uuid_extra, 4);
    if( uuid!=NULL && sizeof(uuid)==16  ){
        memcpy( raw_advertising_data.altbeacon_vendor.beacon_id, uuid, 16);
    }   
    if( uuid_extra!=NULL && sizeof(uuid_extra)==4 ){
        memcpy( raw_advertising_data.altbeacon_vendor.beacon_id_extra, uuid_extra, 4);
    }
    esp_log_buffer_hex("IBEACON_DEMO: :", raw_advertising_data.altbeacon_vendor.beacon_id, 16 );
    esp_log_buffer_hex("IBEACON_DEMO: :", raw_advertising_data.altbeacon_vendor.beacon_id_extra, 4);
    raw_advertising_data.altbeacon_vendor.reference_rssi = ref_rssi;
    raw_advertising_data.altbeacon_vendor.mfg_reserved = mfg_reserved;

}

uint8_t *altbeacon_get_adv_data(void){
    //memcpy(raw_advertising_data.altbeacon_head, &altbeacon_common_head, sizeof(esp_ble_altbeacon_head_t));
    //memcpy(raw_advertising_data.altbeacon_vendor, &vendor_config, sizeof(esp_ble_altbeacon_vendor_t));

    return (uint8_t *)&raw_advertising_data;
}



