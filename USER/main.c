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
    delay_init();	    	 //��ʱ������ʼ��
	NVIC_PriorityGroupConfig(NVIC_PriorityGroup_2); //����NVIC�жϷ���2:2λ��ռ���ȼ���2λ��Ӧ���ȼ�
    LED_Config();
	ADC_Config();
	EXTI_Config();
	TIM_Config();
	
	number = Random_lit_up();
	Lit_up_part1(number);
	while(1)
    {
		if(!number)                //�ж��Ƿ�ȫ������ɹ�
			TIM_Cmd(TIM3, DISABLE); 	
	}
}
