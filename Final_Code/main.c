/**
  ******************************************************************************
  * @file    main.c
  * @author  Nirgal
  * @date    03-July-2019
  * @brief   Default main function.
  ******************************************************************************
*/

//#include <Afficheur_Sept_Seg.h>
#include "stm32f1xx_hal.h"
#include "stm32f1_uart.h"
#include "stm32f1_sys.h"
#include "stm32f1_gpio.h"
#include "stm32f1_timer.h"
#include "macro_types.h"
#include "systick.h"
#include "Afficheur_Sept_Seg.h"
#include "Mosfet.h"
#include "Aff_4_7_Segg.h"
#include "PWM_Bargraphe.h"
#include "Registre_Decalage_LED.h"
#include "stm32f1_adc.h"
#include "N_12_Bouton.h"
#include "machine.h"
#include "stm32f1_flash.h"

void writeLED(bool_e b)
{
	HAL_GPIO_WritePin(LED_GREEN_GPIO, LED_GREEN_PIN, b);
}

bool_e readButton(void)
{
	return !HAL_GPIO_ReadPin(BLUE_BUTTON_GPIO, BLUE_BUTTON_PIN);
}

typedef enum {
	ETAT_Init,
    ETAT_Debut,
    ETAT_Jeu,
	ETAT_Fin,
} EtatJeu;


typedef struct {
    EtatJeu etatActuel;
    } MachineEtatsJeu;


    void initMachineEtatsJeu(MachineEtatsJeu *machine) {
    machine->etatActuel = ETAT_Debut;
}


void mettreAJourMachineEtatsJeu(MachineEtatsJeu *machine) {
    switch (machine->etatActuel) {
        case ETAT_Debut:
        	affichedebut();
        	if (HAL_GPIO_ReadPin(Bouton_A,Bouton_6) == 0){
        		debutJeu();
        		machine->etatActuel = ETAT_Jeu;
        	}
            break;

        case ETAT_Jeu:
        	jeu();
        	machine->etatActuel = ETAT_Fin;
            break;

        case ETAT_Fin:
        	fin();
        	machine->etatActuel = ETAT_Debut;
            break;

        default:
            break;
    }
}

