/*
 * Mosfet.c
 *
 *  Created on: 15 nov. 2023
 *      Author: alexi & alix
 */

/**
 * @file Mosfet.c
 * @brief Fonctions de contr�le des transistors MOSFET.
 */

#include "Mosfet.h"

/**
 * @brief Change l'�tat des transistors MOSFET en fonction du chiffre fourni.
 *
 * @param[in] chiffre - Le chiffre correspondant � l'�tat souhait�.
 *                      0: Transistor 1 allum�, les autres �teints.
 *                      1: Transistor 2 allum�, les autres �teints.
 *                      2: Transistor 3 allum�, les autres �teints.
 *                      3: Transistor 4 allum�, les autres �teints.
 *                      Les autres chiffres sont ignor�s.
 */
void mosfet_Change(int chiffre) {
    switch (chiffre) {
        case 0:
            // Allume le transistor 1, �teint les autres
            HAL_GPIO_WritePin(BROCHE_Mosfet, BROCHE_Mosfet_1, GPIO_PIN_SET);
            HAL_GPIO_WritePin(BROCHE_Mosfet, BROCHE_Mosfet_2, GPIO_PIN_RESET);
            HAL_GPIO_WritePin(BROCHE_Mosfet, BROCHE_Mosfet_3, GPIO_PIN_RESET);
            HAL_GPIO_WritePin(BROCHE_Mosfet, BROCHE_Mosfet_4, GPIO_PIN_RESET);
            break;
        case 1:
            // Allume le transistor 2, �teint les autres
            HAL_GPIO_WritePin(BROCHE_Mosfet, BROCHE_Mosfet_1, GPIO_PIN_RESET);
            HAL_GPIO_WritePin(BROCHE_Mosfet, BROCHE_Mosfet_2, GPIO_PIN_SET);
            HAL_GPIO_WritePin(BROCHE_Mosfet, BROCHE_Mosfet_3, GPIO_PIN_RESET);
            HAL_GPIO_WritePin(BROCHE_Mosfet, BROCHE_Mosfet_4, GPIO_PIN_RESET);
            break;
        case 2:
            // Allume le transistor 3, �teint les autres
            HAL_GPIO_WritePin(BROCHE_Mosfet, BROCHE_Mosfet_1, GPIO_PIN_RESET);
            HAL_GPIO_WritePin(BROCHE_Mosfet, BROCHE_Mosfet_2, GPIO_PIN_RESET);
            HAL_GPIO_WritePin(BROCHE_Mosfet, BROCHE_Mosfet_3, GPIO_PIN_SET);
            HAL_GPIO_WritePin(BROCHE_Mosfet, BROCHE_Mosfet_4, GPIO_PIN_RESET);
            break;
        case 3:
            // Allume le transistor 4, �teint les autres
            HAL_GPIO_WritePin(BROCHE_Mosfet, BROCHE_Mosfet_1, GPIO_PIN_RESET);
            HAL_GPIO_WritePin(BROCHE_Mosfet, BROCHE_Mosfet_2, GPIO_PIN_RESET);
            HAL_GPIO_WritePin(BROCHE_Mosfet, BROCHE_Mosfet_3, GPIO_PIN_RESET);
            HAL_GPIO_WritePin(BROCHE_Mosfet, BROCHE_Mosfet_4, GPIO_PIN_SET);
            break;
        default:
            // G�rer d'autres chiffres ou afficher une erreur si n�cessaire
            break;
    }
}
