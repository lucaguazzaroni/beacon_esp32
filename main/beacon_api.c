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

ibeacon_t ibeacon_adv_data;

static esp_ble_scan_params_t ble_scan_params = {
    .scan_type              = BLE_SCAN_TYPE_ACTIVE,
    .own_addr_type          = BLE_ADDR_TYPE_PUBLIC,
    .scan_filter_policy     = BLE_SCAN_FILTER_ALLOW_ALL,
    .scan_interval          = DEFAULT_SCAN_INT,
    .scan_window            = DEFAULT_SCAN_WINDOW,
    .scan_duplicate         = BLE_SCAN_DUPLICATE_DISABLE
};

static esp_ble_adv_params_t ble_adv_params = {
    .adv_int_min        = DEFAULT_MIN_ADV_INT,
    .adv_int_max        = DEFAULT_MAX_ADV_INT,
    .adv_type           = ADV_TYPE_NONCONN_IND,
    .own_addr_type      = BLE_ADDR_TYPE_PUBLIC,
    .channel_map        = ADV_CHNL_ALL,
    .adv_filter_policy = ADV_FILTER_ALLOW_SCAN_ANY_CON_ANY,
};

static ibeacon_head_t iBeaconCommonHead = {
    .flags = {0x02, 0x01, 0x06},
    .length = 0x1A,
    .type = 0xFF,
    .company_id = 0x004C,
    .beacon_type = 0x1502
};

static ibeacon_vendor_t iBeaconVendorConfig = {
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

void beacon_advertiserConfig(uint8_t minInterval, uint8_t maxInterval){
    ble_adv_params.adv_int_min = minInterval;
    ble_adv_params.adv_int_max = maxInterval;
}

bool beacon_isAdvertiser(){
    if(beaconMode == BEACON_MODE_ADVERTISER){
        return true;
    } else {
        return false;
    }
}   

void beacon_scannerConfig(uint8_t scanInterval, uint8_t scanWindow){
    ble_scan_params.scan_interval = scanInterval;
    ble_scan_params.scan_window = scanWindow;
}

bool beacon_isScanner(){
    if(beaconMode == BEACON_MODE_SCANNER){
        return true;
    } else {
        return false;
    }
}   

void beacon_iBeaconDataConfig(uint8_t *uuid, uint16_t major, uint16_t minor, uint8_t txPower){
    memcpy(&iBeaconVendorConfig->proximity_uuid, uuid, sizeof(&iBeaconVendorConfig->uuid));
    iBeaconVendorConfig.major = ENDIAN_CHANGE_U16(major);
    iBeaconVendorConfig.minor = ENDIAN_CHANGE_U16(minor); 
    iBeaconVendorConfig.measured_power = txPower;

    memcpy(&ibeacon_adv_data->iBeaconHead, &iBeaconCommonHead, sizeof(ibeacon_head_t));
    memcpy(&ibeacon_adv_data->iBeaconVendor, &iBeaconVendorConfig, sizeof(ibeacon_vendor_t));
}

void beacon_getAdvData(ibeacon_t *advData){
    memcpy(advData, &ibeacon_adv_data, sizeof(ibeacon_adv_data));
}

void beacon_getAdvParams(esp_ble_adv_params_t advParams){
    memcpy(advParams, &ble_adv_params, sizeof(ble_adv_params));
}

void beacon_getScanParams(esp_ble_scan_params_t scanParams){
    memcpy(scanParams, &ble_scan_params, sizeof(ble_scan_params));
}