/*
 * PWM_Bargraphe.h
 *
 *  Created on: 1 déc. 2023
 *      Author: alexi
 *      Connexion to A9
 */

/**
 * @file PWM_Bargraphe.h
 * @brief Déclaration des fonctions pour la gestion du bargraphe PWM.
 */

#ifndef PWM_BARGRAPHE_H_
#define PWM_BARGRAPHE_H_

/**
 * @brief Affiche le bargraphe en fonction du temps.
 *
 * @param[in] t - Le temps à afficher.
 */
void bar(uint32_t);

/**
 * @brief Fonction pour traiter les millisecondes.
 */
void process_ms(void);

#endif /* PWM_BARGRAPHE_H_ */
