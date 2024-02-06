/*
 * PWM_Bargraphe.c
 *
 *  Created on: 29 nov. 2023
 *      Author: alexi
 */

#include <stdbool.h>
#include "stm32f1_timer.h"
#include "systick.h"
#include "stm32f1xx_hal.h"
#include "PWM_Bargraphe.h"

int tableau[11] = {1000,800,700,600,500,450,420,310,220,100,0};

void bar(uint32_t t){
	if (t==30000){
		TIMER_run_us(TIMER1_ID, 1000, 0);
		TIMER_enable_PWM(TIMER1_ID, TIM_CHANNEL_2, 500, 0, 0);
		TIMER_set_duty(TIMER1_ID, TIM_CHANNEL_2, 850);
	}


		if (t<=30000 && t>27000){
			TIMER_set_duty(TIMER1_ID, TIM_CHANNEL_2, 1000);
		}
		if (t<=27000 && t>24000){
			TIMER_set_duty(TIMER1_ID, TIM_CHANNEL_2, 450);
		}
		if (t<=24000 && t>21000){
			TIMER_set_duty(TIMER1_ID, TIM_CHANNEL_2, 425);
		}
		if (t<=21000 && t>18000){
			TIMER_set_duty(TIMER1_ID, TIM_CHANNEL_2, 380);
		}
		if (t<=18000 && t>15000){
			TIMER_set_duty(TIMER1_ID, TIM_CHANNEL_2, 350);
		}
		if (t<=15000 && t>12000){
			TIMER_set_duty(TIMER1_ID, TIM_CHANNEL_2, 300);
		}
		if (t<=12000 && t>9000){
			TIMER_set_duty(TIMER1_ID, TIM_CHANNEL_2, 250);
		}
		if (t<=9000 && t>6000){
			TIMER_set_duty(TIMER1_ID, TIM_CHANNEL_2, 200);
		}
		if (t<=6000 && t>3000){
			TIMER_set_duty(TIMER1_ID, TIM_CHANNEL_2, 150);
		}
		if (t<=3000 && t> 0){
			TIMER_set_duty(TIMER1_ID, TIM_CHANNEL_2, 100);
		}
		if (t==0){
			TIMER_set_duty(TIMER1_ID, TIM_CHANNEL_2, 0);
		}

}
