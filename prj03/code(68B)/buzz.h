#ifndef __buzz_h
    #define __buzz_h
//HAL--------------------
	#buzzH1
    #define F_buzz()        P_buzz = ~P_buzz
//Const--------------------
    #define D_buzzLastTime  25    //30*4ms(T0) = last 100ms per Buzz
	#define D_buzzConvertAdTime 200 //200*4ms(T0) = reuse Pin convert to Ad mode
//Var----------------------
    #ifdef __buzz_c
        uint8_t buzzLastTimer ;
        uint8_t buzzConvertAdTimer ;
        uint8_t buzzCounter ;
		bit bBuzz ;
    #else
        extern uint8_t buzzLastTimer ;
        extern uint8_t buzzConvertAdTimer ;
        extern uint8_t buzzCounter ;
		extern bit bBuzz ;
    #endif

//Function----------------------
	void Buzz(void) ;
#endif
