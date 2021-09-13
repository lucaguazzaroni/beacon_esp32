#include <stdint.h>
#include <string.h>
#include <stdbool.h>
#include <stdio.h>


#define BEACON_TYPE_ALTBEACON 2
#define BEACON_TYPE_IBEACON	  3	
#define BEACON_TYPE_EDDYSTONE_UUID 4

/**
 *	@brief	Init esp32's ble controller and register callbacks functions
 *			that manage bluetooth events.
 *
 *	@return None
 */
void beacon_ble_init(void);

/**
 *	@brief	Set the work mode.
 *
 *	@param  beacon_type: to set beacon as eddystone, altbeacon or ibeacon
 *
 *	@return None
 */
void beacon_ble_config(uint8_t beacon_type);

/**
 *	@brief	get what beacon type that is configured.
 *
 *	@return BEACON_TYPE_ALTBEACON 
 *	@return BEACON_TYPE_IBEACON
 *  @return BEACON_TYPE_EDDYSTONE_UUID
 */
uint8_t beacon_get_type(void);

/**
 *	@brief	When beacon is advertising, set the min amd max advertising interval.
 *
 *	@param	adv_int_min 	Minimun advertising interval.
 *	@param 	adv_int_max		Max advertising interval.
 *
 *	@return None
 */
void beacon_advertiser_config(uint8_t adv_int_min, uint8_t adv_int_max);

/**
 *	@brief	Make the abeacon start advertising.
 *
 *	@param 	raw_adv_data 		vector with data thas has to be advertised.
 *	@param	raw_adv_data_size 	raw_adv_data's size
 *
 *	@return None.
 */
void beacon_advertiser_start(uint8_t *raw_adv_data, uint8_t raw_adv_data_size);
