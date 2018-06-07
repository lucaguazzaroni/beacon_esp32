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

#include "esp_ibeacon_api.h"

static const char* TAG = "IBEACON_API";

static esp_ble_ibeacon_t ibeacon_raw_advertising_data = {
    .ibeacon_head = {
        .flags = {0x02, 0x01, 0x06},
        .length = 0x1A,
        .type = 0xFF,
        .company_id = 0x004C,
        .beacon_type = 0x1502
    },
    .ibeacon_vendor = {
        .uuid = {0xFD, 0xA5, 0x06, 0x93, 0xA4, 0xE2, 0x4F, 0xB1, 0xAF, 0xCF, 0xC6, 0xEB, 0x11, 0x11, 0x11, 0x11},
        .major = ENDIAN_CHANGE_U16(1000),
        .minor = ENDIAN_CHANGE_U16(1003),
        .measured_power = 0xC5
    }
};

uint8_t ibeacon_data_size = sizeof(ibeacon_raw_advertising_data);

void ibeacon_config_data(uint8_t *uuid, uint16_t major, uint16_t minor, int8_t measured_power)
{
    if( uuid!=NULL && sizeof(uuid)==16  ){
        memcpy( ibeacon_raw_advertising_data.ibeacon_vendor.uuid, uuid, 16);
    }   
    ibeacon_raw_advertising_data.ibeacon_vendor.major = ENDIAN_CHANGE_U16(major);
    ibeacon_raw_advertising_data.ibeacon_vendor.minor = ENDIAN_CHANGE_U16(minor);
    ibeacon_raw_advertising_data.ibeacon_vendor.measured_power = measured_power;
}

void ibeacon_get_adv_data(uint8_t *adv_data_ptr){
    if( adv_data_ptr != NULL){
        memcpy(adv_data_ptr, &ibeacon_raw_advertising_data, ibeacon_data_size);
    }
}

uint8_t ibeacon_get_adv_data_size(void){
    return ibeacon_data_size;
}


