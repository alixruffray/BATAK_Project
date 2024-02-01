/*
 * Aff_4_7_Segg.h
 *
 *  Created on: 15 nov. 2023
 *      Author: alexi
 */

/**
 * @file Aff_4_7_Segg.h
 * @brief Déclaration des fonctions pour l'affichage sur l'ensemble (mosfet + afficheur 7 segments).
 */

#ifndef AFF_4_7_SEGG_H_
#define AFF_4_7_SEGG_H_

/**
 * @brief Affiche les chiffres sur l'ensemble (mosfet + afficheur 7 segments).
 *
 * @param[in] ms1 - Le premier chiffre du milliseconde.
 * @param[in] ms2 - Le deuxième chiffre du milliseconde.
 * @param[in] s1 - Le premier chiffre de la seconde.
 * @param[in] s2 - Le deuxième chiffre de la seconde.
 */
void Afficher(int ms1, int ms2, int s1, int s2);

#endif /* AFF_4_7_SEGG_H_ */