int main(void)
{
	//Initialisation de la couche logicielle HAL (Hardware Abstraction Layer)
	//Cette ligne doit rester la premi�re �tape de la fonction main().

	HAL_Init();

	//Initialisation de l'UART2 � la vitesse de 115200 bauds/secondes (92kbits/s) PA2 : Tx  | PA3 : Rx.
		//Attention, les pins PA2 et PA3 ne sont pas reli�es jusqu'au connecteur de la Nucleo.
		//Ces broches sont redirig�es vers la sonde de d�bogage, la liaison UART �tant ensuite encapsul�e sur l'USB vers le PC de d�veloppement.
	UART_init(UART2_ID,115200);

	//"Indique que les printf sortent vers le p�riph�rique UART2."
	SYS_set_std_usart(UART2_ID, UART2_ID, UART2_ID);

	//Initialisation du port de la led Verte (carte Nucleo)
	BSP_GPIO_PinCfg(LED_GREEN_GPIO, LED_GREEN_PIN, GPIO_MODE_OUTPUT_PP,GPIO_NOPULL,GPIO_SPEED_FREQ_HIGH);
	BSP_GPIO_PinCfg(BROCHE_DRIVER_7_SEGMENTS, BROCHE_DRIVER_SEGMENTS_1, GPIO_MODE_OUTPUT_PP,GPIO_NOPULL,GPIO_SPEED_FREQ_HIGH);
	BSP_GPIO_PinCfg(BROCHE_DRIVER_7_SEGMENTS, BROCHE_DRIVER_SEGMENTS_2, GPIO_MODE_OUTPUT_PP,GPIO_NOPULL,GPIO_SPEED_FREQ_HIGH);
	BSP_GPIO_PinCfg(BROCHE_DRIVER_7_SEGMENTS, BROCHE_DRIVER_SEGMENTS_3, GPIO_MODE_OUTPUT_PP,GPIO_NOPULL,GPIO_SPEED_FREQ_HIGH);
	BSP_GPIO_PinCfg(BROCHE_DRIVER_7_SEGMENTS, BROCHE_DRIVER_SEGMENTS_4, GPIO_MODE_OUTPUT_PP,GPIO_NOPULL,GPIO_SPEED_FREQ_HIGH);
	BSP_GPIO_PinCfg(BROCHE_Mosfet, BROCHE_Mosfet_1, GPIO_MODE_OUTPUT_PP,GPIO_NOPULL,GPIO_SPEED_FREQ_HIGH);
	BSP_GPIO_PinCfg(BROCHE_Mosfet, BROCHE_Mosfet_2, GPIO_MODE_OUTPUT_PP,GPIO_NOPULL,GPIO_SPEED_FREQ_HIGH);
	BSP_GPIO_PinCfg(BROCHE_Mosfet, BROCHE_Mosfet_3, GPIO_MODE_OUTPUT_PP,GPIO_NOPULL,GPIO_SPEED_FREQ_HIGH);
	BSP_GPIO_PinCfg(BROCHE_Mosfet, BROCHE_Mosfet_4, GPIO_MODE_OUTPUT_PP,GPIO_NOPULL,GPIO_SPEED_FREQ_HIGH);
	BSP_GPIO_PinCfg(BROCHE_Registre_LED, BROCHE_CLK, GPIO_MODE_OUTPUT_PP,GPIO_NOPULL,GPIO_SPEED_FREQ_HIGH);
	BSP_GPIO_PinCfg(BROCHE_Registre_LED, BROCHE_Registre_LED_1, GPIO_MODE_OUTPUT_PP,GPIO_NOPULL,GPIO_SPEED_FREQ_HIGH);
	BSP_GPIO_PinCfg(Bouton_A, Bouton_1, GPIO_MODE_INPUT,GPIO_PULLUP,GPIO_SPEED_FREQ_HIGH);
	BSP_GPIO_PinCfg(Bouton_A, Bouton_2, GPIO_MODE_INPUT,GPIO_PULLUP,GPIO_SPEED_FREQ_HIGH);
	BSP_GPIO_PinCfg(Bouton_A, Bouton_3, GPIO_MODE_INPUT,GPIO_PULLUP,GPIO_SPEED_FREQ_HIGH);
	BSP_GPIO_PinCfg(Bouton_A, Bouton_4, GPIO_MODE_INPUT,GPIO_PULLUP,GPIO_SPEED_FREQ_HIGH);
	BSP_GPIO_PinCfg(Bouton_A, Bouton_5, GPIO_MODE_INPUT,GPIO_PULLUP,GPIO_SPEED_FREQ_HIGH);
	BSP_GPIO_PinCfg(Bouton_A, Bouton_6, GPIO_MODE_INPUT,GPIO_PULLUP,GPIO_SPEED_FREQ_HIGH);
	BSP_GPIO_PinCfg(Bouton_A, Bouton_7, GPIO_MODE_INPUT,GPIO_PULLUP,GPIO_SPEED_FREQ_HIGH);
	BSP_GPIO_PinCfg(Bouton_A, Bouton_8, GPIO_MODE_INPUT,GPIO_PULLUP,GPIO_SPEED_FREQ_HIGH);
	BSP_GPIO_PinCfg(Bouton_B, Bouton_9, GPIO_MODE_INPUT,GPIO_PULLUP,GPIO_SPEED_FREQ_HIGH);
	BSP_GPIO_PinCfg(Bouton_B, Bouton_10, GPIO_MODE_INPUT,GPIO_PULLUP,GPIO_SPEED_FREQ_HIGH);
	BSP_GPIO_PinCfg(Bouton_B, Bouton_11, GPIO_MODE_INPUT,GPIO_PULLUP,GPIO_SPEED_FREQ_HIGH);
	BSP_GPIO_PinCfg(Bouton_B, Bouton_12, GPIO_MODE_INPUT,GPIO_PULLUP,GPIO_SPEED_FREQ_HIGH);

	//Initialisation du port du bouton bleu (carte Nucleo)
	BSP_GPIO_PinCfg(BLUE_BUTTON_GPIO, BLUE_BUTTON_PIN, GPIO_MODE_INPUT,GPIO_PULLUP,GPIO_SPEED_FREQ_HIGH);

	//On ajoute la fonction process_ms � la liste des fonctions appel�es automatiquement chaque ms par la routine d'interruption du p�riph�rique SYSTICK
	Systick_add_callback_function(&process_ms);


	for (int supp = 0; supp<14; supp++){
		HAL_GPIO_WritePin(BROCHE_Registre_LED, BROCHE_CLK, 1);
		HAL_GPIO_WritePin(BROCHE_Registre_LED, BROCHE_CLK, 0);
	}

	MachineEtatsJeu machineJeu;
	initMachineEtatsJeu(&machineJeu);

	while(1)	//boucle de t�che de fond
	{
        mettreAJourMachineEtatsJeu(&machineJeu);
	}


}
