/*
   This example code is in the Public Domain (or CC0 licensed, at your option.)

   Unless required by applicable law or agreed to in writing, this
   software is distributed on an "AS IS" BASIS, WITHOUT WARRANTIES OR
   CONDITIONS OF ANY KIND, either express or implied.
*/

/****************************************************************************
*
* This file is for AltBeacon APIs. 
*
****************************************************************************/
#include <stdint.h>
#include <string.h>
#include <stdbool.h>
#include <stdio.h>
#include "esp_log.h"

#include "esp_altbeacon_api.h"

static const char* TAG = "ALTBEACON_API";

static esp_ble_altbeacon_t altbeacon_advertising_data = {
    .flags = {0x02, 0x01, 0x00},
    .length = 0x1B,
    .type = 0xFF,
    .company_id = 0xFFFF,
    .beacon_type = 0xACBE,
    .beacon_id = {0xFD, 0xA5, 0x06, 0x93, 0xA4, 0xE2, 0x4F, 0xB1, 0xAF, 0xCF, 0xC6, 0xEB, 0x11, 0x11, 0x11, 0x11},
    .beacon_id_extra = {0x00,0x00,0x00,0x00},
    .reference_rssi = 0xC5,
    .mfg_reserved = 0x11
};

void altbeacon_config_data(uint8_t *id, uint8_t *id_extra, uint8_t ref_rssi, uint8_t mfg_reserved)
{
    if( id!=NULL ){
        memcpy( altbeacon_advertising_data.beacon_id, 
                id, 
                ALTBEACON_ID_LEN
              );
    }  

    if( id_extra!=NULL ){
        memcpy( altbeacon_advertising_data.beacon_id_extra, 
                id_extra, 
                ALTBEACON_EXTRA_ID_LEN
              );
    }

    altbeacon_advertising_data.reference_rssi = ref_rssi;
    altbeacon_advertising_data.mfg_reserved = mfg_reserved;
}

void altbeacon_get_adv_data(uint8_t *adv_data_ptr){
    if( adv_data_ptr != NULL){
        memcpy( adv_data_ptr, 
                &altbeacon_advertising_data, 
                sizeof(altbeacon_advertising_data)
              );
    }
}

uint8_t altbeacon_get_adv_data_size(void){
    return sizeof(altbeacon_advertising_data);
}


