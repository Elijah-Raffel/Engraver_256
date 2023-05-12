#include "Systick.h"
#include "tm4c123gh6pm.h"
#include <stdint.h>

void SysTick_Init(void){
	NVIC_ST_CTRL_R = 0;
	NVIC_ST_RELOAD_R = 0X00FFFFFF;
	NVIC_ST_CURRENT_R = 0;
	NVIC_ST_CTRL_R = 0X00000005;
}

void SysTick_delay(void){//using default 16MHz clock
		//Use the Systick Timer to generate a 1ms delay
	// Choose the number of clock ticks to wait
	NVIC_ST_RELOAD_R = 15999;
	//NVIC_ST_RELOAD_R = 159999;
	//NVIC_ST_RELOAD_R = 1599999;
	//NVIC_ST_RELOAD_R = 11200;
	
	NVIC_ST_CURRENT_R = 0; // Any value written to write clears it
	while((NVIC_ST_CTRL_R&0x00010000)==0){} // Wait for count flag 
}

void SysTick_VarDelay(int var){
	int i = 0;
	for(i = 0; i < var; i++){
		SysTick_delay();
	}
}

void SysTick_2s(void){
	int i = 0;
	for(i = 0; i < 2000; i++){
		SysTick_delay();
	}
}