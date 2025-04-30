#include <avr/delay.h>
#include "std_types.h"
#include "MCAL/adc.h"
#include "HAL/buzzer.h"
#include "HAL/flame.h"
#include "HAL/lcd.h"
#include "HAL/ldr.h"
#include "HAL/led.h"
#include "HAL/motor.h"
#include "HAL/lm35_sensor.h"

char* fanState  = "";
uint8 prevFlame = 0, prevTemp = 151, prev_ldr = 101;
const char * criticalAlert = "Critical Alert!";

void rotateFan(const uint8 temp)
{

	if(temp >= 40)
	{
		DcMotor_Rotate(CW, 100);
	}
	else if(temp >= 35)
	{
		DcMotor_Rotate(CW, 75);
	}
	else if(temp >= 30)
	{
		DcMotor_Rotate(CW, 50);
	}
	else if(temp >= 25)
	{
		DcMotor_Rotate(CW, 25);
	}
	else
	{
		DcMotor_Rotate(STOP, 0);
	}


}

void controlLeds(const uint8 ldr)
{
	if(ldr < 15)
	{
		LED_on(RED);
		LED_on(GREEN);
		LED_on(BLUE);
	}
	else if (ldr <= 50)
	{
		LED_on(RED);
		LED_on(GREEN);
		LED_off(BLUE);
	}
	else if (ldr <= 70)
	{
		LED_on(RED);
		LED_off(GREEN);
		LED_off(BLUE);
	}
	else
	{
		LED_off(RED);
		LED_off(GREEN);
		LED_off(BLUE);
	}
}

void printInfo(const uint8 temp, const uint8 ldr, const uint8 flame)
{
	char* newFanState;

	if(temp >= 25)
		newFanState = "FAN is ON       ";
	else
		newFanState = "FAN is OFF      ";



	if(flame && prevFlame == 0)
	{
		LCD_clearScreen();
		LCD_displayString(criticalAlert);

	}
	else if(flame == 0)
	{
		if(prevFlame == 1 || fanState != newFanState)
		{
			LCD_moveCursor(0, 0);
			LCD_displayString(newFanState);
		}

		if(prevFlame == 1 || (temp != prevTemp || ldr != prev_ldr))
		{
			LCD_moveCursor(1, 0);
			LCD_displayString("TEMP=");
			LCD_intgerToString(temp);
			LCD_displayCharacter('C');

			LCD_displayCharacter(' ');
			LCD_displayString("LDR=");
			LCD_intgerToString(ldr);
			LCD_displayString("%     ");
		}

	}

	prevTemp = temp;
	prev_ldr = ldr;
	fanState = newFanState;
}


void controlBuzzer(const uint8 flame)
{
	if(flame)
	{
		// critical alert
		Buzzer_on();
		prevFlame = flame;
	}
	else if(flame == 0)
	{
		Buzzer_off();
		prevFlame = 0;
	}
}

int main(void)
{
	struct ADC_Config config = {ADC_128_PRESCALER, INTERNAL_2_56V};
	struct ADC_Config* configPtr = &config;

	uint8 flame = 0, temp = 0, ldr = 0;

	ADC_init(configPtr);
	Buzzer_init();
	FlameSensor_init();
	LCD_init();

	LEDS_init();
	DcMotor_Init();

	while(1)
	{
		flame = FlameSensor_getValue();
		temp = LM35_getTemperature();
		ldr = LDR_getLightIntensity();

		rotateFan(temp);
		printInfo(temp, ldr, flame);
		controlLeds(ldr);
		controlBuzzer(flame);
	}

	return 0;
}
