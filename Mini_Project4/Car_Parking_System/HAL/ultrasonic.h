#ifndef _H_ULTRASONIC
#define _H_ULTRASONIC
#include "../std_types.h"
#include "../MCAL/gpio.h"

#define ICU_ECHO_PORT PORTD_ID
#define ICU_ECHO_PIN  PIN6_ID

#define ICU_TRIGGER_PORT PORTD_ID
#define ICU_TRIGGER_PIN  PIN7_ID


void Ultrasonic_init(void);

void Ultrasonic_Trigger(void);

uint16 Ultrasonic_readDistance(void);

void Ultrasonic_edgeProcessing(void);

#endif
