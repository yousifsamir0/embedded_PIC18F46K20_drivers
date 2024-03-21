/* 
 * File:   hal_eeprom.h
 * Author: Joe
 *
 * Created on February 29, 2024, 11:32 PM
 */

#ifndef HAL_EEPROM_H
#define	HAL_EEPROM_H

/* section: Includes */
#include "../mcal_std_types.h"
#include "../device_config.h"

/*section: macro declaration*/

        
/* section: macro function declarations */

/* section: data types declaration*/

/*section: functions declaration*/
Std_ReturnType eeprom_write_byte(uint16_t addr, uint8_t data);
Std_ReturnType eeprom_read_byte(uint16_t addr, uint8_t *data);


#endif	/* HAL_EEPROM_H */

