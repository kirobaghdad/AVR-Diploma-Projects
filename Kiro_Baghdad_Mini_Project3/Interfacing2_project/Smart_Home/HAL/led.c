#include "led.h"


void LEDS_init(void)
{
	// initialize pins direction
	GPIO_setupPinDirection(RED_LED_PORT_ID, RED_LED_PIN_ID, PIN_OUTPUT);
	GPIO_setupPinDirection(GREEN_LED_PORT_ID, GREEN_LED_PIN_ID, PIN_OUTPUT);
	GPIO_setupPinDirection(BLUE_LED_PORT_ID, BLUE_LED_PIN_ID, PIN_OUTPUT);

#if LED_LOGIC == POSITIVE_LOGIC
	GPIO_writePin(RED_LED_PORT_ID, RED_LED_PIN_ID, LOGIC_LOW);
	GPIO_writePin(GREEN_LED_PORT_ID, GREEN_LED_PIN_ID, LOGIC_LOW);
	GPIO_writePin(BLUE_LED_PORT_ID, BLUE_LED_PIN_ID, LOGIC_LOW);
#else
	GPIO_writePin(RED_LED_PORT_ID, RED_LED_PIN_ID, LOGIC_HIGH);
	GPIO_writePin(GREEN_LED_PORT_ID, GREEN_LED_PIN_ID, LOGIC_HIGH);
	GPIO_writePin(BLUE_LED_PORT_ID, BLUE_LED_PIN_ID, LOGIC_HIGH);
#endif
}

void LED_on(LED_ID id)
{
	if(id == RED)
	{
		GPIO_writePin(RED_LED_PORT_ID, RED_LED_PIN_ID, LOGIC_HIGH);
	}
	else if(id == GREEN)
	{
		GPIO_writePin(GREEN_LED_PORT_ID, GREEN_LED_PIN_ID, LOGIC_HIGH);
	}
	else if(id == BLUE)
	{
		GPIO_writePin(BLUE_LED_PORT_ID, BLUE_LED_PIN_ID, LOGIC_HIGH);
	}
}

void LED_off(LED_ID id)
{
	if(id == RED)
	{
		GPIO_writePin(RED_LED_PORT_ID, RED_LED_PIN_ID, LOGIC_LOW);
	}
	else if(id == GREEN)
	{
		GPIO_writePin(GREEN_LED_PORT_ID, GREEN_LED_PIN_ID, LOGIC_LOW);
	}
	else if(id == BLUE)
	{
		GPIO_writePin(BLUE_LED_PORT_ID, BLUE_LED_PIN_ID, LOGIC_LOW);
	}

}
