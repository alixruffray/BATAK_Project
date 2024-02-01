/*
 * 4_Aff_Ensemble.c
 *
 *  Created on: 15 nov. 2023
 *      Author: alexi
 */

/**
 * @file 4_Aff_Ensemble.c
 * @brief Implémentation des fonctions pour l'affichage sur l'ensemble (mosfet + afficheur 7 segments).
 */

#include "Mosfet.h"
#include "Afficheur_Sept_Seg.h"
#include "Aff_4_7_Segg.h"

/**
 * @brief Affiche les chiffres sur l'ensemble (mosfet + afficheur 7 segments).
 *
 * @param[in] ms1 - Le premier chiffre du milliseconde.
 * @param[in] ms2 - Le deuxième chiffre du milliseconde.
 * @param[in] s1 - Le premier chiffre de la seconde.
 * @param[in] s2 - Le deuxième chiffre de la seconde.
 */
void Afficher(int ms1, int ms2, int s1, int s2) {
    int temps = 500;
    int i = 0;

    while (temps != 0) {
        temps = temps - 1;

        // Affichage du premier chiffre du milliseconde
        if (i == 0) {
            mosfet_Change(0);
            afficher_7_seg(ms1);
        }
        // Affichage du deuxième chiffre du milliseconde
        else if (i == 1) {
            mosfet_Change(1);
            afficher_7_seg(ms2);
        }
        // Affichage du premier chiffre de la seconde
        else if (i == 2) {
            mosfet_Change(3);
            afficher_7_seg(s1);
        }
        // Affichage du deuxième chiffre de la seconde
        else if (i == 3) {
            mosfet_Change(2);
            afficher_7_seg(s2);
        }

        // Changement de chiffre toutes les 500 ms
        if (temps == 1) {
            temps = 500;
            i = i + 1;
        }

        // Retour à zéro après avoir affiché les 4 chiffres
        if (i == 4) {
            i = 0;
            temps = 0;
        }
    }
}
