#include "MK64F12.h"
#include "NVIC.h"
#include "GPIO.h"
#include "RGB.h"
#include <stdint.h>

#define TRUE 	1
#define FALSE 	0

int main (void){

	uint8_t counter;

	//initialize the switches of the device
	GPIO_init();
	RGB_init();

	/**Sets the threshold for interrupts, if the interrupt has higher priority constant that the BASEPRI, the interrupt will not be attended*/
	NVIC_set_basepri_threshold(PRIORITY_6);
	/**Enables and sets a particular interrupt and its priority*/
	NVIC_enable_interrupt_and_priotity(PORTC_IRQ,PRIORITY_5);
	/**Enables and sets a particular interrupt and its priority*/
	NVIC_enable_interrupt_and_priotity(PORTA_IRQ,PRIORITY_5);

	NVIC_global_enable_interrupts;

	counter = 0;
	//set_RGB(OFF);

	while(1){
		//counter = 0;

		if(TRUE == GPIO_get_irq_status(GPIO_A)){
			if(5 == counter){
				counter = 1;
			}
			else{
				counter++;
			}

			GPIO_clear_irq_status(GPIO_A);
		}


		if(TRUE == GPIO_get_irq_status(GPIO_C)){
			if(1 == counter){
				counter = 5;
			}
			else{
				counter--;
			}
			GPIO_clear_irq_status(GPIO_C);
		}

		switch(counter){
		case 1:		set_RGB(GREEN);	 break;
		case 2: 	set_RGB(BLUE);	 break;
		case 3: 	set_RGB(VIOLET); break;
		case 4: 	set_RGB(RED); 	 break;
		case 5: 	set_RGB(YELLOW); break;
		default: 	set_RGB(OFF);	 break;
		}

	}
	return 0;
}
