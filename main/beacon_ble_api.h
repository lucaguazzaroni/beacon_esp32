#include <stdint.h>
#include <string.h>
#include <stdbool.h>
#include <stdio.h>

#define BEACON_MODE_ADVERTISER 0
#define BEACON_MODE_SCANNER    1

#define BEACON_TYPE_ALTBEACON 2
#define BEACON_TYPE_IBEACON	  3	

/**
 */
void beacon_ble_init(void);

/**
 */
void beacon_ble_config(uint8_t beacon_mode, uint8_t beacon_type);

/**
 */
void beacon_advertiser_config(uint8_t adv_int_min, uint8_t adv_int_max);

/**
 */
uint8_t beacon_is_advertiser(void);

/**
 */
void beacon_advertiser_start(uint8_t *raw_advertising_data);

/**
 */
void beacon_scanner_config(uint8_t scan_window, uint8_t scan_interval);

/**
 */
uint8_t beacon_is_scanner(void);

/**
 */
void beacon_scanner_start(void);