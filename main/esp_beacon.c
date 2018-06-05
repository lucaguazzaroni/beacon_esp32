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
#include "nvs_flash.h"

#include "esp_bt.h"
#include "esp_gap_ble_api.h"
#include "esp_gattc_api.h"
#include "esp_gatt_defs.h"
#include "esp_bt_main.h"
#include "esp_bt_defs.h"
#include "esp_log.h"
#include "freertos/FreeRTOS.h"

#include "beacon_ble_api.h"
#include "esp_altbeacon_api.h"

uint8_t test_uuid[] = {0xFD, 0xA5, 0x06, 0x93, 0xA4, 0xE2, 0x4F, 0xB1, 0xAF, 0xCF, 0xC6, 0xEB, 0x22, 0x22, 0x22, 0x22};
uint8_t test_uuid_extra[] = {0x11,0x11,0x00,0x00};

void app_main()
{
    ESP_ERROR_CHECK(nvs_flash_init());

    beacon_ble_init();
    beacon_ble_config(BEACON_MODE_ADVERTISER, BEACON_TYPE_ALTBEACON);
    beacon_advertiser_config(0x20, 0x40);
    

    /* set scan parameters */
    if( beacon_is_scanner() ){
        beacon_scanner_start();
    }

    /* set advertising data */
    if( beacon_is_advertiser() ){
        altbeacon_config_data(test_uuid, test_uuid_extra, 0xC3, 0x33);
        beacon_advertiser_start( altbeacon_get_adv_data() );
    }
    
}

