#ifndef _ADC_H
#define _ADC_H

#include "../std_types.h"

#define ADC_REF_VOLT_VALUE	2.56
#define ADC_MAXIMUM_VALUE	1023

typedef enum
{
	AREF,
	AVCC,
	INTERNAL_2_56V = 3
} REFERENCE_SELECTION_BITS;

typedef enum
{
	ADC_2_PRESCALER,
	ADC_4_PRESCALER = 2,
	ADC_8_PRESCALER,
	ADC_16_PRESCALER,
	ADC_32_PRESCALER,
	ADC_64_PRESCALER,
	ADC_128_PRESCALER

} ADC_PRESCALER;


struct ADC_Config
{
	ADC_PRESCALER prescaler;
	REFERENCE_SELECTION_BITS reference;
};

void ADC_init(const struct ADC_Config*);

uint16 ADC_readChannel(uint8 ch_num);


#endif
