/*
 * Registre_Decalage_LED.h
 *
 *  Created on: 6 déc. 2023
 *      Author: alexi
 */

/**
 * @file Registre_Decalage_LED.h
 * @brief Déclaration des fonctions pour le registre à décalage des LEDs.
 */

#ifndef REGISTRE_DECALAGE_LED_H_
#define REGISTRE_DECALAGE_LED_H_

#include "stm32f1xx_hal.h"

/**
 * @brief Structure des broches pour le registre à décalage des LEDs.
 */
#define BROCHE_Registre_LED     GPIOA
#define BROCHE_CLK              GPIO_PIN_11
#define BROCHE_Registre_LED_1   GPIO_PIN_10

/**
 * @brief Fonction pour effectuer un décalage aléatoire des LEDs.
 *
 * @param[in] chiffre - Le nombre de décalages.
 */
void randomDeLED(int chiffre);

#endif /* REGISTRE_DECALAGE_LED_H_ */

