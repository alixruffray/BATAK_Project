/*
 * machine.h
 *
 *  Created on: 9 janv. 2024
 *      Author: alexi
 */

#ifndef MACHINE_H_
#define MACHINE_H_

/**
 * @defgroup Machine Machine à états
 * @brief Fonctions pour contrôler la machine à états du jeu.
 * @{
 */

/**
 * @brief Initialise le jeu et affiche le meilleur score.
 */
void debutJeu();

/**
 * @brief Affiche le meilleur score au démarrage du jeu.
 */
void affichedebut();

/**
 * @brief Fonction principale du jeu.
 */
void jeu();

/**
 * @brief Gère la fin du jeu et enregistre le meilleur score si nécessaire.
 */
void fin();

/** @} */

#endif /* MACHINE_H_ */

