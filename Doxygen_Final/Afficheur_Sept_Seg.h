/*
 * Afficheur_Sept_Seg.h
 *
 *  Created on: 8 nov. 2023
 *      Author: alexi
 */

#ifndef AFFICHEUR_SEPT_SEG_H_
#define AFFICHEUR_SEPT_SEG_H_

#include "stm32f1xx_hal.h"

/**
 * @defgroup Afficheur_Sept_Seg Afficheur Sept Segments
 * @brief Fonctions pour contrôler un afficheur à sept segments.
 * @{
 */

/**
 * @brief Broches de l'afficheur à sept segments.
 */
#define BROCHE_DRIVER_7_SEGMENTS		GPIOB
#define BROCHE_DRIVER_SEGMENTS_1		GPIO_PIN_6
#define BROCHE_DRIVER_SEGMENTS_2		GPIO_PIN_9
#define BROCHE_DRIVER_SEGMENTS_3		GPIO_PIN_8
#define BROCHE_DRIVER_SEGMENTS_4		GPIO_PIN_7

/**
 * @brief Affiche un chiffre sur l'afficheur à sept segments.
 *
 * @param chiffre Le chiffre à afficher (de 0 à 9).
 */
void afficher_7_seg(int chiffre);

/** @} */

#endif /* AFFICHEUR_SEPT_SEG_H_ */

