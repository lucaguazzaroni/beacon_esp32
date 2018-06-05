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

#include "esp_altbeacon_api.h"

extern esp_ble_altbeacon_vendor_t vendor_config;

void app_main()
{
    ESP_ERROR_CHECK(nvs_flash_init());

    beacon_ble_init();

    /* set scan parameters */
    if( beacon_is_scanner() ){
        beacon_scanner_start();
    }

    /* set advertising data */
    if( beacon_is_advertiser() ){
        esp_ble_altbeacon_t altbeacon_adv_data;

        /*Here configure alt beacon, ibeacon, etc info*/

        //beacon_advertiser_start( altbeacon_get_adv_data() );

        /*esp_err_t status = esp_ble_config_altbeacon_data (&vendor_config, &altbeacon_adv_data);
        if (status == ESP_OK){
            esp_ble_gap_config_adv_data_raw((uint8_t*)&altbeacon_adv_data, sizeof(altbeacon_adv_data));
        }
        else {
            ESP_LOGE(DEMO_TAG, "Config altBeacon data failed: %s\n", esp_err_to_name(status));
        }*/
    }
    
}

