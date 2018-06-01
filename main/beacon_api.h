#include <stdint.h>
#include <string.h>
#include <stdbool.h>
#include <stdio.h>

#include "esp_gap_ble_api.h"
#include "esp_gattc_api.h"


/* Because current ESP IDF version doesn't support scan and adv simultaneously,
 * so iBeacon sender and receiver should not run simultaneously */
#define BEACON_MODE_ADVERTISER      0
#define BEACON_MODE_SCANNER         1
/* Beacons types supported */
#define BEACON_TYPE_ALTBEACON       2
#define BEACON_TYPE_IBEACON         3
#define BEACON_TYPE_EDDYSTONE_UUID  4
#define BEACON_TYPE_EDDYSTONE_URL   5
#define BEACON_TYPE_EDDYSTONE_TLM   6

/* Major and Minor part are stored in big endian mode in iBeacon packet,
 * need to use this macro to transfer while creating or processing
 * iBeacon data */
#define ENDIAN_CHANGE_U16(x) ((((x)&0xFF00)>>8) + (((x)&0xFF)<<8))

/* Default Values */
#define DEFAULT_UUID    {0xFD, 0xA5, 0x06, 0x93, 0xA4, 0xE2, 0x4F, 0xB1, 0xAF, 0xCF, 0xC6, 0xEB, 0x11, 0x11, 0x11, 0x11}
#define DEFAULT_MAJOR   1000
#define DEFAULT_MINOR   1001
#define DEFAULT_TX_POWER 0xC5

#define DEFAULT_MIN_ADV_INT 0x20
#define DEFAULT_MAX_ADV_INT 0x40
#define DEFAULT_SCAN_INT    0x50
#define DEFAULT_SCAN_WINDOW 0x30


typedef struct {
    uint8_t flags[3];
    uint8_t length;
    uint8_t type;
    uint16_t company_id;
    uint16_t beacon_type;
}__attribute__((packed)) ibeacon_head_t;

typedef struct {
    uint8_t proximity_uuid[16];
    uint16_t major;
    uint16_t minor;
    int8_t measured_power;
}__attribute__((packed)) ibeacon_vendor_t;


typedef struct {
    ibeacon_head_t   iBeaconHead;
    ibeacon_vendor_t iBeaconVendor;
}__attribute__((packed)) ibeacon_t;


/**
 * @brief Set Beacons variables to work as a advertiser or scanner
 *        In the case of advertiser it can be set to publish as  
 *        ATLBeacon, iBeacon or Eddystone.
 * @param  mode: 
 * @param 
 * @return
 */
bool beacon_config(uint8_t mode, uint8_t type);

/**
 * @brief 
 * @param
 * @return
 */
void beacon_advertiserConfig(uint8_t minInterval, uint8_t maxInterval);

/**
 * @brief 
 * @param
 * @return
 */
void beacon_iBeaconDataConfig(uint8_t *uuid, uint16_t major, uint16_t minor, uint8_t txPower);

/**
 * @brief 
 * @param
 * @return
 */
bool beacon_isAdvertiser();

/**
 * @brief 
 * @param
 * @return
 */
bool beacon_isScanner();

/**
 * @brief 
 * @param
 * @return
 */
void beacon_scannerConfig(uint8_t scanInterval, uint8_t scanWindow);

/**
 * @brief 
 * @param
 * @return
 */
void beacon_getAdvData(ibeacon_t *advData);

/**
 * @brief 
 * @param
 * @return
 */
void beacon_getAdvParams(esp_ble_adv_params_t advParams);

/**
 * @brief 
 * @param
 * @return
 */
void beacon_getScanParams(esp_ble_scan_params_t scanParams);



