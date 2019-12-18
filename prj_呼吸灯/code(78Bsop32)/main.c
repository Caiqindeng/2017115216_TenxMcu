#define __main_c
#include "includeAll.h"

int times = 0;   // 定义一个times变量用于表示LedOn时的延时时间
int flag = 1;    // flag = 1 表示led由暗逐渐变到亮

//================================main主函数========================================
void main() {
	SysInit();				// 芯片的系统初始化
	F_turnOnWDT();   	// 使能看门狗
	F_ledOff();
	
  while (1) {
		F_clearWDT();		    // 清除看门狗
		breathingLight();		// 实现呼吸灯
		F_ledOff();
  }
}
//==================================================================================

//===============================定义呼吸灯函数=====================================
void breathingLight() {
	
  if (b4ms == 1) {
    b4ms = 0;
    timer4ms++;
    timer250ms++;
    timer1s++;
	}
	
  if (timer4ms >= D_4ms) {
    timer4ms = 0;
    
    if(times > 300){
      times = 300;
      flag = 0;  	// flag = 0 表示led由亮逐渐变暗      
    }

    if(times < 0){
      times = 0;
      flag = 1; 	// flag = 1 表示led由暗逐渐变亮
    } 

		//times的初始值为0，通过times值得累加实现led由暗逐渐变亮，又通过times值的递减实现led由亮逐渐变暗      
		F_ledOn();
		Delay(times);
		F_ledOff();
		Delay(1000);
		
		//前300次循环，均为led由暗逐渐变亮的过程
		if(times <= 300 && flag == 1){
			times += 1;
		}
		
		//执行到第301次时，flag的 值被修改为0，此后为led由亮逐渐变暗的过程
		if(times <= 300 && flag == 0){
			times -= 1;
		}
  }

  if (timer250ms >= D_250ms) {
    timer250ms = 0;
  }

  if (timer1s >= D_1s) {
    timer1s = 0;
    timer1m++;
    if (timer1m >= D_1m) {
      timer1m = 0;
      timer1h++;
      if (timer1h >= D_1h) {
        timer1h = 0;
      }
    }
  }
}
//==============================================================================

//===============================定义LED灯的延时函数==================================
void Delay(int time) {
  int i;
  for (i = 0; i < time; i++)
    CLRWDT = 1;
}
//==============================================================================

