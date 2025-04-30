#include "ldr.h"
#include "../MCAL/adc.h"


uint16 LDR_getLightIntensity(void)
{
	uint16 reading = ADC_readChannel(LDR_SENSOR_CHANNEL_ID);

	return (((ADC_REF_VOLT_VALUE / ADC_MAXIMUM_VALUE) * reading) / LDR_SENSOR_MAX_VOLT_VALUE) * LDR_SENSOR_MAX_LIGHT_INTENSITY;
}
