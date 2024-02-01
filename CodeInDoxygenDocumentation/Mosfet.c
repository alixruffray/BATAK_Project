/*
 * Mosfet.c
 *
 *  Created on: 15 nov. 2023
 *      Author: alexi & alix
 */

/**
 * @file Mosfet.c
 * @brief Fonctions de contrôle des transistors MOSFET.
 */

#include "Mosfet.h"

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
void mosfet_Change(int chiffre) {
    switch (chiffre) {
        case 0:
            // Allume le transistor 1, éteint les autres
            HAL_GPIO_WritePin(BROCHE_Mosfet, BROCHE_Mosfet_1, GPIO_PIN_SET);
            HAL_GPIO_WritePin(BROCHE_Mosfet, BROCHE_Mosfet_2, GPIO_PIN_RESET);
            HAL_GPIO_WritePin(BROCHE_Mosfet, BROCHE_Mosfet_3, GPIO_PIN_RESET);
            HAL_GPIO_WritePin(BROCHE_Mosfet, BROCHE_Mosfet_4, GPIO_PIN_RESET);
            break;
        case 1:
            // Allume le transistor 2, éteint les autres
            HAL_GPIO_WritePin(BROCHE_Mosfet, BROCHE_Mosfet_1, GPIO_PIN_RESET);
            HAL_GPIO_WritePin(BROCHE_Mosfet, BROCHE_Mosfet_2, GPIO_PIN_SET);
            HAL_GPIO_WritePin(BROCHE_Mosfet, BROCHE_Mosfet_3, GPIO_PIN_RESET);
            HAL_GPIO_WritePin(BROCHE_Mosfet, BROCHE_Mosfet_4, GPIO_PIN_RESET);
            break;
        case 2:
            // Allume le transistor 3, éteint les autres
            HAL_GPIO_WritePin(BROCHE_Mosfet, BROCHE_Mosfet_1, GPIO_PIN_RESET);
            HAL_GPIO_WritePin(BROCHE_Mosfet, BROCHE_Mosfet_2, GPIO_PIN_RESET);
            HAL_GPIO_WritePin(BROCHE_Mosfet, BROCHE_Mosfet_3, GPIO_PIN_SET);
            HAL_GPIO_WritePin(BROCHE_Mosfet, BROCHE_Mosfet_4, GPIO_PIN_RESET);
            break;
        case 3:
            // Allume le transistor 4, éteint les autres
            HAL_GPIO_WritePin(BROCHE_Mosfet, BROCHE_Mosfet_1, GPIO_PIN_RESET);
            HAL_GPIO_WritePin(BROCHE_Mosfet, BROCHE_Mosfet_2, GPIO_PIN_RESET);
            HAL_GPIO_WritePin(BROCHE_Mosfet, BROCHE_Mosfet_3, GPIO_PIN_RESET);
            HAL_GPIO_WritePin(BROCHE_Mosfet, BROCHE_Mosfet_4, GPIO_PIN_SET);
            break;
        default:
            // Gérer d'autres chiffres ou afficher une erreur si nécessaire
            break;
    }
}
