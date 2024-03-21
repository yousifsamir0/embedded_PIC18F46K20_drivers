/* 
 * File:   std_types.h
 * Author: Joe
 *
 * Created on February 4, 2024, 1:01 AM
 */

#ifndef STD_TYPES_H
#define	STD_TYPES_H

/* section: Includes */
#include "compiler.h"
#include "std_libraries.h"

/*section: data types declaration*/
typedef uint8_t Std_ReturnType;
/* section: macros definition */
#define STD_ONE         (uint8_t)1
#define STD_ZERO        (uint8_t)0

#define E_OK            (Std_ReturnType)0
#define E_NOT_OK        (Std_ReturnType)1


#endif	/* STD_TYPES_H */

