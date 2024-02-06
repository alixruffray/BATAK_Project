/*
 * Mosfet.c
 *
 *  Created on: 15 nov. 2023
 *      Author: alexi
 */


#include "Mosfet.h"


void mosfet_Change(int chiffre) {
    switch (chiffre) {
    case 0:
        HAL_GPIO_WritePin(BROCHE_Mosfet, BROCHE_Mosfet_1, 1);
        HAL_GPIO_WritePin(BROCHE_Mosfet, BROCHE_Mosfet_2, 0);
        HAL_GPIO_WritePin(BROCHE_Mosfet, BROCHE_Mosfet_3, 0);
        HAL_GPIO_WritePin(BROCHE_Mosfet, BROCHE_Mosfet_4, 0);

        break;
    case 1:
    	HAL_GPIO_WritePin(BROCHE_Mosfet, BROCHE_Mosfet_1, 0);
    	HAL_GPIO_WritePin(BROCHE_Mosfet, BROCHE_Mosfet_2, 1);
    	HAL_GPIO_WritePin(BROCHE_Mosfet, BROCHE_Mosfet_3, 0);
    	HAL_GPIO_WritePin(BROCHE_Mosfet, BROCHE_Mosfet_4, 0);
        break;
    case 2:
        HAL_GPIO_WritePin(BROCHE_Mosfet, BROCHE_Mosfet_1, 0);
        HAL_GPIO_WritePin(BROCHE_Mosfet, BROCHE_Mosfet_2, 0);
        HAL_GPIO_WritePin(BROCHE_Mosfet, BROCHE_Mosfet_3, 1);
        HAL_GPIO_WritePin(BROCHE_Mosfet, BROCHE_Mosfet_4, 0);
        break;
    case 3:
        HAL_GPIO_WritePin(BROCHE_Mosfet, BROCHE_Mosfet_1, 0);
        HAL_GPIO_WritePin(BROCHE_Mosfet, BROCHE_Mosfet_2, 0);
        HAL_GPIO_WritePin(BROCHE_Mosfet, BROCHE_Mosfet_3, 0);
        HAL_GPIO_WritePin(BROCHE_Mosfet, BROCHE_Mosfet_4, 1);
        break;
    default:
    	// Gérer d'autres chiffres ou afficher une erreur si nécessaire
        break;
    }
}
