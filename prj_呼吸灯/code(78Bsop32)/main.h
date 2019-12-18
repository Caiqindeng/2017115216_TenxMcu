#ifndef __main_h
#define __main_h

// 定义基准时间
//基准时间 4ms
#define D_4ms  4
#define D_250ms  250
#define D_1s   1000

//基准时间 1s
#define D_1m   60

//基准时间 1m
#define D_1h   60


// Globle Var -----------------------------------------
#ifdef __main_c

    bit b4ms;
    uint8_t timer1Click, timer4ms, timer250ms, timer1s, timer1m, timer1h;
#else
    extern bit b4ms;
    extern uint8_t  timer1Click, timer4ms, timer250ms, timer1s, timer1m, timer1h;
#endif

void breathingLight();    // 呼吸灯函数
void Delay(int time);     // 延时函数


#endif