#ifndef __ADC_H
#define __ADC_H	 
#include "sys.h"

void ADC_GPIO_Init(void);
void ADC_MODE_Init(void);
void ADC_Config(void);
u16 Get_Adc(u8 ch);
u16 rand(void);


#endif

