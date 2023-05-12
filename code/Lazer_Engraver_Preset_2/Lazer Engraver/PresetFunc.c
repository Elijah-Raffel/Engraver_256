#include "tm4c123gh6pm.h"
#include "Systick.h"
#include "Port_Init.h"
#include "motorCont.h"
#include <stdint.h>

void Square(int length){ // this is a function that draws a square spiral with each side length being 1/2 a rotation less than previous
	int side = 0; 
	while(length > 0){
		int i = 0;
			if(side == 0){
				for(i = 0; i < length; i++){
					move_Motor_X(16,16,0);
				}
			}else if(side == 1){
				for(i = 0; i < length; i++){
					move_Motor_Y(16,16,0);
				}
			}else if(side == 2){
				for(i = 0; i < length; i++){
					move_Motor_X(16,16,1);
				}				
			}else if(side == 3){
				for(i = 0; i < length; i++){
					move_Motor_Y(16,16,1);
				}
				side = 0;
			}
			side++;
			length = length - 100;
	}
}