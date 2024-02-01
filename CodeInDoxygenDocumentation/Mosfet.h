/*
 * Mosfet.h
 *
 *  Created on: 15 nov. 2023
 *      Author: alexi
 */

/**
 * @file Mosfet.h
 * @brief Définitions et prototypes pour le contrôle des transistors MOSFET.
 */

#ifndef MOSFET_H_
#define MOSFET_H_

#include "stm32f1xx_hal.h"

/** @defgroup Mosfet_Broches Broches des transistors MOSFET */
/** @{ */
#define BROCHE_Mosfet    GPIOB        /**< Broche du GPIO pour les transistors MOSFET */
#define BROCHE_Mosfet_1  GPIO_PIN_11  /**< Broche du transistor 1 */
#define BROCHE_Mosfet_2  GPIO_PIN_10  /**< Broche du transistor 2 */
#define BROCHE_Mosfet_3  GPIO_PIN_1   /**< Broche du transistor 3 */
#define BROCHE_Mosfet_4  GPIO_PIN_0   /**< Broche du transistor 4 */
/** @} */

/**
 * @brief Change l'état des transistors MOSFET en fonction du chiffre fourni.
 *
 * @param[in] chiffre - Le chiffre correspondant à l'état souhaité.
 *                      0: Transistor 1 allumé, les autres éteints.
 *                      1: Transistor 2 allumé, les autres éteints.
 *                      2: Transistor 3 allumé, les autres éteints.
 *                      3: Transistor 4 allumé, les autres éteints.
 *                      Les autres chiffres sont ignorés.
 */
void mosfet_Change(int chiffre);

#endif /* MOSFET_H_ */
