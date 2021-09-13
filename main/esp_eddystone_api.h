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

#define EDDYSTONE_UID_NAMESPACE_LEN 10
#define EDDYSTONE_UID_INSTANCE_LEN  6

typedef struct {
        uint8_t flags[3];
        uint8_t length;
        uint8_t type;
        uint16_t beacon_type;
        uint8_t frame_type;
        int8_t ranging_data;
        uint8_t id_namespace[EDDYSTONE_UID_NAMESPACE_LEN];
        uint8_t id_instance[EDDYSTONE_UID_INSTANCE_LEN];
        uint8_t rfu[4];
}__attribute__((packed)) esp_ble_eddystone_uid_t;

/**
 *  @brief  Set the parameters that eddystone UID is going to advertise.
 *          
 *  @param  id_namespace   10 byte vector. The namespace portion of the ID may be used 
 *                         to group a particular set of beacons
 *
 *  @param  id_instance  6 byte vector. the instance portion of the ID identifies 
 *                       individual devices in the group. The division of the ID into namespace 
 *                       and instance components may also be used to optimize BLE scanning strategies
 *
 *  @param  ranging_data  Tx power is the received power at 0 meters measured in dBm. 
 *                        The value may range from -100 dBm to +20 dBm at a resolution of 1 dBm.
 *
 *  @return None.
 */
void eddystone_config_data(uint8_t *id_namespace, uint8_t *id_instance, uint8_t ranging_data);

/**
 *  @brief  Copy the advertising data stored in esp_ble_eddystone_uid_t struct in
 *          a uint8_t vector passed by the function's user.
 *
 *  @param  adv_data_ptr  Pointer to a vector with size given by eddystone_get_adv_data_size().
 *
 *  @return None
 */
void eddystone_get_adv_data(uint8_t *adv_data_ptr);

/**
 *  @brief  Get size of all advertising data. 
 *          It should be used to pass the advertising data size
 *          to the ble publish function.
 *
 *  @return size of esp_ble_eddystone_uid_t struct
 */
uint8_t eddystone_get_adv_data_size(void);