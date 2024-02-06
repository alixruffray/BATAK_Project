/*
 * 12_Bouton.c
 *
 *  Created on: 20 déc. 2023
 *      Author: alexi
 */

#include "N_12_Bouton.h"

int Bouton_Valide(int ou){
	 switch (ou) {
	    case 0:
	    	while (HAL_GPIO_ReadPin(Bouton_A,Bouton_1) == 1){
	    		return 0;
	    	}
	    	return 1;
	    	break;
	    case 1:
	    	while (HAL_GPIO_ReadPin(Bouton_A,Bouton_2) == 1){
	    		return 0;
	    	}
	    	return 1;
	    	break;
	    case 2:
	    	while (HAL_GPIO_ReadPin(Bouton_A,Bouton_3) == 1){
	    		return 0;
	    	}
	    	return 1;
	    	break;
	    case 3:
	    	while (HAL_GPIO_ReadPin(Bouton_A,Bouton_4) == 1){
	    		return 0;
	    	}
	    	return 1;
	    	break;
	    case 4:
	    	while (HAL_GPIO_ReadPin(Bouton_A,Bouton_5) == 1){
	    		return 0;
	    	}
	    	return 1;
	    	break;
	    case 5:
	    	while (HAL_GPIO_ReadPin(Bouton_A,Bouton_6) == 1){
	    		return 0;
	    	}
	    	return 1;
	    	break;
	    case 6:
	    	while (HAL_GPIO_ReadPin(Bouton_A,Bouton_7) == 1){
	    		return 0;
	    	}
	    	return 1;
	    	break;
	    case 7:
	    	while (HAL_GPIO_ReadPin(Bouton_A,Bouton_8) == 1){
	    		return 0;
	    	}
	    	return 1;
	    	break;
	    case 8:
	    	while (HAL_GPIO_ReadPin(Bouton_B,Bouton_9) == 1){
	    		return 0;
	    	}
	    	return 1;
	    	break;
	    case 9:
	    	while (HAL_GPIO_ReadPin(Bouton_B,Bouton_10) == 1){
	    		return 0;
	    	}
	    	return 1;
	    	break;
	    case 10:
	    	while (HAL_GPIO_ReadPin(Bouton_B,Bouton_11) == 1){
	    		return 0;
	    	}
	    	return 1;
	    	break;
	    case 11:
	    	while (HAL_GPIO_ReadPin(Bouton_B,Bouton_12) == 1){
	    		return 0;
	    	}
	    	return 1;
	    	break;
	    default:
	       	// Gérer d'autres chiffres ou afficher une erreur si nécessaire
	           break;
	 }
}
