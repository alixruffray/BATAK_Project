/*
 * Conf_Aff_Sept_Segg.h
 *
 *  Created on: 8 nov. 2023
 *      Author: alexi
 */

#ifndef AFFICHEUR_SEPT_SEG_H_
#define AFFICHEUR_SEPT_SEG_H_

#include "stm32f1xx_hal.h"

#define BROCHE_DRIVER_7_SEGMENTS		GPIOB
#define BROCHE_DRIVER_SEGMENTS_1		GPIO_PIN_6
#define BROCHE_DRIVER_SEGMENTS_2		GPIO_PIN_9
#define BROCHE_DRIVER_SEGMENTS_3		GPIO_PIN_8
#define BROCHE_DRIVER_SEGMENTS_4		GPIO_PIN_7


void afficher_7_seg(int);


#endif /* AFFICHEUR_SEPT_SEG_H_ */
