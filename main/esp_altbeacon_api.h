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

/* For ALTBeacon packet format, please refer to https://github.com/AltBeacon/spec
 */

#define ALTBEACON_ID_LEN        16
#define ALTBEACON_EXTRA_ID_LEN  4

typedef struct {
    uint8_t flags[3];
    uint8_t length;
    uint8_t type;
    uint16_t company_id;
    uint16_t beacon_type;
    uint8_t beacon_id[ALTBEACON_ID_LEN];
    uint8_t beacon_id_extra[ALTBEACON_EXTRA_ID_LEN];
    int8_t reference_rssi;
    uint8_t mfg_reserved;
}__attribute__((packed)) esp_ble_altbeacon_t;

/**
 *  @brief  Set the parameters that AltBeacon is going to advertise.
 *          
 *  @param  id   16 byte vector in big endian representation.
 *               This id should be unique to the advertiser's organizational unit.
 *
 *  @param  id_extra  4 byte vector. May be subdivided as needed for the use case.
 *
 *  @param  ref_rssi  Representing the average received signal strength at 1m 
 *                    from the advertiser. A signed 1-byte value from 0 to -127.
 *
 *  @param  mfg_reserved  A 1-byte value from 0x00 to 0xFF. Interpretation of this 
 *                        value is to be defined by the manufacturer and is to be 
 *                        evaluated based on the MFG ID value
 *
 *  @return None.
 */
void altbeacon_config_data(uint8_t *id, uint8_t *id_extra, uint8_t ref_rssi, uint8_t mfg_reserved);

/**
 *  @brief  Copy the advertising data stored in esp_ble_altbeacon_t struct in
 *          a uint8_t vector passed by the function's user.
 *
 *  @param  adv_data_ptr  Pointer to a vector with size given by altbeacon_get_adv_data_size().
 *
 *  @return None
 */
void altbeacon_get_adv_data(uint8_t *adv_data_ptr);

/**
 *  @brief  Get size of all advertising data. 
 *          It should be used to pass the advertising data size
 *          to the ble publish function.
 *
 *  @return size of esp_ble_altbeacon_t struct
 */
uint8_t altbeacon_get_adv_data_size(void);