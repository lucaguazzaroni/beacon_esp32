deps_config := \
	/c/Users/pasante/Documents/ESP32/esp-idf/components/app_trace/Kconfig \
	/c/Users/pasante/Documents/ESP32/esp-idf/components/aws_iot/Kconfig \
	/c/Users/pasante/Documents/ESP32/esp-idf/components/bt/Kconfig \
	/c/Users/pasante/Documents/ESP32/esp-idf/components/driver/Kconfig \
	/c/Users/pasante/Documents/ESP32/esp-idf/components/esp32/Kconfig \
	/c/Users/pasante/Documents/ESP32/esp-idf/components/esp_adc_cal/Kconfig \
	/c/Users/pasante/Documents/ESP32/esp-idf/components/esp_http_client/Kconfig \
	/c/Users/pasante/Documents/ESP32/esp-idf/components/ethernet/Kconfig \
	/c/Users/pasante/Documents/ESP32/esp-idf/components/fatfs/Kconfig \
	/c/Users/pasante/Documents/ESP32/esp-idf/components/freertos/Kconfig \
	/c/Users/pasante/Documents/ESP32/esp-idf/components/heap/Kconfig \
	/c/Users/pasante/Documents/ESP32/esp-idf/components/libsodium/Kconfig \
	/c/Users/pasante/Documents/ESP32/esp-idf/components/log/Kconfig \
	/c/Users/pasante/Documents/ESP32/esp-idf/components/lwip/Kconfig \
	/c/Users/pasante/Documents/ESP32/esp-idf/components/mbedtls/Kconfig \
	/c/Users/pasante/Documents/ESP32/esp-idf/components/openssl/Kconfig \
	/c/Users/pasante/Documents/ESP32/esp-idf/components/pthread/Kconfig \
	/c/Users/pasante/Documents/ESP32/esp-idf/components/spi_flash/Kconfig \
	/c/Users/pasante/Documents/ESP32/esp-idf/components/spiffs/Kconfig \
	/c/Users/pasante/Documents/ESP32/esp-idf/components/tcpip_adapter/Kconfig \
	/c/Users/pasante/Documents/ESP32/esp-idf/components/wear_levelling/Kconfig \
	/c/Users/pasante/Documents/ESP32/esp-idf/components/bootloader/Kconfig.projbuild \
	/c/Users/pasante/Documents/ESP32/esp-idf/components/esptool_py/Kconfig.projbuild \
	/c/Users/pasante/Documents/ESP32/esp-idf/components/partition_table/Kconfig.projbuild \
	/c/Users/pasante/Documents/ESP32/esp-idf/Kconfig

include/config/auto.conf: \
	$(deps_config)


$(deps_config): ;
