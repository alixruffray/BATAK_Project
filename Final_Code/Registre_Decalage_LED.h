/*
 * Registre_Decalage_LED.h
 *
 *  Created on: 6 déc. 2023
 *      Author: alexi
 */

#ifndef REGISTRE_DECALAGE_LED_H_
#define REGISTRE_DECALAGE_LED_H_

#include "stm32f1xx_hal.h"

#define BROCHE_Registre_LED		GPIOA
#define BROCHE_CLK				GPIO_PIN_11
#define BROCHE_Registre_LED_1	GPIO_PIN_10

void randomDeLED(int);

#endif /* REGISTRE_DECALAGE_LED_H_ */
