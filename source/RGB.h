/*
 * This is the API for the RGB LEDS to be implemented in the K64 board based: FRDM K64
 * i.e: this code enables RGB pins to be used and sets a color.
 *
 * Author: Pablo Daniel Perez Montes
 * Email;  TAE2024.7@cinvestav.mx	/ pablo.perez7247@alumnos.udg.mx
 */

#ifndef	RGB_H_
#define RGB_H_

#include <stdint.h>
#include "MK64F12.h"
#include "GPIO.h"

#define BIT_ON 		 1u	 //unsigned
#define BIT_OFF	 	 0
#define PIN21        21u //unsigned
#define PIN22        22u //unsigned
#define PIN26        26u //unsigned

//enum the primary pallete for the RGB
typedef enum{
	WHITE	= 0x0U,
	RED 	= 0x3U,
	BLUE 	= 0x6U,
	GREEN 	= 0x5U,
	CYAN 	= 0x4U,
	YELLOW 	= 0x1U,
	VIOLET 	= 0x2U,
	OFF		= 0x7U
}color;

//RGB LED initialization of pins
void RGB_init(void);

// this function has the purpose to allow user to set any color in parameter
void set_RGB(uint8_t set_color);

#endif 
