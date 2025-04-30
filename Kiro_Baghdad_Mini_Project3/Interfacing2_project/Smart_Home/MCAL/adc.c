#include <avr/io.h>
#include "adc.h"
#include "../common_macros.h"

void ADC_init(const struct ADC_Config* config)
{
	ADMUX = config->reference << 6;
	ADCSRA = (1 << ADEN);
	ADCSRA |= config->prescaler & 0x07;
}


uint16 ADC_readChannel(uint8 ch_num)
{
	ch_num &= 0x07;
	ADMUX &= 0xE0;
	ADMUX = ADMUX | ch_num;

	SET_BIT(ADCSRA, ADSC);

	while(BIT_IS_CLEAR(ADCSRA, ADIF));

	SET_BIT(ADCSRA, ADIF);

	return ADC;
}
