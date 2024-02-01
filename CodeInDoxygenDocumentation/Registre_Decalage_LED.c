/*
 * Registre_Decalage_LED.c
 *
 *  Created on: 6 d�c. 2023
 *      Author: alexi
 */

/**
 * @file Registre_Decalage_LED.c
 * @brief Impl�mentation des fonctions pour le registre � d�calage des LEDs.
 */

#include "Registre_Decalage_LED.h"

/**
 * @brief Effectue un d�calage al�atoire des LEDs.
 *
 * @param[in] chiffre - Le nombre de d�calages.
 */
void randomDeLED(int chiffre) {
    // R�initialise les LEDs
    for (int supp = 0; supp < 13; supp++) {
        HAL_GPIO_WritePin(BROCHE_Registre_LED, BROCHE_CLK, 1);
        HAL_GPIO_WritePin(BROCHE_Registre_LED, BROCHE_CLK, 0);
    }

    // Active le premier bit du registre
    HAL_GPIO_WritePin(BROCHE_Registre_LED, BROCHE_Registre_LED_1, 1);
    HAL_GPIO_WritePin(BROCHE_Registre_LED, BROCHE_CLK, 1);
    HAL_GPIO_WritePin(BROCHE_Registre_LED, BROCHE_CLK, 0);
    HAL_GPIO_WritePin(BROCHE_Registre_LED, BROCHE_Registre_LED_1, 0);

    // Effectue les d�calages n�cessaires
    for (int i = 0; i < (chiffre + 1); i++) {
        HAL_GPIO_WritePin(BROCHE_Registre_LED, BROCHE_CLK, 1);
        HAL_GPIO_WritePin(BROCHE_Registre_LED, BROCHE_CLK, 0);
    }
}
