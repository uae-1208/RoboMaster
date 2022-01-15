#include "sys.h"
#include "delay.h"
#include "usart.h"
#include "led.h"
#include "adc.h"
#include "exti.h"
#include "tim.h"

extern u8 number; 

int main(void)
{			  
	SystemInit();
    delay_init();	    	 //延时函数初始化
	NVIC_PriorityGroupConfig(NVIC_PriorityGroup_2); //设置NVIC中断分组2:2位抢占优先级，2位响应优先级
    LED_Config();
	ADC_Config();
	EXTI_Config();
	TIM_Config();
	
	number = Random_lit_up();
	Lit_up_part1(number);
	while(1)
    {
		if(!number)                //判断是否全部击打成功
			TIM_Cmd(TIM3, DISABLE); 	
	}
}
