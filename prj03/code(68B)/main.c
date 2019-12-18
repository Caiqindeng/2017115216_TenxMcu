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
  while (1) {
    //喂狗
    F_clearWDT();
    TimeProcess();
    TaskSetting();
  }
}
//=============================================================================
void TimeProcess() {
 F_buzz();
 F_led1On();
 F_led2On(); 
 Delay(100000);
  F_buzz();
 F_led1Off();
 F_led2Off();
}
//=============================================================================
void TaskProcess() {}
//=============================================================================
void TaskSetting() {
 
}
//=============================================================================
void DisplayProcess() {
  // F_ledOn();
}
//=============================================================================
void Delay(unsigned  int t){
  while (--t)
  {
    ;/* code */;
  }
  
}