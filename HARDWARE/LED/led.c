#include "led.h"
#include "adc.h"

u8 number = 0;     			//当前该击打的扇叶的标号
u8 State[6] = {off};			//扇叶是否已完全点亮,state[0]不使用，state[1-5]与相应扇叶对应

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
	//低电平点亮(第一部分LEDA + 第二部分LEDB)	
	//扇叶1：PG12+PG13  扇叶2：PG14+PG15  扇叶3：PB3+PB4  扇叶4：PB5+PB6  扇叶5：PB7+PB8
    GPIO_InitTypeDef GPIO_InitStructure;
 	
    RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOG|RCC_APB2Periph_GPIOB, ENABLE);	 //使能端口时钟
	
    GPIO_InitStructure.GPIO_Pin = GPIO_Pin_12|GPIO_Pin_13|GPIO_Pin_14|GPIO_Pin_15;			
    GPIO_InitStructure.GPIO_Mode = GPIO_Mode_Out_PP; 		 //推挽输出
    GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;		 //IO口速度为50MHz
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
	for(i = 1; i <= 5; i++)     //判断所有扇叶是否都完全点亮
		if(State[i] == off)
			break;
	if(i == 6)                  //如果所有扇叶都完全点亮，返回false
		return False;
	wing_number = rand();       
	while(State[wing_number] != off)     //产生一个未完全点亮的扇叶序号
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

