/*
 * N_12_Bouton.h
 *
 *  Created on: 20 déc. 2023
 *      Author: alexi
 */

#ifndef N_12_BOUTON_H_
#define N_12_BOUTON_H_

#include "stm32f1xx_hal.h"

#define Bouton_A	GPIOA
#define Bouton_B	GPIOB
#define Bouton_1 	GPIO_PIN_7
#define Bouton_2 	GPIO_PIN_6
#define Bouton_3 	GPIO_PIN_5
#define Bouton_4 	GPIO_PIN_4
#define Bouton_5 	GPIO_PIN_3
#define Bouton_6 	GPIO_PIN_2
#define Bouton_7 	GPIO_PIN_1
#define Bouton_8 	GPIO_PIN_0
#define Bouton_9 	GPIO_PIN_12
#define Bouton_10 	GPIO_PIN_13
#define Bouton_11 	GPIO_PIN_14
#define Bouton_12 	GPIO_PIN_15

int Bouton_Valide(int);

#endif /* N_12_BOUTON_H_ */
