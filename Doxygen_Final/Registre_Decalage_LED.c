/*
 * Registre_Decalage_LED.c
 *
 *  Created on: 6 déc. 2023
 *      Author: alexi
 */

/**
 * @file Registre_Decalage_LED.c
 * @brief Implémentation des fonctions pour le registre à décalage des LEDs.
 */

#include "Registre_Decalage_LED.h"

/**
 * @brief Effectue un décalage aléatoire des LEDs.
 *
 * @param[in] chiffre - Le nombre de décalages.
 */
void randomDeLED(int chiffre) {
    // Réinitialise les LEDs
    for (int supp = 0; supp < 13; supp++) {
        HAL_GPIO_WritePin(BROCHE_Registre_LED, BROCHE_CLK, 1);
        HAL_GPIO_WritePin(BROCHE_Registre_LED, BROCHE_CLK, 0);
    }

    // Active le premier bit du registre
    HAL_GPIO_WritePin(BROCHE_Registre_LED, BROCHE_Registre_LED_1, 1);
    HAL_GPIO_WritePin(BROCHE_Registre_LED, BROCHE_CLK, 1);
    HAL_GPIO_WritePin(BROCHE_Registre_LED, BROCHE_CLK, 0);
    HAL_GPIO_WritePin(BROCHE_Registre_LED, BROCHE_Registre_LED_1, 0);

    // Effectue les décalages nécessaires
    for (int i = 0; i < (chiffre + 1); i++) {
        HAL_GPIO_WritePin(BROCHE_Registre_LED, BROCHE_CLK, 1);
        HAL_GPIO_WritePin(BROCHE_Registre_LED, BROCHE_CLK, 0);
    }
}
