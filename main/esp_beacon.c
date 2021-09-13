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
#include "freertos/FreeRTOS.h"
#include "esp_log.h"

#include "beacon_ble_api.h"
#include "esp_altbeacon_api.h"
#include "esp_eddystone_api.h"
#include "esp_ibeacon_api.h"

static const char* TAG = "MAIN";

uint8_t test_uuid[] = {0xFD, 0xA5, 0x06, 0x93, 0xA4, 0xE2, 0x4F, 0xB1, 0xAF, 0xCF, 0xC6, 0xEB, 0x22, 0x22, 0x22, 0x22};
uint8_t test_uuid_extra[] = {0x11,0x11,0x00,0x00};

uint8_t test_namespace[] = {0xFD, 0x11, 0x22, 0x33, 0x44, 0x55, 0x66, 0x77, 0x88, 0x99};
uint8_t test_instance[] = {0x10, 0x20, 0x30, 0x10, 0x20, 0x30};

void app_main()
{
    ESP_ERROR_CHECK(nvs_flash_init());

    /* Init ESP32's bluetooth hardware */
    beacon_ble_init();

    /* Config beacon_ble_api to work as an advertiser */
    beacon_ble_config(BEACON_MODE_ADVERTISER, BEACON_TYPE_EDDYSTONE_UUID);
    
    uint8_t *advertising_packet = NULL;     
    uint8_t advertising_packet_size = 0;  

    /* set advertising data */
    beacon_advertiser_config(0x60, 0x80);

    switch( beacon_get_type() )
    {
        case BEACON_TYPE_ALTBEACON:
            // if altbeacon_config_data is not called, default values are going to be published when beacon_advertiser_start() is called
            altbeacon_config_data(test_uuid, test_uuid_extra, 0xC3, 0x33); 
            // get size of adv data
            advertising_packet_size = altbeacon_get_adv_data_size(); 
            // create array to store the advertising data
            advertising_packet = (uint8_t *)malloc(advertising_packet_size); 
            // get advertising data from altbeacon_api 
            altbeacon_get_adv_data(advertising_packet);
            break;
        case BEACON_TYPE_IBEACON:
            // if altbeacon_config_data is not called, default values are going to be published when beacon_advertiser_start() is called
            ibeacon_config_data(test_uuid, 2000, 2003, 0xC3); 
            // get size of adv data
            advertising_packet_size = ibeacon_get_adv_data_size();  
            // create array to store the advertising data
            advertising_packet = (uint8_t *)malloc(advertising_packet_size); 
            // get advertising data from altbeacon_api 
            ibeacon_get_adv_data(advertising_packet); 
            break;
        case BEACON_TYPE_EDDYSTONE_UUID:
            // if eddystone_config_data is not called, default values are going to be published when beacon_advertiser_start() is called
            eddystone_config_data(test_namespace, test_instance, 0xC3); 
            // get size of adv data
            advertising_packet_size = eddystone_get_adv_data_size(); 
            // create array to store the advertising data
            advertising_packet = (uint8_t *)malloc(advertising_packet_size); 
            // get advertising data from altbeacon_api 
            eddystone_get_adv_data(advertising_packet);
            break;
        default:
            break;
    } 
    
    // give to beacon_ble_api data to advertise
    beacon_advertiser_start(advertising_packet, advertising_packet_size);     
}

