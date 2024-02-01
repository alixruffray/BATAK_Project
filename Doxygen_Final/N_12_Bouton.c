/*
 * N_12_Bouton.c
 *
 *  Created on: 20 déc. 2023
 *      Author: alexi
 */

/**
 * @file N_12_Bouton.c
 * @brief Implémentation des fonctions pour la gestion des boutons N-12.
 */

#include "N_12_Bouton.h"

/**
 * @brief Vérifie si le bouton correspondant à la valeur 'ou' est pressé.
 *
 * @param[in] ou - La valeur du bouton à vérifier (de 0 à 11).
 * @return 1 si le bouton est pressé, 0 sinon.
 */
int Bouton_Valide(int ou) {
    switch (ou) {
        case 0:
            while (HAL_GPIO_ReadPin(Bouton_A, Bouton_1) == 1) {
                return 0;
            }
            return 1;
            break;
        case 1:
            while (HAL_GPIO_ReadPin(Bouton_A, Bouton_2) == 1) {
                return 0;
            }
            return 1;
            break;
        case 2:
            while (HAL_GPIO_ReadPin(Bouton_A, Bouton_3) == 1) {
                return 0;
            }
            return 1;
            break;
        case 3:
            while (HAL_GPIO_ReadPin(Bouton_A, Bouton_4) == 1) {
                return 0;
            }
            return 1;
            break;
        case 4:
            while (HAL_GPIO_ReadPin(Bouton_A, Bouton_5) == 1) {
                return 0;
            }
            return 1;
            break;
        case 5:
            while (HAL_GPIO_ReadPin(Bouton_A, Bouton_6) == 1) {
                return 0;
            }
            return 1;
            break;
        case 6:
            while (HAL_GPIO_ReadPin(Bouton_A, Bouton_7) == 1) {
                return 0;
            }
            return 1;
            break;
        case 7:
            while (HAL_GPIO_ReadPin(Bouton_A, Bouton_8) == 1) {
                return 0;
            }
            return 1;
            break;
        case 8:
            while (HAL_GPIO_ReadPin(Bouton_B, Bouton_9) == 1) {
                return 0;
            }
            return 1;
            break;
        case 9:
            while (HAL_GPIO_ReadPin(Bouton_B, Bouton_10) == 1) {
                return 0;
            }
            return 1;
            break;
        case 10:
            while (HAL_GPIO_ReadPin(Bouton_B, Bouton_11) == 1) {
                return 0;
            }
            return 1;
            break;
        case 11:
            while (HAL_GPIO_ReadPin(Bouton_B, Bouton_12) == 1) {
                return 0;
            }
            return 1;
            break;
        default:
            // Gérer d'autres chiffres ou afficher une erreur si nécessaire
            break;
    }
    return 0;
}
