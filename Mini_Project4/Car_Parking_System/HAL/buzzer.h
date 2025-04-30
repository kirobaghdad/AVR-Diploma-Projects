#ifndef _H_BUZZER
#define _H_BUZZER
#include "../MCAL/gpio.h"

#define BUZZER_PORT_ID	PORTC_ID
#define BUZZER_PIN_ID	PIN5_ID

void Buzzer_init(void);

void Buzzer_on(void);

void Buzzer_off(void);

#endif
