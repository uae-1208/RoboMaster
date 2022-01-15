#include "led.h"
#include "adc.h"

u8 number = 0;     			//��ǰ�û������Ҷ�ı��
u8 State[6] = {off};			//��Ҷ�Ƿ�����ȫ����,state[0]��ʹ�ã�state[1-5]����Ӧ��Ҷ��Ӧ

void All_lights_down(void)
{
	int i;
	LEDA1 = 1;
	LEDA2 = 1;
	LEDA3 = 1;
	LEDA4 = 1;
	LEDA5 = 1;
	LEDB1 = 1;
	LEDB2 = 1;
	LEDB3 = 1;
	LEDB4 = 1;
	LEDB5 = 1; 
	for(i = 1; i <= 5; i++)
		State[i] = off;
}

void LED_Config(void)
{     
	//�͵�ƽ����(��һ����LEDA + �ڶ�����LEDB)	
	//��Ҷ1��PG12+PG13  ��Ҷ2��PG14+PG15  ��Ҷ3��PB3+PB4  ��Ҷ4��PB5+PB6  ��Ҷ5��PB7+PB8
    GPIO_InitTypeDef GPIO_InitStructure;
 	
    RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOG|RCC_APB2Periph_GPIOB, ENABLE);	 //ʹ�ܶ˿�ʱ��
	
    GPIO_InitStructure.GPIO_Pin = GPIO_Pin_12|GPIO_Pin_13|GPIO_Pin_14|GPIO_Pin_15;			
    GPIO_InitStructure.GPIO_Mode = GPIO_Mode_Out_PP; 		 //�������
    GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;		 //IO���ٶ�Ϊ50MHz
    GPIO_Init(GPIOG, &GPIO_InitStructure);	

    GPIO_InitStructure.GPIO_Pin = GPIO_Pin_3|GPIO_Pin_4|GPIO_Pin_5|GPIO_Pin_6|GPIO_Pin_7|GPIO_Pin_8;			
    GPIO_Init(GPIOB, &GPIO_InitStructure);	
	
	All_lights_down();		
}

void Lit_up_part1(u8 wing_number)
{
	switch(wing_number){
		case 1:	LEDA1 = 0;
				break;
		case 2: LEDA2 = 0;
				break;
		case 3:	LEDA3 = 0;
				break;
		case 4:	LEDA4 = 0;
				break;
		case 5:	LEDA5 = 0;
				break; 
	}
}

void Lit_up_part2(u8 wing_number)
{
	switch(wing_number){
		case 1:	LEDB1 = 0;
				break;
		case 2: LEDB2 = 0;
				break;
		case 3:	LEDB3 = 0;
				break;
		case 4:	LEDB4 = 0;
				break;
		case 5:	LEDB5 = 0;
				break; 
	}
}


u8 Random_lit_up(void)
{
	u8 i, wing_number;
	for(i = 1; i <= 5; i++)     //�ж�������Ҷ�Ƿ���ȫ����
		if(State[i] == off)
			break;
	if(i == 6)                  //���������Ҷ����ȫ����������false
		return False;
	wing_number = rand();       
	while(State[wing_number] != off)     //����һ��δ��ȫ��������Ҷ���
		wing_number = rand();
	return wing_number;
}



void Hit_failure(void)
{
	All_lights_down();
	TIM_SetCounter(TIM3, 0);
	number = Random_lit_up();
	Lit_up_part1(number);
}


void Hit_success(void)
{
	Lit_up_part2(number);
	State[number] = on;
	TIM_SetCounter(TIM3, 0);
	number = Random_lit_up();
	Lit_up_part1(number);
}

