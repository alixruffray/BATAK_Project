/*
 * Registre_Decalage_LED.c
 *
 *  Created on: 6 déc. 2023
 *      Author: alexi
 */

#include "Registre_Decalage_LED.h"


void randomDeLED(int chiffre){
	for (int supp = 0; supp<13; supp++){
		HAL_GPIO_WritePin(BROCHE_Registre_LED, BROCHE_CLK, 1);
		HAL_GPIO_WritePin(BROCHE_Registre_LED, BROCHE_CLK, 0);
	}
	HAL_GPIO_WritePin(BROCHE_Registre_LED, BROCHE_Registre_LED_1, 1);
	HAL_GPIO_WritePin(BROCHE_Registre_LED, BROCHE_CLK, 1);
	HAL_GPIO_WritePin(BROCHE_Registre_LED, BROCHE_CLK, 0);
	HAL_GPIO_WritePin(BROCHE_Registre_LED, BROCHE_Registre_LED_1, 0);
	for (int i = 0; i < (chiffre+1); i++){
		HAL_GPIO_WritePin(BROCHE_Registre_LED, BROCHE_CLK, 1);
		HAL_GPIO_WritePin(BROCHE_Registre_LED, BROCHE_CLK, 0);
	}
}
