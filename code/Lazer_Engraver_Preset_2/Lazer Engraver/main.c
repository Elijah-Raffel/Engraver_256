#include "tm4c123gh6pm.h"
#include <stdint.h>
#include "motorCont.h"
#include "Systick.h"
#include "Port_Init.h"
#include "PresetFunc.h"

int main(void){
	Init_Ports();
	SysTick_Init();
	while(1){
		//3 ROTATIONS IN BOTH DIRECTIONS ARE MAX
		//1 rotation = 200 full steps
/*uncomment for for diagonal line and lazer
		lazerState(0);
		int i = 0;
		for(i = 0; i < 200; i++){
			move_Motor_X(16, 16, 0);
			move_Motor_Y(16, 16, 0);
		}
		int j = 0;
		for(j = 0; j < 2000; j++){
			SysTick_delay();
		}
		lazerState(0);
		int k = 0;
		for(k = 0; k < 200; k++){
			move_Motor_X(16, 16, 1);
			move_Motor_Y(16, 16, 1);
		}
		int l = 0;
		for(l = 0; l < 10000; l++){
			SysTick_delay();
		}
*/
	
	Square(400);

	}
	return 0; 
}
