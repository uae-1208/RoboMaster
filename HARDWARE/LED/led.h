#ifndef __LED_H
#define __LED_H	 
#include "sys.h"

#define on   1             //������Ҷ��ȫ����
#define off  0	           //������Ҷδ��ȫ����
#define False  0	       //��Ҷȫ����ȫ����
#define LEDA1  PGout(12)   //ĳ����Ҷ�ĵ�һ����
#define LEDA2  PGout(14)
#define LEDA3  PBout(3)
#define LEDA4  PBout(5)
#define LEDA5  PBout(7)
#define LEDB1  PGout(13)    //ĳ����Ҷ�ĵڶ�����
#define LEDB2  PGout(15)
#define LEDB3  PBout(4)
#define LEDB4  PBout(6)
#define LEDB5  PBout(8)

void LED_Config(void);
void Lit_up_part1(u8 wing_number);		//����ĳ����Ҷ�ĵ�һ����
void Lit_up_part2(u8 wing_number);      //����ĳ����Ҷ�ĵڶ�����
u8 Random_lit_up(void);                 //����һ�������������Ҷ����������Ҷ��ȫ��������False
void All_lights_down(void);	            //��糵ȫ����������Ҷ��״̬����Ϊoff
void Hit_failure(void);                 //����ʧ�ܺ�������������ʱ����糵ȫ�𣬼��������㣬�����������һ����Ҷ
void Hit_success(void);                 //����ɹ���������ǰ��Ҷ��ȫ������״̬��Ϊon�����������㣬�����������һ����Ҷ


#endif
