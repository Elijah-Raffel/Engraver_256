#include "tm4c123gh6pm.h"
#include "Systick.h"
#include "Port_Init.h"
#include <stdint.h>

#define rotation 200 // 200 steps for 1 full rotation
#define resolutionX (*((volatile unsigned long *)0x40006380))
#define resolutionY (*((volatile unsigned long *)0x40004380))
#define PC4 (*((volatile unsigned long *)0x40006040)) //PC4 is step for motor x
#define PB4 (*((volatile unsigned long *)0x40005040)) //PB4 is step for motor y
#define XmotorDir (*((volatile unsigned long *)0x40005020)) //pb3
#define YmotorDir (*((volatile unsigned long *)0x40005004)) //pb0

#define lazerPin (*((volatile unsigned long *)0x40005008)) //pb0

//dist takes in amount of steps 
//speed selects how big a step is (1, 1/2, 1/4, 1/8, 1/16)
void move_Motor_X(int dist, int step, int dir){
	switch(step){
		default:
				resolutionX = 0x00;
			break;
		
		case 2:
				resolutionX = 0x80; //sets PC7 to high
			break;
		
		case 4:
				resolutionX = 0x40; //sets PC6 to high
			break;
		
		case 8:
				resolutionX = 0xC0; //Sets PC6 and PC7 to high
			break;
		
		case 16:
				resolutionX = 0xE0; //sets PC5-7 to high
			break;
	}
	
	if(dir == 1){
		XmotorDir = 0x08; 
	}else{
		XmotorDir = 0x00; 
	}
	
	int i = 0;
	//This for loop sets PC4 to logic high and logic low after some time
	for(i = 0; i < dist; i++){
		PC4 = 0x10;
		SysTick_delay();
		PC4 = 0x00;
		SysTick_delay();
	}
	
}

void move_Motor_Y(int dist, int step, int dir){
	switch(step){
		default:
				resolutionY = 0x00;
			break;
		
		case 2:
				resolutionY = 0x80; //sets PC7 to high
			break;
		
		case 4:
				resolutionY = 0x40; //sets PC6 to high
			break;
		
		case 8:
				resolutionY = 0xC0; //Sets PC6 and PC7 to high
			break;
		
		case 16:
				resolutionY = 0xE0; //sets PC5-7 to high
			break;
	}
	
	if(dir == 1){
		YmotorDir = 0x01; 
	}else{
		YmotorDir = 0x00; 
	}
	
	int i = 0;
	//This for loop sets PB4 to logic high and logic low after some time
	for(i = 0; i < dist; i++){
		PB4 = 0x10;
		SysTick_delay();
		PB4 = 0x00;
		SysTick_delay();
	}
}

void lazerState(int state){
	if(state == 1){
		lazerPin = 0x02;
	}else{
		lazerPin = 0x00;
	}
}


