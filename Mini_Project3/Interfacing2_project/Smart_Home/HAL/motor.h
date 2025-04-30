#ifndef _H_MOTOR
#define _H_MOTOR
#include "../MCAL/gpio.h"

#define MOTOR_IN0_PORT_ID	PORTB_ID
#define MOTOR_IN0_PIN_ID	PIN0_ID

#define MOTOR_IN1_PORT_ID	PORTB_ID
#define MOTOR_IN1_PIN_ID	PIN1_ID


#define MOTOR_E_PORT_ID		PORTB_ID
#define MOTOR_E_PIN_ID		PIN3_ID


typedef enum
{
	CCW,
	CW,
	STOP
}DcMotor_State;

void DcMotor_Init(void);

// Controls the motor's state (Clockwise/Anti-Clockwise/Stop)
// and adjusts the speed based on the input duty cycle (in percentage)
void DcMotor_Rotate(DcMotor_State state, uint8 speed);


#endif
