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

/**
 * @brief Writes the state of the LED.
 * @param b: State of the LED (ON/OFF).
 * @return None
 */
void writeLED(bool_e b)
{
    HAL_GPIO_WritePin(LED_GREEN_GPIO, LED_GREEN_PIN, b);
}

/**
 * @brief Reads the state of the blue button.
 * @return State of the blue button (pressed/not pressed).
 */
bool_e readButton(void)
{
    return !HAL_GPIO_ReadPin(BLUE_BUTTON_GPIO, BLUE_BUTTON_PIN);
}

/**
 * @brief Enumeration of different states of the game.
 */
typedef enum {
    ETAT_Init,
    ETAT_Debut,
    ETAT_Jeu,
    ETAT_Fin,
} EtatJeu;

/**
 * @brief Structure representing the state machine for the game.
 */
typedef struct {
    EtatJeu etatActuel;
} MachineEtatsJeu;

/**
 * @brief Initializes the game state machine.
 * @param machine: Pointer to the state machine structure.
 * @return None
 */
void initMachineEtatsJeu(MachineEtatsJeu *machine) {
    machine->etatActuel = ETAT_Debut;
}

/**
 * @brief Updates the game state machine based on the current state.
 * @param machine: Pointer to the state machine structure.
 * @return None
 */
void mettreAJourMachineEtatsJeu(MachineEtatsJeu *machine) {
    switch (machine->etatActuel) {
        case ETAT_Debut:
            affichedebut();
            if (HAL_GPIO_ReadPin(Bouton_A, Bouton_6) == 0) {
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

/**
 * @brief Main function of the program.
 * @return Program exit status.
 */
int main(void)
{
    // Initialization of the Hardware Abstraction Layer (HAL)
    HAL_Init();

    // Initialization of UART2 at a baud rate of 115200 bps (PA2: Tx | PA3: Rx)
    UART_init(UART2_ID, 115200);

    // Set standard output to UART2
    SYS_set_std_usart(UART2_ID, UART2_ID, UART2_ID);

    // Initialize GPIO pins
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

    // Add the process_ms function to the list of functions called automatically every millisecond by the SYSTICK interrupt routine
    Systick_add_callback_function(&process_ms);

    // Shift LEDs to clear the display
    for (int supp = 0; supp < 14; supp++) {
        HAL_GPIO_WritePin(BROCHE_Registre_LED, BROCHE_CLK, 1);
        HAL_GPIO_WritePin(BROCHE_Registre_LED, BROCHE_CLK, 0);
    }

    // Initialize the game state machine
    MachineEtatsJeu machineJeu;
    initMachineEtatsJeu(&machineJeu);

    // Main loop
    while (1) {
        mettreAJourMachineEtatsJeu(&machineJeu);
    }

    // Program should never reach here
    return 0;
}
