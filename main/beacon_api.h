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

#define BEACON_TYPE_ALTBEACON       2
#define BEACON_TYPE_IBEACON         3
#define BEACON_TYPE_EDDYSTONE_UUID  4
#define BEACON_TYPE_EDDYSTONE_URL   5
#define BEACON_TYPE_EDDYSTONE_TLM   6

/* Major and Minor part are stored in big endian mode in iBeacon packet,
 * need to use this macro to transfer while creating or processing
 * iBeacon data */
#define ENDIAN_CHANGE_U16(x) ((((x)&0xFF00)>>8) + (((x)&0xFF)<<8))

/* Espressif WeChat official account can be found using WeChat "Yao Yi Yao Zhou Bian", 
 * if device advertises using ESP defined UUID. 
 * Please refer to http://zb.weixin.qq.com for further information. */
#define DEFAULT_UUID    {0xFD, 0xA5, 0x06, 0x93, 0xA4, 0xE2, 0x4F, 0xB1, 0xAF, 0xCF, 0xC6, 0xEB, 0x11, 0x11, 0x11, 0x11}
#define DEFAULT_MAJOR   1000
#define DEFAULT_MINOR   1001
#define DEFAULT_TX_POWER 0xC5


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
}__attribute__((packed)) beacon_t;


/**************************************************** 
 *
 ****************************************************/
bool beacon_isAdvertiser();

/**************************************************** 
 *
 ****************************************************/
bool beacon_isScanner();

/**************************************************** 
 *
 ****************************************************/
bool beacon_config(uint8_t mode, uint8_t type);

/**************************************************** 
 *
 ****************************************************/
bool beacon_AdvertiseConfig(uint16_t minInterval, uint16_t maxInterval);

/**************************************************** 
 *
 ****************************************************/
bool beacon_ScanConfig(uint8_t mode, uint8_t type);


