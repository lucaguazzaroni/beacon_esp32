# beacon with esp32
This repo shows how to program ESP32 to work as iBeacon and AltBeacon. Eddystone is not supported yet.

It consist in three Api's:
*  ###beacon_ble_api:
Contains methods to start publishing ble network and configure the raw data to publish.
*  ###esp_altbeacon_api:
You can configure uuid, extra uuid, reference rssi and extra manufacturer data from altbeacon specification (https://github.com/AltBeacon/spec)
*  ###esp_ibeacon_api:

for documentation see https://esp-idf.readthedocs.io/en/v1.0/documenting-code.html
