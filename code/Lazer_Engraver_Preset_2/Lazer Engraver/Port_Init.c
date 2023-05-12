#include "tm4c123gh6pm.h"
#include <stdint.h>

void Init_Ports(void); // port initialization file

void Init_Ports(void){
	volatile unsigned long delay;
	SYSCTL_RCGCGPIO_R |= 0x07; //Port A,B and C Clock Init; Want to use PB0&3 and PC4-7 as outputs
	//PP0&3 will drive directional input on motor driver board
	//This will drive the MS1-3 bits on motor driver
	//PC5->MS3; PC6->MS2; PC7->MS1
	//PC4 is step signal
  delay = SYSCTL_RCGCGPIO_R;           // allow time for clock to start
	GPIO_PORTC_AMSEL_R &= ~0xF0;
	GPIO_PORTC_AFSEL_R &= ~0xF0;
	GPIO_PORTC_PCTL_R &= ~0xFFFF0000;
	GPIO_PORTC_DIR_R |= 0xF0; //sets PC4-7 as outputs
	GPIO_PORTC_DEN_R |= 0xF0;
	
	//This block intitailizes port B pins to output direction
	//PB1 will send signal to arduino to drive lazer
	GPIO_PORTB_AMSEL_R &= ~0x1B;
	GPIO_PORTB_AFSEL_R &= ~0x1B;
	GPIO_PORTB_PCTL_R &= ~0x000FF0FF;
	GPIO_PORTB_DIR_R |= 0x1B; //sets PB0,1,3,4 as outputs
	//PB4 is step of motor y
	GPIO_PORTB_DEN_R |= 0x1B;
	
	//PORT A will drive MS1, MS2, MS3 for Y Motor
	// PA5->MS3, PA6->MS2, PA7->MS1,
	GPIO_PORTA_AMSEL_R &= ~0xE0;
	GPIO_PORTA_AFSEL_R &= ~0xE0;
	GPIO_PORTA_PCTL_R &= ~0xFFF00000;
	GPIO_PORTA_DIR_R |= 0xE0; //sets PA5,6,7 as outputs
	GPIO_PORTA_DEN_R |= 0xE0;
}

/*void Init_PWM(void){
	
}
*/