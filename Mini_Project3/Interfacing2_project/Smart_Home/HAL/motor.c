#include "motor.h"
#include "../MCAL/PWM.h"

void DcMotor_Init(void)
{
	GPIO_setupPinDirection(MOTOR_IN0_PORT_ID, MOTOR_IN0_PIN_ID, PIN_OUTPUT);
	GPIO_setupPinDirection(MOTOR_IN1_PORT_ID, MOTOR_IN1_PIN_ID, PIN_OUTPUT);
	GPIO_setupPinDirection(MOTOR_E_PORT_ID, MOTOR_E_PIN_ID, PIN_OUTPUT);

	DcMotor_Rotate(STOP, -1);
}


void DcMotor_Rotate(DcMotor_State state, uint8 speed)
{
	if(state == CCW)
	{
		GPIO_writePin(MOTOR_IN0_PORT_ID, MOTOR_IN0_PIN_ID, LOGIC_HIGH);
		GPIO_writePin(MOTOR_IN1_PORT_ID, MOTOR_IN1_PIN_ID, LOGIC_LOW);

		PWM_Timer0_Start(speed);
	}
	else if(state == CW)
	{
		GPIO_writePin(MOTOR_IN0_PORT_ID, MOTOR_IN0_PIN_ID, LOGIC_LOW);
		GPIO_writePin(MOTOR_IN1_PORT_ID, MOTOR_IN1_PIN_ID, LOGIC_HIGH);

		PWM_Timer0_Start(speed);
	}
	else if(state == STOP)
	{
		GPIO_writePin(MOTOR_IN0_PORT_ID, MOTOR_IN0_PIN_ID, LOGIC_LOW);
		GPIO_writePin(MOTOR_IN1_PORT_ID, MOTOR_IN1_PIN_ID, LOGIC_LOW);

		PWM_Timer0_Start(0);
	}

}

