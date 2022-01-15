#ifndef __LED_H
#define __LED_H	 
#include "sys.h"

#define on   1             //单个扇叶完全点亮
#define off  0	           //单个扇叶未完全点亮
#define False  0	       //扇叶全部完全点亮
#define LEDA1  PGout(12)   //某个扇叶的第一部分
#define LEDA2  PGout(14)
#define LEDA3  PBout(3)
#define LEDA4  PBout(5)
#define LEDA5  PBout(7)
#define LEDB1  PGout(13)    //某个扇叶的第二部分
#define LEDB2  PGout(15)
#define LEDB3  PBout(4)
#define LEDB4  PBout(6)
#define LEDB5  PBout(8)

void LED_Config(void);
void Lit_up_part1(u8 wing_number);		//点亮某个扇叶的第一部分
void Lit_up_part2(u8 wing_number);      //点亮某个扇叶的第二部分
u8 Random_lit_up(void);                 //产生一个随机点亮的扇叶，若所有扇叶完全点亮返回False
void All_lights_down(void);	            //大风车全灭，且所有扇叶的状态设置为off
void Hit_failure(void);                 //击打失败函数：击打错误或超时，大风车全灭，计数器清零，重新随机点亮一个扇叶
void Hit_success(void);                 //击打成功函数：当前扇叶完全点亮并状态变为on，计数器清零，重新随击点亮一个扇叶


#endif
