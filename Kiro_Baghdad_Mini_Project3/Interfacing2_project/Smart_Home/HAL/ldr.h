#ifndef _H_LDR
#define _H_LDR
#include "../std_types.h"

#define LDR_SENSOR_CHANNEL_ID 0
#define LDR_SENSOR_MAX_VOLT_VALUE 2.56f
#define LDR_SENSOR_MAX_LIGHT_INTENSITY 100

uint16 LDR_getLightIntensity(void);

#endif
