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

static esp_ble_altbeacon_t altbeacon_raw_advertising_data = {
    .altbeacon_head = {
        .flags = {0x02, 0x01, 0x00},
        .length = 0x1B,
        .type = 0xFF,
        .company_id = 0xFFFF,
        .beacon_type = 0xACBE
    },
    .altbeacon_vendor = {
        .beacon_id = {0xFD, 0xA5, 0x06, 0x93, 0xA4, 0xE2, 0x4F, 0xB1, 0xAF, 0xCF, 0xC6, 0xEB, 0x11, 0x11, 0x11, 0x11},
        .beacon_id_extra = {0x00,0x00,0x00,0x00},
        .reference_rssi = 0xC5,
        .mfg_reserved = 0x11
    }
};

uint8_t altbeacon_data_size = sizeof(altbeacon_raw_advertising_data);

void altbeacon_config_data(uint8_t *uuid, uint8_t *uuid_extra, uint8_t ref_rssi, uint8_t mfg_reserved)
{
    if( uuid!=NULL && sizeof(uuid)==16  ){
        memcpy( altbeacon_raw_advertising_data.altbeacon_vendor.beacon_id, uuid, 16);
    }   
    if( uuid_extra!=NULL && sizeof(uuid_extra)==4 ){
        memcpy( altbeacon_raw_advertising_data.altbeacon_vendor.beacon_id_extra, uuid_extra, 4);
    }
    altbeacon_raw_advertising_data.altbeacon_vendor.reference_rssi = ref_rssi;
    altbeacon_raw_advertising_data.altbeacon_vendor.mfg_reserved = mfg_reserved;

}

void altbeacon_get_adv_data(uint8_t *adv_data_ptr){
    //uint8_t adv_data_size;

    if( adv_data_ptr != NULL){
        memcpy(adv_data_ptr, &altbeacon_raw_advertising_data, altbeacon_data_size);
    }
}

uint8_t altbeacon_get_adv_data_size(void){
    return altbeacon_data_size;
}


