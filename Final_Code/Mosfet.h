/*
 * Mosfet.h
 *
 *  Created on: 15 nov. 2023
 *      Author: alexi
 */

#ifndef MOSFET_H_
#define MOSFET_H_

#include "stm32f1xx_hal.h"

#define BROCHE_Mosfet		GPIOB
#define BROCHE_Mosfet_1		GPIO_PIN_11
#define BROCHE_Mosfet_2		GPIO_PIN_10
#define BROCHE_Mosfet_3		GPIO_PIN_1
#define BROCHE_Mosfet_4		GPIO_PIN_0

void mosfet_Change(int);



#endif /* MOSFET_H_ */
