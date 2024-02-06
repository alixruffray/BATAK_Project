/*
 * machine.c
 *
 *  Created on: 9 janv. 2024
 *      Author: alexi
 */


#include <machine.h>
#include "Aff_4_7_Segg.h"
#include "PWM_Bargraphe.h"
#include "N_12_Bouton.h"
#include "Registre_Decalage_LED.h"
#include "stm32f1_adc.h"
#include "stm32f1_gpio.h"
#include "stm32f1_sys.h"
#include "stm32f1xx_hal.h"
#include "stm32f1_flash.h"

uint32_t score;
uint32_t score1;
uint32_t score2;
uint32_t high10;
uint32_t high1;
uint32_t highscore = 0;

static volatile uint32_t t = 0;
		void process_ms(void)
		{
			if(t)
				t--;
		}

void clignotement(){
	for (int rep = 0; rep<3;rep++){
		t=600;
		HAL_GPIO_WritePin(BROCHE_Registre_LED, BROCHE_Registre_LED_1, 1);
		HAL_GPIO_WritePin(BROCHE_Registre_LED, BROCHE_CLK, 1);
		HAL_GPIO_WritePin(BROCHE_Registre_LED, BROCHE_CLK, 0);
		for (int cli = 0; cli < 13; cli++){
			HAL_GPIO_WritePin(BROCHE_Registre_LED, BROCHE_CLK, 1);
			HAL_GPIO_WritePin(BROCHE_Registre_LED, BROCHE_CLK, 0);
		}
		bar(30000);
		while(t>300){
			affichedebut();
		}
		HAL_GPIO_WritePin(BROCHE_Registre_LED, BROCHE_Registre_LED_1, 0);
		for (int supp = 0; supp<13; supp++){
			HAL_GPIO_WritePin(BROCHE_Registre_LED, BROCHE_CLK, 1);
			HAL_GPIO_WritePin(BROCHE_Registre_LED, BROCHE_CLK, 0);
		}
		bar(0);
		while(t>0){
			affichedebut();
		}
	}
}


void debutJeu(){
	clignotement();
	highscore = FLASH_read_word(4);
	high10 = highscore/10;
	high1 = highscore - (high10*10);
	score = 0;
	score1 = 0;
	score2 = 0;
	//partir sur le jeu

}

void jeu(){
	t= 30000;
	uint8_t exrandom = 2;
	uint8_t valide;

	while (t){
		valide = 0;

		ADC_init();
		uint8_t randomiser = 0;
		randomiser = (uint8_t) ADC_getValue(ADC_CHANNEL_0 ) %12;

		if (exrandom==randomiser){
			if (exrandom > 10){
				randomiser = exrandom-2;
			}
			else{
				randomiser = exrandom+2;
			}
		}

		randomDeLED(randomiser);

		while (Bouton_Valide(randomiser) == 0){
			bar(t);
			Afficher(high10, high1, score1, score2);
			valide ++;
			if (t==0){
				score--;
				bar(0);
				break;
			}
		}
		if (valide != 0){
			score++;
			score1 = score/10;
			score2 = score - (score1*10);
		}

	}
}


void fin(){
	if (score>highscore){
		FLASH_set_word(4, score);
	}
	clignotement();
}

void affichedebut(){
	highscore = FLASH_read_word(4);
	high10 = highscore/10;
	high1 = highscore - (high10*10);
	Afficher(high10, high1, score1, score2);
}
