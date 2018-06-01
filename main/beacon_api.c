#include <stdint.h>
#include <string.h>
#include <stdbool.h>
#include <stdio.h>

#include "esp_gap_ble_api.h"
#include "esp_ibeacon_api.h"

/**********************************************************************
 *                    Private variables
 **********************************************************************/
uint8_t beaconMode = BEACON_MODE_ADVERTISER;
uint8_t beaconType = BEACON_TYPE_ALTBEACON;

ibeacon_head_t iBeaconCommonHead = {
    .flags = {0x02, 0x01, 0x06},
    .length = 0x1A,
    .type = 0xFF,
    .company_id = 0x004C,
    .beacon_type = 0x1502
};

ibeacon_vendor_t iBeaconVendorConfig = {
    .proximity_uuid = DEFAULT_UUID,
    .major = ENDIAN_CHANGE_U16(DEFAULT_MAJOR), 
    .minor = ENDIAN_CHANGE_U16(DEFAULT_MINOR), 
    .measured_power = DEFAULT_TX_POWER
};


/**********************************************************************
 *                    Public functions
 **********************************************************************/
void beacon_config(uint8_t mode, uint8_t type){
    if( (mode >= BEACON_MODE_ADVERTISER) && (mode <= BEACON_MODE_SCANNER) ){
        beaconMode = mode;
    }
    if( (type >= BEACON_TYPE_ALTBEACON) && (type <= BEACON_TYPE_EDDYSTONE_TLM) ){
        beaconType = type;
    }
}

bool beacon_isAdvertiser(){
    if(beaconMode == BEACON_MODE_ADVERTISER){
        return true;
    } else {
        return false;
    }
}   

bool beacon_isScanner(){
    if(beaconMode == BEACON_MODE_SCANNER){
        return true;
    } else {
        return false;
    }
}   

