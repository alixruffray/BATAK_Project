/*
 * machine.h
 *
 *  Created on: 9 janv. 2024
 *      Author: alexi
 */

#ifndef MACHINE_H_
#define MACHINE_H_

/**
 * @defgroup Machine Machine � �tats
 * @brief Fonctions pour contr�ler la machine � �tats du jeu.
 * @{
 */

/**
 * @brief Initialise le jeu et affiche le meilleur score.
 */
void debutJeu();

/**
 * @brief Affiche le meilleur score au d�marrage du jeu.
 */
void affichedebut();

/**
 * @brief Fonction principale du jeu.
 */
void jeu();

/**
 * @brief G�re la fin du jeu et enregistre le meilleur score si n�cessaire.
 */
void fin();

/** @} */

#endif /* MACHINE_H_ */

