#ifndef __EXTI_H
#define __EXTI_H	 
#include "sys.h"

#define key1 PEin(1)	//1∫≈…»“∂
#define key2 PEin(2)    //2∫≈…»“∂
#define key3 PEin(3)    //3∫≈…»“∂
#define key4 PEin(4)    //4∫≈…»“∂
#define key5 PEin(5)    //5∫≈…»“∂

void EXTI_GPIO_Init(void);
void EXTI_MODE_Init(void);
void EXTI_NVIC_Init(void);
void EXTI_Config(void);
		 				    
#endif
