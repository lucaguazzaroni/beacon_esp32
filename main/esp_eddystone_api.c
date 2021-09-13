/*
   This example code is in the Public Domain (or CC0 licensed, at your option.)

   Unless required by applicable law or agreed to in writing, this
   software is distributed on an "AS IS" BASIS, WITHOUT WARRANTIES OR
   CONDITIONS OF ANY KIND, either express or implied.
*/

/****************************************************************************
*
* This file is for eedystone uuid beacons
*
****************************************************************************/
#include <stdint.h>
#include <string.h>
#include <stdbool.h>
#include <stdio.h>
#include "esp_log.h"

#include "esp_eddystone_api.h"

static const char* TAG = "EDDYSTONE_API";

static esp_ble_eddystone_uid_t eddystone_advertising_data = {
        .flags = {0x02, 0x01, 0x00},
        .length = 21,
        .type = 0x16,
        .beacon_type = 0xFEAA,
        .frame_type = 0x00,
        .ranging_data = 0xC5,
        .id_namespace = {0xFD, 0xA5, 0x06, 0x93, 0xA4, 0xE2, 0x4F, 0xB1, 0xAF, 0xCF},
        .id_instance = {0x00, 0x00, 0x00, 0x00, 0x00, 0x00},
        .rfu = {0x03,0xFF,0xE0,0x00}
};

void eddystone_config_data(uint8_t *id_namespace, uint8_t *id_instance, uint8_t ranging_data)
{
    if( id_namespace!=NULL ){
        memcpy( eddystone_advertising_data.id_namespace, 
                id_namespace, 
                EDDYSTONE_UID_NAMESPACE_LEN
               );
    }   

    if( id_instance!=NULL ){
        memcpy( eddystone_advertising_data.id_instance, 
                id_instance, 
                EDDYSTONE_UID_INSTANCE_LEN
               );
    }
    
    eddystone_advertising_data.ranging_data = ranging_data;
}

void eddystone_get_adv_data(uint8_t *adv_data_ptr){
    if( adv_data_ptr != NULL){
        memcpy( adv_data_ptr, 
                &eddystone_advertising_data, 
                sizeof(eddystone_advertising_data)
              );
    }
}

uint8_t eddystone_get_adv_data_size(void){
    return sizeof(eddystone_advertising_data);
}


