#define __main_c
#include "includeAll.h"
int modeValue = 1;
//=============================================================================
void main() {
	int i = 0;
  SysInit();
  VarsInit();
  InitTriac();
  //使能看门狗
  F_turnOnWDT();
	P1_0 = 0;          // 开漏输出状态 且 数据位为0 时点亮
	P1_4 = 0;
	P1_2 = 1;
	P1MODH = 0xaa;     //推挽输出状态控制蜂鸣器
  while (1) {
    //喂狗
    F_clearWDT();
   // F_buzz();
		//for(i=0;i<1000000;i++)
	//	F_buzz();
    TimeProcess();
    TaskSetting();
		DisplayProcess();
  }
}
//=============================================================================
void TimeProcess() {
  static uint8_t timer5ms = 0;
  static uint16_t second = 0;
	uint16_t temp1,temp2,temp3,temp4;
  if (b1ms) {
    // 1ms 执行一次
    b1ms = 0;
    timer5ms++;
    second++;
  }
  if (timer5ms >= D_5ms) {
	/*temp1 = P1MODH;
	temp2 = P3MODL;
	temp3 = P3MODH;
	temp4 = P1MODL;
	//1.7
	P1MODH = 0x00;
	//3.2
	P3MODL = 0x00;
	//3.4
	P3MODH = 0x00;
	//1.2
	P1MODL = 0x00;*/
	P1MODL = P1MODL&0xCF;
  GetKeys();
	/*P1MODH = temp1;
	P3MODL = temp2;
	P3MODH = temp3;
	P1MODL = temp4;*/
  //F_buzz();

  }
  if (second >= D_1000ms) {
    // 1s 执行一次
		
    second = 0;
  }
}
//=============================================================================
void TaskProcess() {}
//=============================================================================
void TaskSetting() {
  // delayMs(1000);
    if (modeValue == 1){//模式标志为1时，该模式为推挽输出
		//LED状态转换
		if(D_keyValue1 == keyValue){
			modeValue = ~modeValue;		//模式标志为取反
		}
		P1MODL = 0xE0;		//将模式置为推挽输出，使LED显示
		}
	else {
	//否则，该模式为上拉输入
			if(D_keyValue1 == keyValue){
				modeValue = ~modeValue;	
			}
		}
}
//=============================================================================
void DisplayProcess() {
  F_led2On();
	F_led1On();
}