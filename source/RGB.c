/*
 * RGB.c
 *
 *  Created on: 4 may. 2024
 *      Author: Daniel Perez
 *      Email:
 */

#include "RGB.h"
#include "MK64F12.h"
#include "fsl_clock.h"
#include "fsl_gpio.h"
#include "fsl_port.h"

void RGB_init(void){

	gpio_pin_config_t led_config = {
			kGPIO_DigitalOutput,
			BIT_ON
		};
	/* enable clock gating to ports where the leds are */
	CLOCK_EnableClock(kCLOCK_PortB);
	CLOCK_EnableClock(kCLOCK_PortE);

	/* set mux as GPIO */
	PORT_SetPinMux(PORTB, PIN22, kPORT_MuxAsGpio);
	PORT_SetPinMux(PORTB, PIN21, kPORT_MuxAsGpio);
	PORT_SetPinMux(PORTE, PIN26, kPORT_MuxAsGpio);

	/* LED configuration  */
	GPIO_PinInit(GPIOB, PIN22, &led_config);  	//blue
	GPIO_PinInit(GPIOB, PIN21, &led_config);	//red
	GPIO_PinInit(GPIOE, PIN26, &led_config);	//green

}

void set_RGB(uint8_t set_color){

	//GPIO_PinWrite(GPIOB,PIN21,0);	//R
	/* applies shift to the LSB bit of set_color and puts that bit in corresponding place of GPIO */
	GPIO_PinWrite(GPIOB,PIN22,((set_color & 0x4u) >> 0x2U));	//R
	GPIO_PinWrite(GPIOE,PIN26,((set_color & 0x2u) >> 0x1U));	//G
	GPIO_PinWrite(GPIOB,PIN21,((set_color & 0x1u)));			//B
}
