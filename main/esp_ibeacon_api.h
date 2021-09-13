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

#define IBEACON_UUID_LEN     16

typedef struct {
    uint8_t flags[3];
    uint8_t length;
    uint8_t type;
    uint16_t company_id;
    uint16_t beacon_type;
    uint8_t uuid[IBEACON_UUID_LEN];
    uint16_t major;
    uint16_t minor;
    int8_t measured_power;;
}__attribute__((packed)) esp_ble_ibeacon_t;

/**
 *  @brief  Set the parameters that Ibeacon is going to advertise.
 *          
 *  @param  uuid   Pointer to a 16 uint8_t vector. This uuid is used to
 *                 identify a group of ibeacons from other group.
 *
 *  @param  major  For example, is used to define a sub-region of the group
 *                 defined by the uuid. Is stored in big endian mode.
 *
 *  @param  minor  For example, is used to define a subdivision of the region
 *                 defined by param mayor. Is stored in big endian mode.
 *
 *  @param  measured_power  iBeacon signal power measured at 1 meter (Calibrated RSSI@1m).
 *
 *  @return None.
 */
void ibeacon_config_data(uint8_t *uuid, uint16_t major, uint16_t minor, int8_t measured_power);

/**
 *  @brief  Copy the advertising data stored in esp_ble_ibeacon_t struct in
 *          a uint8_t vector passed by the function's user.
 *
 *  @param  adv_data_ptr  Pointer to a vector with size given by ibeacon_get_adv_data_size().
 *
 *  @return None
 */
void ibeacon_get_adv_data(uint8_t *adv_data_ptr);

/**
 *  @brief  Get size of all advertising data. 
 *          It should be used to pass the advertising data size
 *          to the ble publish function.
 *
 *  @return size of esp_ble_ibeacon_t struct
 */
uint8_t ibeacon_get_adv_data_size(void);