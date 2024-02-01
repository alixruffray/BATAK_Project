/*
 * N_12_Bouton.h
 *
 *  Created on: 20 déc. 2023
 *      Author: alexi
 */

/**
 * @file N_12_Bouton.h
 * @brief Définitions et prototypes pour la gestion des boutons N-12.
 */

#ifndef N_12_BOUTON_H_
#define N_12_BOUTON_H_

#include "stm32f1xx_hal.h"

/** @defgroup Bouton_Broches Broches des boutons N-12 */
/** @{ */
#define Bouton_A    GPIOA      /**< Broche du GPIO A pour les boutons N-12 */
#define Bouton_B    GPIOB      /**< Broche du GPIO B pour les boutons N-12 */
#define Bouton_1    GPIO_PIN_7 /**< Broche du bouton 1 */
#define Bouton_2    GPIO_PIN_6 /**< Broche du bouton 2 */
#define Bouton_3    GPIO_PIN_5 /**< Broche du bouton 3 */
#define Bouton_4    GPIO_PIN_4 /**< Broche du bouton 4 */
#define Bouton_5    GPIO_PIN_3 /**< Broche du bouton 5 */
#define Bouton_6    GPIO_PIN_2 /**< Broche du bouton 6 */
#define Bouton_7    GPIO_PIN_1 /**< Broche du bouton 7 */
#define Bouton_8    GPIO_PIN_0 /**< Broche du bouton 8 */
#define Bouton_9    GPIO_PIN_12 /**< Broche du bouton 9 */
#define Bouton_10   GPIO_PIN_13 /**< Broche du bouton 10 */
#define Bouton_11   GPIO_PIN_14 /**< Broche du bouton 11 */
#define Bouton_12   GPIO_PIN_15 /**< Broche du bouton 12 */
/** @} */

/**
 * @brief Vérifie si le bouton correspondant à la valeur 'ou' est pressé.
 *
 * @param[in] ou - La valeur du bouton à vérifier (de 0 à 11).
 * @return 1 si le bouton est pressé, 0 sinon.
 */
int Bouton_Valide(int ou);

#endif /* N_12_BOUTON_H_ */
