#ifndef __EXTI_H
#define __EXTI_H	 
#include "sys.h"

#define key1 PEin(1)	//1����Ҷ
#define key2 PEin(2)    //2����Ҷ
#define key3 PEin(3)    //3����Ҷ
#define key4 PEin(4)    //4����Ҷ
#define key5 PEin(5)    //5����Ҷ

void EXTI_GPIO_Init(void);
void EXTI_MODE_Init(void);
void EXTI_NVIC_Init(void);
void EXTI_Config(void);
		 				    
#endif
