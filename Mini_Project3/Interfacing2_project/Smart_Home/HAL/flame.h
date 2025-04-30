#ifndef _H_FLAME
#define _H_FLAME
#include "../MCAL/gpio.h"
#include "../std_types.h"

#define FLAME_PORT_ID	PORTD_ID
#define FLAME_PIN_ID	PIN2_ID

void FlameSensor_init(void);

uint8 FlameSensor_getValue(void);

#endif
