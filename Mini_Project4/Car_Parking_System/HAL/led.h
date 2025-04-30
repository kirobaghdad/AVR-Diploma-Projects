#ifndef _H_LED
#define _H_LED
#include "../MCAL/gpio.h"

#define POSITIVE_LOGIC 		0
#define NEGATIVE_LOGIC		1

#define RED_LED_PORT_ID		PORTC_ID
#define RED_LED_PIN_ID		PIN0_ID

#define GREEN_LED_PORT_ID	PORTC_ID
#define GREEN_LED_PIN_ID	PIN1_ID

#define BLUE_LED_PORT_ID	PORTC_ID
#define BLUE_LED_PIN_ID		PIN2_ID

#define LED_LOGIC 			POSITIVE_LOGIC

typedef enum
{
	RED,
	GREEN,
	BLUE
}LED_ID;


void LEDS_init(void);

void LED_on(LED_ID id);

void LED_off(LED_ID id);

#endif
