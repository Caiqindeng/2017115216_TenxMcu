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