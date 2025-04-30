#ifndef _H_BUZZER
#define _H_BUZZER
#include "../MCAL/gpio.h"

#define BUZZER_PORT_ID	PORTD_ID
#define BUZZER_PIN_ID	PIN3_ID

void Buzzer_init(void);

void Buzzer_on(void);

void Buzzer_off(void);

#endif
