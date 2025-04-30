#ifndef _H_PWM
#define _H_PWM
#include "../std_types.h"
// Initializes Timer0 in PWM mode and sets the required duty cycle.
// duty_cycle is in percentage e.g: 25%, 50%, ...
void PWM_Timer0_Start(uint8 duty_cycle);

#endif
