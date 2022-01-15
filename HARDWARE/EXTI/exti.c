#include "exti.h"
#include "led.h"
#include "delay.h"

extern u8 number;

void EXTI_GPIO_Init(void)
{
	//PE1��PE2��PE3��PE4��PE5
	GPIO_InitTypeDef GPIO_InitStructure;
 
 	RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOE,ENABLE);

	GPIO_InitStructure.GPIO_Pin  = GPIO_Pin_1|GPIO_Pin_2|GPIO_Pin_3|GPIO_Pin_4|GPIO_Pin_5;  
	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_IPU ; 
 	GPIO_Init(GPIOE, &GPIO_InitStructure);					
}


void EXTI_MODE_Init(void)
{
	EXTI_InitTypeDef EXTI_InitStructure;
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_AFIO,ENABLE);	//ʹ�ܸ��ù���ʱ��

	GPIO_EXTILineConfig(GPIO_PortSourceGPIOE,GPIO_PinSource1);       //PE1
	EXTI_InitStructure.EXTI_Mode = EXTI_Mode_Interrupt;	
	EXTI_InitStructure.EXTI_Line = EXTI_Line1;
	EXTI_InitStructure.EXTI_Trigger = EXTI_Trigger_Falling;
	EXTI_InitStructure.EXTI_LineCmd = ENABLE;
	EXTI_Init(&EXTI_InitStructure);		

	GPIO_EXTILineConfig(GPIO_PortSourceGPIOE,GPIO_PinSource2);       //PE2
	EXTI_InitStructure.EXTI_Line = EXTI_Line2;
	EXTI_Init(&EXTI_InitStructure);		
	
	GPIO_EXTILineConfig(GPIO_PortSourceGPIOE,GPIO_PinSource3);       //PE3
	EXTI_InitStructure.EXTI_Line = EXTI_Line3;
	EXTI_Init(&EXTI_InitStructure);		
	
	GPIO_EXTILineConfig(GPIO_PortSourceGPIOE,GPIO_PinSource4);       //PE4
	EXTI_InitStructure.EXTI_Line = EXTI_Line4;
	EXTI_Init(&EXTI_InitStructure);		
	
	GPIO_EXTILineConfig(GPIO_PortSourceGPIOE,GPIO_PinSource5);       //PE5
	EXTI_InitStructure.EXTI_Line = EXTI_Line5;
	EXTI_Init(&EXTI_InitStructure);		
}
void EXTI_NVIC_Init(void)
{
	NVIC_InitTypeDef NVIC_InitStructure;
	NVIC_InitStructure.NVIC_IRQChannel = EXTI1_IRQn;				//ʹ�ܰ���key1���ڵ��ⲿ�ж�ͨ��
  	NVIC_InitStructure.NVIC_IRQChannelPreemptionPriority = 0x02;	//��ռ���ȼ�2�� 
  	NVIC_InitStructure.NVIC_IRQChannelSubPriority = 0x03;			//�����ȼ�3
  	NVIC_InitStructure.NVIC_IRQChannelCmd = ENABLE;					//ʹ���ⲿ�ж�ͨ��
  	NVIC_Init(&NVIC_InitStructure); 
	
	NVIC_InitStructure.NVIC_IRQChannel = EXTI2_IRQn;				//ʹ�ܰ���key2���ڵ��ⲿ�ж�ͨ��
  	NVIC_Init(&NVIC_InitStructure); 
	
	NVIC_InitStructure.NVIC_IRQChannel = EXTI3_IRQn;				//ʹ�ܰ���key3���ڵ��ⲿ�ж�ͨ��
  	NVIC_Init(&NVIC_InitStructure); 
	
	NVIC_InitStructure.NVIC_IRQChannel = EXTI4_IRQn;				//ʹ�ܰ���key4���ڵ��ⲿ�ж�ͨ��
  	NVIC_Init(&NVIC_InitStructure); 
	
	NVIC_InitStructure.NVIC_IRQChannel = EXTI9_5_IRQn;				//ʹ�ܰ���key5���ڵ��ⲿ�ж�ͨ��
  	NVIC_Init(&NVIC_InitStructure); 
}

void EXTI_Config(void)
{
	EXTI_GPIO_Init();
	EXTI_MODE_Init();
	EXTI_NVIC_Init();
}



void EXTI1_IRQHandler(void)
{
	delay_ms(50);//����
	if(key1 == 0)          //����
	{
		if(number == 1)    //�ж��Ƿ�������
			Hit_success();
		else
			Hit_failure();  
	while(!key1);	
	}		
	EXTI_ClearITPendingBit(EXTI_Line1);  //���LINE1�ϵ��жϱ�־λ  
}

void EXTI2_IRQHandler(void)
{
	delay_ms(50);//����
	if(key2 == 0)
	{
		if(number == 2)
			Hit_success();
		else
			Hit_failure();  
	}
	while(!key2);	
	EXTI_ClearITPendingBit(EXTI_Line2);  //���LINE2�ϵ��жϱ�־λ  
}

void EXTI3_IRQHandler(void)
{
	delay_ms(50);//����
	if(key3 == 0)
	{
		if(number == 3)
			Hit_success();
		else
			Hit_failure();
	}	
	while(!key3);		
	EXTI_ClearITPendingBit(EXTI_Line3);  //���LINE3�ϵ��жϱ�־λ  
}

void EXTI4_IRQHandler(void)
{
	delay_ms(50);//����
	if(key4 == 0)
	{
		if(number == 4)
			Hit_success();
		else
			Hit_failure();
	}	
	while(!key4);
	EXTI_ClearITPendingBit(EXTI_Line4);  //���LINE4�ϵ��жϱ�־λ  
}
                 
void EXTI9_5_IRQHandler(void)
{
	delay_ms(50);//����
	if(key5 == 0)
	{
		if(number == 5)
			Hit_success();
		else
			Hit_failure();
	}	
	while(!key5);	
	EXTI_ClearITPendingBit(EXTI_Line5);  //���LINE5�ϵ��жϱ�־λ  
}


