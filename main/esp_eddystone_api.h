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


typedef struct {
        uint8_t flags[3];
        uint8_t length;
        uint8_t type;
        uint16_t beacon_type;
        uint8_t frame_type;
        int8_t ranging_data;
        uint8_t id_namespace[10];
        uint8_t id_instance[6];
        uint8_t rfu[4];
}__attribute__((packed)) esp_ble_eddystone_uuid_t;


/**
 */
void eddystone_config_data(uint8_t *id_namespace, uint8_t *id_instance, uint8_t ranging_data);

/**
 */
void eddystone_get_adv_data(uint8_t *adv_data_ptr);

/**
 */
uint8_t eddystone_get_adv_data_size(void);