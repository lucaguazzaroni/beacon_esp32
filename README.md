# beacon with esp32
This repo shows how to program ESP32 to work as iBeacon, AltBeacon and Eddystone uid.
The configuration is done in compile time. Update parameters such as the beacon type or beacon specific data such as uuid through
BLE or UART are not supported yet.

## Apis
It consist in four Api's:
* beacon_ble_api:
Contains methods to start publishing ble network and configure the raw data to publish.
* esp_altbeacon_api:
You can configure uuid, extra uuid, reference rssi and extra manufacturer data from altbeacon specification 
*  esp_ibeacon_api:
You can configure uuid, mayor value, minor value and measured rssi.
*  esp_eddystone_api:
  ** eddystone_uid: You can configure id namespace, id instance and tx power at 0m.

## References
* Altbeacon specification: https://github.com/AltBeacon/spec
* iBeacon specification: https://developer.apple.com/ibeacon/
* Eddystone specification: https://github.com/google/eddystone/blob/master/protocol-specification.md
* Eddystone uid specification: https://github.com/google/eddystone/tree/master/eddystone-uid
* ESP32 enviroment configuration: https://esp-idf.readthedocs.io/en/latest/get-started/index.html
* ESP32 api reference: https://esp-idf.readthedocs.io/en/latest/api-reference/index.html
* ESP32 how to document: https://esp-idf.readthedocs.io/en/v1.0/documenting-code.html
