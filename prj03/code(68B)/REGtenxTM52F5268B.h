/*
******************************************************************************************************
Name		:TM52M5268B_64B.h
Version		:V1.1
Author		:
Date		:2015.08.06
Modify      :2.PWM1RPD -> PWM1PRD
             1.TT0 -> IT0
******************************************************************************************************
*/
#ifndef __TM52F5268_H__
#define __TM52F5268_H__

sfr     P0      =0x80;
	sbit 		P0_7		= P0^7;
	sbit 		P0_6		= P0^6;
	sbit 		P0_5		= P0^5;
	sbit 		P0_4		= P0^4;
	sbit 		P0_3		= P0^3;
	sbit 		P0_2		= P0^2;
	sbit 		P0_1		= P0^1;
	sbit 		P0_0		= P0^0;


sfr     SP      =0x81;
sfr     DPL     =0x82;
sfr     DPH     =0x83;
sfr 	PCON  		= 0x87;			//²»Ö§³ÖÎ»²Ù×÷,ÓÃ¶Á¸ÄÐ´·½Ê½
	//--------------------------------------------------------------------------------------------
	#define 	SMOD	0x80		//PCON Bit[7],1=²¨ÌØÂÊ±¶Ôö
	//--------------------------------------------------------------------------------------------
	#define 	GF1		0x08		//PCON Bit[3],ÓÃ»§¿ÉÒÔËæ±ãÊ¹ÓÃ
	#define 	GF0		0x04		//PCON Bit[2],ÓÃ»§¿ÉÒÔËæ±ãÊ¹ÓÃ
	//--------------------------------------------------------------------------------------------
	#define 	PD		0x02		//PCON Bit[1],´ËÎ»ÖÃ1,Ð¾Æ¬½øÈëstopÄ£Ê½
	//--------------------------------------------------------------------------------------------
	#define 	IDL		0x01		//PCON Bit[0],´ËÎ»ÖÃ1,Ð¾Æ¬½øÈëIDLÄ£Ê½
	//---------------------------------------------------------------------------------------------
	#define		ENTER_IDLE_MODE		PCON=(PCON&0xfe)|IDL
	#define		LEAVE_IDLE_MODE		PCON=(PCON&0xfe)
	#define		ENTER_STOP_MODE		PCON=(PCON&0xfd)|PD
	#define		LEAVE_STOP_MODE		PCON=(PCON&0xfd)

//---------------------------
sfr     TCON    =0x88;
	//--------------------------------------------------------------------------------------------
	sbit 		TF1 		= TCON^7;	//¶¨Ê±Æ÷T1Òç³ö±êÖ¾,¿ÉÓÉ³ÌÐò²éÑ¯ºÍÇåÁã,TF1Ò²ÊÇÖÐ¶ÏÇëÇóÔ´,µ±CPUÏìÓ¦T1ÖÐ¶ÏÊ±ÓÉÓ²¼þÇåÁã
	sbit 		TR1 		= TCON^6;	//T1³äÐí¼ÆÊý¿ØÖÆÎ»,Îª1Ê±³äÐíT1¼ÆÊý
	//--------------------------------------------------------------------------------------------
	sbit 		TF0 		= TCON^5;	//¶¨Ê±Æ÷T0Òç³ö±êÖ¾,¿ÉÓÉ³ÌÐò²éÑ¯ºÍÇåÁã,TF0Ò²ÊÇÖÐ¶ÏÇëÇóÔ´,µ±CPUÏìÓ¦T0ÖÐ¶ÏÊ±ÓÉÓ²¼þÇåÁã
	sbit 		TR0			= TCON^4;	//T0³äÐí¼ÆÊý¿ØÖÆÎ»,Îª1Ê±³äÐíT0¼ÆÊý
	//--------------------------------------------------------------------------------------------
	sbit 		IE1 		= TCON^3;	//Íâ²¿ÖÐ¶Ï1ÇëÊ¾Ô´(INT1,P3.3)±êÖ¾;IE1Ò²ÊÇÖÐ¶ÏÇëÇóÔ´,µ±CPUÏìÓ¦¸ÃÖÐ¶ÏÊ±ÓÉÓ²¼þÇåIE1(±ßÑØ´¥·¢·½Ê½)
	sbit 		IT1 		= TCON^2;	//Íâ²¿ÖÐ¶ÏÔ´1´¥·¢·½Ê½¿ØÖÆÎ»,IT1£½0,Íâ²¿ÖÐ¶Ï1³Ì¿ØÎªµçÆ½´¥·¢·½Ê½;µ±INT1£¨P3.3£©ÊäÈëµÍµçÆ½Ê±,ÖÃÎ»IE1
	//--------------------------------------------------------------------------------------------
	sbit 		IE0 		= TCON^1;	//Íâ²¿ÖÐ¶Ï0ÇëÊ¾Ô´(INT1,P3.2)±êÖ¾;IE0Ò²ÊÇÖÐ¶ÏÇëÇóÔ´,µ±CPUÏìÓ¦¸ÃÖÐ¶ÏÊ±ÓÉÓ²¼þÇåIE0(±ßÑØ´¥·¢·½Ê½)
	sbit 		IT0 		= TCON^0;	//Íâ²¿ÖÐ¶ÏÔ´0´¥·¢·½Ê½¿ØÖÆÎ»,IT0£½0,Íâ²¿ÖÐ¶Ï0³Ì¿ØÎªµçÆ½´¥·¢·½Ê½;µ±INT0£¨P3.2£©ÊäÈëµÍµçÆ½Ê±,ÖÃÎ»IE0

sfr     TMOD    =0x89;
	//--------------------------------------------------------------------------------------------
	#define 	T1Mask		0xf0		//T1¹¤×÷Ä£Ê½Ñ¡ÔñMask
	//--------------------------------------------------------------------------------------------
	#define 	GATE1		0x80		//¶¨Ê±Æ÷1²Ù×÷¿ª¹Ø¿ØÖÆÎ»
					 	 	//µ±GATE1=1Ê±,INT1Òý½ÅÎª¸ßµçÆ½,Í¬Ê±TCONÖÐµÄTR1¿ØÖÆÎ»Îª1Ê±,¼ÆÊ±/¼ÆÊýÆ÷1²Å¿ªÊ¼¹¤×÷
					 	 	//µ±GATE1=0Ê±,ÔòÖ»Òª½«TR1¿ØÖÆÎ»ÉèÎª1£¬¼ÆÊ±/¼ÆÊýÆ÷1¾Í¿ªÊ¼¹¤×÷
	#define 	CT1		0x40		//¶¨Ê±/¼ÆÊýÆ÷1¹¦ÄÜµÄÑ¡ÔñÎ»
					 	 	//CT1=1Îª¼ÆÊýÆ÷,Í¨¹ýÍâ²¿Òý½ÅT1ÊäÈë¼ÆÊýÂö³å
					 	 	//CT1=0Îª¶¨Ê±Æ÷,ÓÉÄÚ²¿ÏµÍ³Ê±ÖÓÌá¹©¼ÆÊ±¹¤×÷Âö³å
	//--------------------------------------------------------------------------------------------
	#define 	T1M0		0x00		//T1Îª13Î»¼ÆÊ±/¼ÆÊýÆ÷
	#define 	T1M1		0x10		//T1Îª16Î»¼ÆÊ±/¼ÆÊýÆ÷
	#define 	T1M2		0x20		//T1Îª8Î»×Ô¶¯¼ÓÔØ¼ÆÊý/¼ÆÊ±Æ÷ 
	#define 	T1M3		0x30		//²»´æÔÚ
	//--------------------------------------------------------------------------------------------
	#define 	T0Mask		0x0f		//T0¹¤×÷Ä£Ê½Ñ¡ÔñMask
	//--------------------------------------------------------------------------------------------
	#define 	GATE0		0x08		//¶¨Ê±Æ÷0²Ù×÷¿ª¹Ø¿ØÖÆÎ»
					 	 	//µ±GATE0=1Ê±,INT0Òý½ÅÎª¸ßµçÆ½,Í¬Ê±TCONÖÐµÄTR0¿ØÖÆÎ»Îª1Ê±,¼ÆÊ±/¼ÆÊýÆ÷0²Å¿ªÊ¼¹¤×÷
					 	 	//µ±GATE0=0Ê±,ÔòÖ»Òª½«TR0¿ØÖÆÎ»ÉèÎª1£¬¼ÆÊ±/¼ÆÊýÆ÷0¾Í¿ªÊ¼¹¤×÷
	#define 	CT0		0x04		//¶¨Ê±/¼ÆÊýÆ÷0¹¦ÄÜµÄÑ¡ÔñÎ»
					 	 	//CT0=1Îª¼ÆÊýÆ÷,Í¨¹ýÍâ²¿Òý½ÅT0ÊäÈë¼ÆÊýÂö³å
					 	 	//CT0=0Îª¶¨Ê±Æ÷,ÓÉÄÚ²¿ÏµÍ³Ê±ÖÓÌá¹©¼ÆÊ±¹¤×÷Âö³å
	//--------------------------------------------------------------------------------------------
	#define 	T0M0		0x00		//T0Îª13Î»¼ÆÊ±/¼ÆÊýÆ÷ 
	#define 	T0M1		0x01		//T0Îª16Î»¼ÆÊ±/¼ÆÊýÆ÷ 
	#define 	T0M2		0x02		//T0Îª8Î»×Ô¶¯¼ÓÔØ¼ÆÊý/¼ÆÊ±Æ÷
	#define 	T0M3		0x03		//½öÊÊÓÃÓÚT0,T0·ÖÎªÁ½¸ö¶ÀÁ¢µÄ8Î»¶¨Ê±Æ÷/¼ÆÊýÆ÷TH0¼°TL0,ÔÚ´ËÄ£Ê½ÏÂT1Í£Ö¹¹¤×÷
sfr     TL0     =0x8a;
sfr     TL1     =0x8b;
sfr     TH0     =0x8c;
sfr     TH1     =0x8d;
//---------------------------
sfr     P1      =0x90;
sbit    P1_7    = P1^7;
sbit    P1_6    = P1^6;
sbit    P1_5    = P1^5;
sbit    P1_4    = P1^4;
sbit    P1_3    = P1^3;
sbit    P1_2    = P1^2;			  
sbit    P1_1    = P1^1;
sbit    P1_0    = P1^0;
/*
******************************************************************************************************
*/
sfr		P0OE		= 0x91;				//P0 CMOS Push-Pull Output Enable (1=Enable)

/*
******************************************************************************************************
*/
sfr		P2MOD		= 0x93;				//P2  
	//--------------------------------------------------------------------------------------------
	//P2MOD1:P2MOD Bit[3:2],P2.1 Pin Mode Control
	#define		P21MOD_Mask		~0x0c
	#define		P21MOD_0		0x00
	#define		P21MOD_1		0x04
	#define		P21MOD_2		0x08
	#define		P21MOD_3		0x0C
	//--------------------------------------------------------------------------------------------
	//P2MOD0:P2MOD Bit[1:0],P2.0 Pin Mode Control
	#define		P20MOD_Mask		~0x03
	#define		P20MOD_0		0x00
	#define		P20MOD_1		0x01
	#define		P20MOD_2		0x02
	#define		P20MOD_3		0x03
/*
******************************************************************************************************
*/
sfr     OPTION  =0x94;
	//--------------------------------------------------------------------------------------------
	#define 	UART1W		0x80		//One wire UART, both TXD/RXD use P3.1 pin
	//--------------------------------------------------------------------------------------------
	#define 	MODE3 		0x40		//mode 3v
	//--------------------------------------------------------------------------------------------
	#define		WDTPSC_1	 	0x00	  //Watch Dog Timer Prescale 3=Fastest   
	#define		WDTPSC_2		0x10		//Watch Dog Timer Prescale 3=Fastest   
	#define		WDTPSC_3 		0x20		//Watch Dog Timer Prescale 3=Fastest   
	#define		WDTPSC_4 		0x30		//Watch Dog Timer Prescale 3=Fastest  

	#define		WDTPSC_00		0x00	  	//Watch Dog Timer Prescale 0  
	#define		WDTPSC_01		0x10		//Watch Dog Timer Prescale 1   
	#define		WDTPSC_02 		0x20		//Watch Dog Timer Prescale 2   
	#define		WDTPSC_03		0x30		//Watch Dog Timer Prescale 3
	
	#define  	WDTPSC0    OPTION=OPTION&0xcf			//360ms WDT overflow rate 
	#define  	WDTPSC1    OPTION=(OPTION&0xcf)|0x10	//180ms WDT overflow rate 
	#define  	WDTPSC2    OPTION=(OPTION&0xcf)|0x20	//90ms WDT overflow rate  
	#define  	WDTPSC3    OPTION=(OPTION&0xcf)|0x30	//45ms WDT overflow rate    
	//--------------------------------------------------------------------------------------------
	#define 	AdcClk_32	0x00		//ADC Clock Rate:SysClk/32
	#define 	AdcClk_16	0x04		//ADC Clock Rate:SysClk/16
	#define 	AdcClk_8	0x08		//ADC Clock Rate:SysClk/8
	#define 	AdcClk_4	0x0C		//ADC Clock Rate:SysClk/4
  	
	#define 	AdcClk32	OPTION=OPTION&0xf3		//ADC Clock Rate:SysClk/32
	#define 	AdcClk16	OPTION=(OPTION&0xf3)|0x04		//ADC Clock Rate:SysClk/16
	#define 	AdcClk8		OPTION=(OPTION&0xf3)|0x08		//ADC Clock Rate:SysClk/8
	#define 	AdcClk4		OPTION=(OPTION&0xf3)|0x0C		//ADC Clock Rate:SysClk/4
	//--------------------------------------------------------------------------------------------
	#define 	TM3_InterruptIsCountDataOverflow	0x00		
	#define 	TM3_InterruptIs1SecondRate			0x01		
	#define 	TM3_InterruptIs1_2SecondRate		0x02		
	#define 	TM3_InterruptIs1_4SecondRate		0x03

	#define 	TM3PscClk32768	OPTION=OPTION&0xfc		
	#define 	TM3PscClk16384	OPTION=(OPTION&0xfc)|0x01		
	#define 	TM3PscClk8192	OPTION=(OPTION&0xfc)|0x02		
	#define 	TM3PscClk128	OPTION=(OPTION&0xfc)|0x03



sfr     INTFLG  =0x95;
	//--------------------------------------------------------------------------------------------
	#define		LVD		0x80		//Low Voltage Detect Flag
	//--------------------------------------------------------------------------------------------
	#define		TKIF	0x20		//Touch Key ÖÐ¶Ï±êÖ¾£¬HW clear while TKSOC set
	//--------------------------------------------------------------------------------------------
	#define		ADIF	0x10		//ADC ÖÐ¶Ï±êÖ¾£¬HW clear while ADSOC set
	//--------------------------------------------------------------------------------------------
	#define		IE2		0x04		//INT2 ÖÐ¶Ï±êÖ¾£¬1=Íâ²¿ÖÐ¶Ï2ÖÐ¶Ï
	//--------------------------------------------------------------------------------------------
	#define 	P1IF	0x02		//P1¶Ë¿ÚÖÐ¶Ï±êÖ¾£¬1=P1¶Ë¿ÚÖÐ¶Ï
	//--------------------------------------------------------------------------------------------
	#define 	TF3		0x01		//TM3ÖÐ¶Ï±êÖ¾,1=TM3ÖÐ¶Ï
sfr     P1WKUP  =0x96;
	#define		P1WKUP_Mask			~0xff	   	//P1¶Ë¿ÚÖÐ¶Ï»½ÐÑÉèÖÃMask
	#define		P1WKUP_AllEnable	0xff		//P1ËùÓÐ¶Ë¿ÚÖÐ¶Ï»½ÐÑÆôÓÃ
	#define		P1WKUP_P10Enable	0x01		//P10¶Ë¿ÚÖÐ¶Ï»½ÐÑÆôÓÃ
	#define		P1WKUP_P11Enable	0x02		//P11¶Ë¿ÚÖÐ¶Ï»½ÐÑÆôÓÃ
	#define		P1WKUP_P12Enable	0x04		//P12¶Ë¿ÚÖÐ¶Ï»½ÐÑÆôÓÃ
	#define		P1WKUP_P13Enable	0x08		//P13¶Ë¿ÚÖÐ¶Ï»½ÐÑÆôÓÃ
	#define		P1WKUP_P14Enable	0x10		//P14¶Ë¿ÚÖÐ¶Ï»½ÐÑÆôÓÃ
	#define		P1WKUP_P15Enable	0x20		//P15¶Ë¿ÚÖÐ¶Ï»½ÐÑÆôÓÃ
	#define		P1WKUP_P16Enable	0x40		//P16¶Ë¿ÚÖÐ¶Ï»½ÐÑÆôÓÃ
	#define		P1WKUP_P17Enable	0x80		//P17¶Ë¿ÚÖÐ¶Ï»½ÐÑÆôÓÃ
/*
******************************************************************************************************
*/
sfr		SWCMD		= 0x97;

//---------------------------
sfr     SCON    =0x98;
	//--------------------------------------------------------------------------------------------
	sbit 		SM0 		= SCON^7;	//´®ÐÐ¿Ú¹¤×÷·½Ê½¿ØÖÆÎ»
	sbit 		SM1 		= SCON^6;	//[SM0:SM1]=
	#define		Uart_ModeMask	~0xC0	//´®¿ÚÄ£Ê½Mask
	#define		Uart_Mode0		0x00	//00 ·½Ê½0£­²¨ÌØÂÊÓÉÕñµ´Æ÷ÆµÂÊËù¶¨:Õñµ´Æ÷ÆµÂÊ/12
	#define		Uart_Mode1		0x40	//01 ·½Ê½1£­²¨ÌØÂÊÓÉ¶¨Ê±Æ÷T1»òT2µÄÒç³öÂÊºÍSMODËù¶¨:2SMOD*(T1Òç³öÂÊ)/32
	#define		Uart_Mode2		0x80 	//10 ·½Ê½2£­²¨ÌØÂÊÓÉÕñµ´Æ÷ÆµÂÊºÍSMODËù¶¨:2SMOD*Õñµ´Æ÷ÆµÂÊ/64
	#define		Uart_Mode3		0xc0 	//11 ·½Ê½3£­²¨ÌØÂÊÓÉ¶¨Ê±Æ÷T1»òT2µÄÒç³öÂÊºÍSMODËù¶¨:2SMOD*(T1Òç³öÂÊ)/32
							
	//--------------------------------------------------------------------------------------------
	sbit 		SM2 		= SCON^5;	//¶à»úÍ¨ÐÅ¿ØÖÆÎ»*/
							//¶à»úÍ¨ÐÅÊÇ¹¤×÷ÓÚ·½Ê½2ºÍ·½Ê½3£¬SM2Î»Ö÷ÒªÓÃÓÚ·½Ê½2ºÍ·½Ê½3½ÓÊÕ×´Ì¬
					 	 	//µ±´®ÐÐ¿Ú¹¤×÷ÓÚ·½Ê½2»ò3:
					 	 	//µ±SM2=1Ê±,Ö»ÓÐµ±½ÓÊÕµ½µÚ9Î»Êý¾Ý(RB8)Îª1Ê±,²Å°Ñ½ÓÊÕµ½µÄÇ°8Î»Êý¾ÝËÍÈëSBUF,ÇÒÖÃÎ»RI·¢³öÖÐ¶ÏÉêÇë,·ñÔò»á½«½ÓÊÕµ½µÄÊý¾Ý·ÅÆú
					 	 	//µ±SM2=0Ê±,¾Í²»¹ÜµÚ9Î»Êý¾ÝÊÇ0»¹ÊÇ1,¶¼µÃÊý¾ÝËÍÈëSBUF,²¢·¢³öÖÐ¶ÏÉêÇë,¹¤×÷ÓÚ·½Ê½0Ê±£¬SM2±ØÐëÎª0
	//--------------------------------------------------------------------------------------------
	sbit 		REN 		= SCON^4;	//ÔÊÐí½ÓÊÕÎ»:
					 	 	//RENÓÃÓÚ¿ØÖÆÊý¾Ý½ÓÊÕµÄÔÊÐíºÍ½ûÖ¹,REN=1Ê±,ÔÊÐí½ÓÊÕ,REN=0Ê±,½ûÖ¹½ÓÊÕ
	//--------------------------------------------------------------------------------------------
	sbit 		TB8 		= SCON^3;	//·¢ËÍÊý¾ÝµÚ8Î»
	sbit 		RB8 		= SCON^2;	//½ÓÊÕÊý¾ÝµÚ8Î»
	//--------------------------------------------------------------------------------------------
	sbit 		TI 		= SCON^1;	//·¢ËÍÖÐ¶Ï±êÖ¾Î»£º
					 	 	//·½Ê½0Ê±,·¢ËÍÍêµÚ8Î»Êý¾Ýºó,ÓÉÓ²¼þÖÃÎ»
					 	 	//ÆäËü·½Ê½ÏÂ,ÓÉÓ²¼þÖÃÎ»,TI=1±íÊ¾Ö¡·¢ËÍ½áÊø,TI¿ÉÓÉÈí¼þÇåÁã
	//--------------------------------------------------------------------------------------------
	sbit 		RI 		= SCON^0;	//½ÓÊÕÖÐ¶Ï±êÖ¾Î»£º
					 	 	//·½Ê½0Ê±,½ÓÊÕÍêµÚ8Î»Êý¾Ýºó,ÓÉÓ²¼þÖÃÎ»
					 	 	//ÆäËü·½Ê½ÏÂ,ÓÉÓ²¼þÖÃÎ»,RI=1±íÊ¾Ö¡½ÓÊÕÍê³É
	
sfr     SBUF    =0x99;
sfr     PWM0PRD =0x9a;
sfr     PWM0DH  =0x9b;
sfr     PWM1PRD =0x9c;
sfr     PWM1DH  =0x9d;

//---------------------------
sfr     P2      =0xa0;
	sbit 		P2_5		= P2^5;	
	sbit 		P2_4		= P2^4;	
	sbit 		P2_3		= P2^3;	
	sbit 		P2_2		= P2^2;	
	sbit 		P2_1		= P2^1;	
	sbit 		P2_0		= P2^0;	

sfr     PWMCON  =0xa1;
	//--------------------------------------------------------------------------------------------
	#define		PWM1CKS_16M	0xC0		//PWM1 clock =FRC Double frequence
	#define		PWM1CKS_Div1	0x80            //PWM1 clock =SysClk/1
	#define		PWM1CKS_Div2	0x40            //PWM1 clock =SysClk/2
	#define		PWM1CKS_Div4	0x00            //PWM1 clock =SysClk/4
	//--------------------------------------------------------------------------------------------
	// PWM1DL  (bit5~bit4) 
	//--------------------------------------------------------------------------------------------                                              //
	#define		PWM0CKS_16M		0x0C		//PWM0 clock =FRC Double frequence
	#define		PWM0CKS_Div1	0x08            //PWM0 clock =SysClk/1
	#define		PWM0CKS_Div2	0x04            //PWM0 clock =SysClk/2
	#define		PWM0CKS_Div4	0x00            //PWM0 clock =SysClk/4
sfr     P1MODL  =0xa2;
	//--------------------------------------------------------------------------------------------
	//P1MOD3:P1MODL Bit[7:6],P1.3 Pin Mode Control
	#define		P13MOD_Mask		~0xc0
	#define		P13MOD_0		0x00
	#define		P13MOD_1		0x40
	#define		P13MOD_2		0x80
	#define		P13MOD_3		0xC0
	//--------------------------------------------------------------------------------------------
	//P1MOD2:P1MODL Bit[5:4],P1.2 Pin Mode Control
	#define		P12MOD_Mask		~0x30
	#define		P12MOD_0		0x00
	#define		P12MOD_1		0x10
	#define		P12MOD_2		0x20
	#define		P12MOD_3		0x30
	//--------------------------------------------------------------------------------------------
	//P1MOD1:P1MODL Bit[3:2],P1.1 Pin Mode Control
	#define		P11MOD_Mask		~0x0C
	#define		P11MOD_0		0x00
	#define		P11MOD_1		0x04
	#define		P11MOD_2		0x08
	#define		P11MOD_3		0x0C
	//--------------------------------------------------------------------------------------------
	//P1MOD0:P1MODL Bit[1:0],P1.0 Pin Mode Control
	#define		P10MOD_Mask		~0x03
	#define		P10MOD_0		0x00
	#define		P10MOD_1		0x01
	#define		P10MOD_2		0x02
	#define		P10MOD_3		0x03
sfr     P1MODH  =0xa3;
	//--------------------------------------------------------------------------------------------
	//P1MOD7:P1MODH Bit[7:6],P1.7 Pin Mode Control
	#define		P17MOD_Mask		~0xc0
	#define		P17MOD_0		0x00
	#define		P17MOD_1		0x40
	#define		P17MOD_2		0x80
	#define		P17MOD_3		0xc0
	//--------------------------------------------------------------------------------------------
	//P1MOD6:P1MODH Bit[5:4],P1.6 Pin Mode Control
	#define		P16MOD_Mask		~0x30
	#define		P16MOD_0		0x00
	#define		P16MOD_1		0x10
	#define		P16MOD_2		0x20
	#define		P16MOD_3		0x30
	//--------------------------------------------------------------------------------------------
	//P1MOD5:P1MODH Bit[3:2],P1.5 Pin Mode Control
	#define		P15MOD_Mask		~0x0c
	#define		P15MOD_0		0x00
	#define		P15MOD_1		0x04
	#define		P15MOD_2		0x08
	#define		P15MOD_3		0x0c
	//--------------------------------------------------------------------------------------------
	//P1MOD4:P1MODH Bit[1:0],P1.4 Pin Mode Control
	#define		P14MOD_Mask		~0x03
	#define		P14MOD_0		0x00
	#define		P14MOD_1		0x01
	#define		P14MOD_2		0x02
	#define		P14MOD_3		0x03
sfr     P3MODL  =0xa4;
	//--------------------------------------------------------------------------------------------
	//P3MOD3:P3MODL Bit[7:6],P3.3 Pin Mode Control
	#define		P33MOD_Mask		~0xc0
	#define		P33MOD_0		0x00
	#define		P33MOD_1		0x40
	#define		P33MOD_2		0x80
	#define		P33MOD_3		0xc0
	//--------------------------------------------------------------------------------------------
	//P3MOD2:P3MODL Bit[5:4],P3.2 Pin Mode Control
	#define		P32MOD_Mask		~0x30
	#define		P32MOD_0		0x00
	#define		P32MOD_1		0x10
	#define		P32MOD_2		0x20
	#define		P32MOD_3		0x30
	//--------------------------------------------------------------------------------------------
	//P3MOD1:P3MODL Bit[3:2],P3.1 Pin Mode Control
	#define		P31MOD_Mask		~0x0c
	#define		P31MOD_0		0x00
	#define		P31MOD_1		0x04
	#define		P31MOD_2		0x08
	#define		P31MOD_3		0x0c
	//--------------------------------------------------------------------------------------------
	//P3MOD0:P3MODL Bit[1:0],P3.0 Pin Mode Control
	#define		P30MOD_Mask		~0x03
	#define		P30MOD_0		0x00
	#define		P30MOD_1		0x01
	#define		P30MOD_2		0x02
	#define		P30MOD_3		0x03
sfr     P3MODH  =0xa5;	
	//--------------------------------------------------------------------------------------------
	//T0OE:P3MODH Bit[7],"Timer0 overflow divided by 64"signal output to P3.4 pin
	#define		T0OE    		0x80
	//--------------------------------------------------------------------------------------------
	//P3MOD6:P3MODH Bit[5:4],P3.6 Pin Mode Control
	#define		P36MOD_Mask		~0x30
	#define		P36MOD_0		0x00
	#define		P36MOD_1		0x10
	#define		P36MOD_2		0x20
	#define		P36MOD_3		0x30
	//--------------------------------------------------------------------------------------------
	//P3MOD5:P3MODH Bit[3:2],P3.5 Pin Mode Control
	#define		P35MOD_Mask		~0x0c
	#define		P35MOD_0		0x00
	#define		P35MOD_1		0x04
	#define		P35MOD_2		0x08
	#define		P35MOD_3		0x0c
	//--------------------------------------------------------------------------------------------
	//P3MOD4:P3MODH Bit[1:0],P3.4 Pin Mode Control
	#define		P34MOD_Mask		~0x03
	#define		P34MOD_0		0x00
	#define		P34MOD_1		0x01
	#define		P34MOD_2		0x02
	#define		P34MOD_3		0x03
sfr     PINMOD  =0xa6;
	#define		PWM1AOE		0x80//Set to enable PWM1A and signal output to P1.3 pin
	#define		PWM0AOE		0x20//Set to enable PWM0A and signal output to P1.2 pin
	#define		TCOE		  0x08//Set to output "Instruction Cycle Clock " signal to P1.4 pin
	#define		T2OE		  0x04//Set to output "Timer2 overflow divided by 2" signal to P1.0 pin
	
	#define		PWM1OE_ENABLE 	PINMOD=(PINMOD&0x7f)|PWM1AOE
	#define		PWM1OE_DISABLE	PINMOD=(PINMOD&0x7f)
	#define		PWM0OE_ENABLE	PINMOD=(PINMOD&0xdf)|PWM0AOE
	#define		PWM0OE_DISABLE	PINMOD=(PINMOD&0xdf)
	#define		TCOE_ENABLE		PINMOD=(PINMOD&0xf7)|TCOE
	#define		TCOE_DISABLE	PINMOD=(PINMOD&0xf7)
	#define		T2OE_ENABLE		PINMOD=(PINMOD&0xfb)|T2OE
	#define		T2OE_DISABLE	PINMOD=(PINMOD&0xfb)
//---------------------------	
sfr     IE      =0xa8;
	//--------------------------------------------------------------------------------------------
	sbit 		EA 			= IE^7;		//EA=0Ê±,ËùÓÐÖÐ¶Ï½ûÖ¹;EA=1Ê±,¸÷ÖÐ¶ÏµÄ²úÉúÓÉ¸ö±ðµÄÔÊÐíÎ»¾ö¶¨
	sbit 		ET2 		= IE^5;		//¶¨Ê±Æ÷2ÖÐ¶Ï³äÐí
	sbit 		ES 			= IE^4;		//´®ÐÐ¿ÚÖÐ¶Ï³äÐí(ES=1³äÐí,ES=0½ûÖ¹)
	sbit 		ET1 		= IE^3;		//¶¨Ê±Æ÷1ÖÐ¶Ï³äÐí
	sbit 		EX1 		= IE^2;		//ÍâÖÐ¶ÏINT1ÖÐ¶Ï³äÐí
	sbit 		ET0 		= IE^1;		//¶¨Ê±Æ÷0ÖÐ¶Ï³äÐí
	sbit 		EX0 		= IE^0;		//Íâ²¿ÖÐ¶ÏINT0µÄÖÐ¶ÏÔÊÐí
	
sfr     INTE1   =0xa9;		
    //-------------------------------------------------------------------------------------------------------
	//IAPÐ´Ê¹ÄÜ-->INTE1=(INTE1&~IAPWE_Mask)|IAPWE_En;(½ö½öÐ´ÐèÒª)
	//IAPÐ´½ûÖ¹-->INTE1=(INTE1&~IAPWE_Mask)|IAPWE_Dis;
	
	#define 	IAPWE_Mask	0xE0
	#define 	IAPWE_En	0xA0
	#define 	IAPWE_Dis	0x00
	//--------------------------------------------------------------------------------------------
	#define		SPIE		0x10		//SPI ÖÐ¶ÏÔÊÐí
	//--------------------------------------------------------------------------------------------
	#define		ADTKIE  0x08		//ADC/Touch Key  ÖÐ¶ÏÔÊÐí
	//--------------------------------------------------------------------------------------------
	#define		EX2			0x04		//INT2 ÖÐ¶ÏÔÊÐí¡¢Stop Mode »½ÐÑ¹¦ÄÜÆôÓÃ
	//--------------------------------------------------------------------------------------------
	#define	  P1IE		0x02		//P1¶Ë¿ÚÖÐ¶ÏÔÊÐí
	//--------------------------------------------------------------------------------------------
	#define		TM3IE		0x01		//TM3ÖÐ¶ÏÔÊÐí		
sfr     ADTKDT  =0xaa;		
	//--------------------------------------------------------------------------------------------
	//ADCDL:ADTKDT Bit[7:4],ADC Data LSB 3~0
	#define		TKEOC		0x08		//Touch Key End of Conversion
	#define		TKOVF		0x04		//Touch Key Counter Overflow
	//--------------------------------------------------------------------------------------------
	//TKDH:ADTKDT Bit[1:0],Touch Key Data MSB 9~8
sfr     ADCDH   =0xab;
sfr     TKDL    =0xac;
sfr     TKCON   =0xad;
	//--------------------------------------------------------------------------------------------
	//TKPD:TKCON Bit[7],Touch Key Power Down
	#define		TKPD		0x80		//0: Touch Key Running ;1: Touch Key Power Down
	//--------------------------------------------------------------------------------------------
	//TKTMR:TKCON Bit[2:0],Touch Key Conversion Time
	#define		TKTMR_Mask		 ~0x07		//TKTMR_Mask
	#define		TKTMR_short    0x00		  //shortest
//...
	#define		TKTMR_long     0x07		  //longest
sfr     CHSEL   =0xae;
	//--------------------------------------------------------------------------------------------
	//ADCHS:CHSEL Bit[7:4],ADC Channel Select
                 //0000: AD0 (P3.3)
                 //0001: AD1 (P3.2)
                 //0010: AD2 (P3.1)
                 //0011: AD3 (P3.0)
                 //0100: AD4 (P1.0)
                 //0101: AD5 (P1.1)
                 //0110: AD6 (P1.2)
                 //0111: AD7 (P1.3)
                 //1000: AD8 (P1.4)
                 //1001: AD9 (P1.5)
                 //1010: VSS
                 //1011: VBG (Internal Reference Voltage)
                 //11xx: Reserved	
	//--------------------------------------------------------------------------------------------
	//TKCHS:TKCON Bit[3:0],Touch Key Channel Select
                 //0000: TK0 (P1.0)
                 //0001: TK1 (P1.1)
                 //0010: TK2 (P1.2)
                 //0011: TK3 (P1.3)
                 //0100: TK4 (P3.3)
                 //0101: TK5 (P3.2)
                 //0110: TK6 (P3.1)
                 //0111: TK7 (P3.0)
                 //1000: TK8 (P1.4)
                 //1001: TK9 (P1.6)
                 //1010: TK10 (P1.7)
                 //1011: TK11 (P3.6)
                 //1100: TK12 (P3.5)
                 //1101: TK13 (P3.4)
                 //11xx: Reserved
/*
******************************************************************************************************
*/
sfr		TKCON2		= 0xAF;
	//ATKDT:TKCON2 Bit[7:4],Auto Touch Key Scan Result
	//--------------------------------------------------------------------------------------------
	//TKAUTO:TKCON2 Bit[3],Touch Key Auto Scan Mode Enable
	#define		TKAUTO		0x08		//0: Touch Key Running ;1: Touch Key Power Down
	//--------------------------------------------------------------------------------------------
	//TKSCNRT:TKCON2 Bit[2],Touch Key Auto Scan Rate ,0=125mS,1=62mS
	#define		TKSCNRT		0x04		//0=125mS,1=62mS
	//--------------------------------------------------------------------------------------------
	//TKSCNUM:TKCON2 Bit[1:0],Touch Key Auto Scan Number
	#define		TKSCNUM1	0x00		//1 channel
	#define		TKSCNUM4	0x03		//4 channel

//---------------------------
sfr     P3      =0xb0;
sbit    P3_7    = P3^7;
sbit    P3_6    = P3^6;
sbit    P3_5    = P3^5;
sbit    P3_4    = P3^4;
sbit    P3_3    = P3^3;
sbit    P3_2    = P3^2;			  
sbit    P3_1    = P3^1;
sbit    P3_0    = P3^0;

//---------------------------
sfr     IP      =0xb8;
	//--------------------------------------------------------------------------------------------
	sbit		PT2			  = IP^5;		//¶¨Ê±2ÖÐ¶ÏÓÅÏÈ¼¶µÍÎ»
	sbit 		PS			  = IP^4;		//´®ÐÐ¿ÚÖÐ¶ÏÓÅÏÈ¼¶µÍÎ»
	sbit 		PT1	    	= IP^3;		//¶¨Ê±1ÖÐ¶ÏÓÅÏÈ¼¶µÍÎ»
	sbit 		PX1	    	= IP^2;		//ÍâÖÐ¶ÏINT1ÖÐ¶ÏÓÅÏÈ¼¶µÍÎ»
	sbit 		PT0	    	= IP^1;		//¶¨Ê±0ÖÐ¶ÏÓÅÏÈ¼¶µÍÎ»
	sbit 		PX0	    	= IP^0;		//ÍâÖÐ¶ÏINT0ÖÐ¶ÏÓÅÏÈ¼¶µÍÎ»

sfr     IPH     =0xb9;
	//--------------------------------------------------------------------------------------------	
	#define	  	PT2H		0x20 		//Timer2ÖÐ¶ÏÓÅÏÈ¼¶¸ßÎ»¿ØÖÆ
	#define	  	PSH		  0x10 		//´®¿ÚÖÐ¶ÏÓÅÏÈ¼¶¸ßÎ»¿ØÖÆ
	#define	  	PT1H		0x08 		//Timer1ÖÐ¶ÏÓÅÏÈ¼¶¸ßÎ»¿ØÖÆ
	#define	  	PX1H		0x04 		//XINT1ÖÐ¶ÏÓÅÏÈ¼¶¸ßÎ»¿ØÖÆ 
	#define	  	PT0H		0x02 		//Timer0ÖÐ¶ÏÓÅÏÈ¼¶¸ßÎ»¿ØÖÆ
	#define		  PX0H		0x01 		//XINT0ÖÐ¶ÏÓÅÏÈ¼¶¸ßÎ»¿ØÖÆ
sfr     IP1     =0xba;
	//--------------------------------------------------------------------------------------------
	#define		  PSPI		0x10		//SPIÖÐ¶ÏÓÅÏÈ¼¶µÍÎ»
	#define	  	PADTKI  0x08		//ADC/Touch KeyÖÐ¶ÏÓÅÏÈµÍÎ»¿ØÖÆ
	#define	  	PX2		  0x04		//XINT2ÖÐ¶ÏÓÅÏÈµÍÎ»¿ØÖÆ
	#define	  	PP1		  0x02		//Port1ÖÐ¶ÏÓÅÏÈµÍÎ»¿ØÖÆ
	#define		  PT3		  0x01		//Timer3ÖÐ¶ÏÓÅÏÈµÍÎ»¿ØÖÆ
sfr     IP1H    =0xbb;
	//--------------------------------------------------------------------------------------------
	#define		  PSPIH 	0x10		//SPIÖÐ¶ÏÓÅÏÈ¼¶¸ßÎ»
	#define 	  PADTKIH	0x08;		//ADC/Touch Key ÖÐ¶ÏÓÅÏÈ¼¶¸ßÎ»
	#define		  PX2H		0x04		//XIN T2ÖÐ¶ÏÓÅÏÈ¼¶¸ßÎ»
	#define 	  PP1H		0x02;		//P1ÖÐ¶ÏÓÅÏÈ¼¶¸ßÎ»
	#define 	  PT3H    0x01;		//¶¨Ê±3ÖÐ¶ÏÓÅÏÈ¼¶¸ßÎ»

/*
******************************************************************************************************
*/
sfr   SPCON     = 0xBC;
	#define		SPCON_Mask	~0xFF		//
	#define		SPEN    0x80		//SPI Enable.0: SPI Enable;1: SPI Disable
	#define		MSTR    0x40 	  //Master Mode Enable.0: Slave Mode;1: Master Mode
	#define		CPOL    0x20	  //SPI Clock Polarity.0: SCK is low in idle state;1: SCK is high in idle state
	#define		CPHA    0x10		//SPI Clock Phase.0: Data sampled on first edge of SCK period;1: Data sampled on second edge of SCK period
	#define		SSDIS   0x08		//Pin Disable.0: Enable   pin;1: Disable   pin
	#define		LSBF    0x04 	  //LSB First.0: MSB first;1: LSB first
	//--------------------------------------------------------------------------------------------
	//SPCR:SPCON Bit[1:0], SPI Clock Rate.
	#define		SPCR_2  0x00	  //FSYSCLK/2
	#define		SPCR_4  0x01	  //FSYSCLK/4
	#define		SPCR_8  0x02	  //FSYSCLK/8
	#define		SPCR_16 0x03	  //FSYSCLK/16
/*
******************************************************************************************************
*/
sfr   SPSTA     = 0xBD;
	#define		SPSTA_Mask	~0xFC		//
	#define		SPIF    0x80		//SPI Interrupt Flag,This bit is set by H/W at the end of a data transfer,Cleared by H/W when interrupt is vectored into
	#define		WCOL    0x40 	  //Write Collision Interrupt Flag,This bit is set by H/W if write data to SPDAT when SPBSY is set.Write 0 to this bit or rewrite data to SPDAT when SPBYS is cleared will clear this flag.
	#define		MODF    0x20	  //Mode Fault Interrupt Flag,This bit is set by H/W when SSDIS is cleared and NSS pin is pulled low in Master mode.Write 0 to this bit will clear this flag.When this bit is set, the SPEN and MSTR in SPCON will be cleared by hardware
	#define		RCVOVF  0x10		//Receive Buffer Overrun Flag,This bit is set by H/W at the end of a data transfer and RCVBF is set.Write 0 to this bit or read SPDAT register will clear this flag.
	#define		RCVBF   0x08		//Receive Buffer Full Flag,This bit is set by H/W at the end of a data transfer.Write 0 to this bit or read SPDAT register will clear this flag.
	#define		SPBSY   0x04 	  //SPI Busy Flag (Read Only),This bit is set by H/W when a SPI transfer is progress.
/*
******************************************************************************************************
*/
sfr   SPDAT     = 0xBE;         //SPI Transmit and Receive Data
/*
******************************************************************************************************
*/
sfr   ATKCMP10H = 0xC2;         //
	//--------------------------------------------------------------------------------------------
	//ATKCMP1:ATKCMP10H Bit[6:4], Auto Touch Key Scan Channel 1 Compare Data bit 10~8.
	//--------------------------------------------------------------------------------------------
	//ATKCMP0:ATKCMP10H Bit[2:0], Auto Touch Key Scan Channel 0 Compare Data bit 10~8.
/*
******************************************************************************************************
*/
sfr   ATKCMP32H = 0xC3;         //
	//--------------------------------------------------------------------------------------------
	//ATKCMP3:ATKCMP32H Bit[6:4], Auto Touch Key Scan Channel 3 Compare Data bit 10~8.
	//--------------------------------------------------------------------------------------------
	//ATKCMP2:ATKCMP32H Bit[2:0], Auto Touch Key Scan Channel 2 Compare Data bit 10~8.
/*
******************************************************************************************************
*/
sfr   ATKCMP0   = 0xC4;         //Auto Touch Key Scan Channel 0 Compare Data bit 7~0.
/*
******************************************************************************************************
*/
sfr   ATKCMP1   = 0xC5;         //Auto Touch Key Scan Channel 1 Compare Data bit 7~0.
/*
******************************************************************************************************
*/
sfr   ATKCMP2   = 0xC6;         //Auto Touch Key Scan Channel 2 Compare Data bit 7~0.
/*
******************************************************************************************************
*/
sfr   ATKCMP3   = 0xC7;         //Auto Touch Key Scan Channel 3 Compare Data bit 7~0.
//---------------------------
sfr     T2CON   =0xc8;
	//--------------------------------------------------------------------------------------------
	sbit 		TF2  	  =	T2CON^7 ;	//TM2Òç³öÖÐ¶Ï±êÖ¾¡£TF2±ØÐëÓÉÓÃ»§³ÌÐòÇå¡°0¡±¡£µ±TM2×÷Îª´®¿Ú²¨ÌØÂÊ·¢ÉúÆ÷Ê±£¬TF2²»»á±»ÖÃ¡°1¡±¡£
	sbit 		EXF2    =	T2CON^6	;	//¶¨Ê±Æ÷TM2Íâ²¿ÖÐ¶Ï±êÖ¾¡£EXEN2Îª1Ê±£¬µ±T2EX£¨P1.1£©·¢Éú¸ºÌø±äÊ±ÖÃ1ÖÐ¶Ï±êÖ¾EXF2£¬EXF2±ØÐëÓÉÓÃ»§³ÌÐòÇå¡°0¡±¡£
	sbit  	RCLK    =	T2CON^5	;	//´®ÐÐ½Ó¿ÚµÄ·¢ËÍÊ±ÖÓÑ¡Ôñ±êÖ¾¡£TCLK=1Ê±£¬T2¹¤×÷ÓÚ²¨ÌØÂÊ·¢ÉúÆ÷·½Ê½¡£
	sbit  	TCLK 	  =	T2CON^4	;	//´®ÐÐ½Ó¿ÚµÄ½ÓÊÕÊ±ÖÓÑ¡Ôñ±êÖ¾Î»¡£RCLK£½1Ê±£¬T2¹¤×÷ÓÚ²¨ÌØÂÊ·¢ÉúÆ÷·½Ê½¡£
	sbit  	EXEN2   =	T2CON^3	;	//TM2µÄÍâ²¿ÖÐ¶Ï³äÐí±êÖ¾¡£
	sbit 		TR2     =	T2CON^2	;	//TM2¼ÆÊý/¶¨Ê±¿ØÖÆÎ»¡£TR2Îª1Ê±³äÐí¼ÆÊý£¬Îª0Ê±½ûÖ¹¼ÆÊý
	sbit 		CT2     =	T2CON^1	;	//Íâ²¿¼ÆÊýÆ÷/¶¨Ê±Æ÷Ñ¡ÔñÎ»¡£C/T2=1Ê±£¬T2ÎªÍâ²¿ÊÂ¼þ¼ÆÊýÆ÷£¬¼ÆÊýÂö³åÀ´×ÔT2£¨P1.0£©£»C/T2=0Ê±£¬T2Îª¶¨Ê±Æ÷£¬Õñµ´Âö³åµÄÊ®¶þ·ÖÆµÐÅºÅ×÷Îª¼ÆÊýÐÅºÅ¡£
	sbit    CPRL2   =	T2CON^0	;	//²¶×½ºÍ³£Êý×Ô¶¯ÔÙ×°Èë·½Ê½Ñ¡ÔñÎ»¡£Îª1Ê±¹¤×÷ÓÚ²¶×½·½Ê½£¬Îª0Ê±TM2¹¤×÷ÓÚ³£Êý×Ô¶¯ÔÙ×°Èë·½Ê½¡£µ±TCLK»òRCLKÎª1Ê±£¬CP/RL2±»ºöÂÔ£¬T2×ÜÊÇ¹¤×÷ÓÚ³£Êý×Ô¶¯ÔÙ×°Èë·½Ê½¡£

sfr     RCP2L   =0xca;
sfr     RCP2H   =0xcb;
sfr     TL2     =0xcc;
sfr     TH2     =0xcd;

sfr     PSW     =0xd0;
	//--------------------------------------------------------------------------------------------
	sbit 		CY 		= PSW^7;	//½øÎ»±êÖ¾,ÓÐ½ø»ò½èÎ»,CY£½1;ÎÞ½ø»ò½èÎ»,CY£½0
	sbit 		AC 		= PSW^6;	//°ë½øÎ»±êÖ¾
	sbit 		F0 		= PSW^5;	//ÓÃ»§¿ÉÒÔËæ±ãÊ¹ÓÃ
	sbit 		RS1 	= PSW^4;	//¹¤×÷¼Ä´æÆ÷ÇøÑ¡Ôñ[RS1:RS0]
	sbit 		RS0 	= PSW^3;	//00--0Çø,01--1Çø,10--2Çø,11--3Çø
	sbit 		OV 		= PSW^2;	//ÔËËã½á¹û°´²¹ÂëÔËËã,ÓÐÒç³ö,OV=1;ÎÞÒç³ö,OV£½0
  sbit    F1    = PSW^1;
	sbit 		P 		= PSW^0;	//ÓÃÀ´±íÊ¾ALUÔËËã½á¹ûÖÐ¶þ½øÖÆÊýÎ»1µÄ¸öÊýµÄÆæÅ¼ÐÔ,

//---------------------------
sfr		CLKCON		= 0xD8;
	sbit 		SCKTYPE = CLKCON^7;		//ÂýÊ±ÖÓÀàÐÍÑ¡Ôñ£¬Slow Clock Type. 1=SXT, 0=SRC
	sbit 		FCKTYPE = CLKCON^6;		//Fast clock Type. 0=FRC, 1=FXT.
	sbit 		STPPCK 	= CLKCON^4;		//1=½øÈëIDLÄ£Ê½£¬Stop UART/Timer0/Timer1/Timer2 Clock in Idle mode
	sbit 		STPFCK 	= CLKCON^3;		//1=Í£Ö¹¿ìÊ±ÖÓ£¬0=¿ìÊ±ÖÓ¹¤×÷
	sbit 		SELFCK 	= CLKCON^2;		//1=Ñ¡Ôñ¿ìÊ±ÖÓÎªÏµÍ³Ê±ÖÓÔ´£¬0=ÂýÊ±ÖÓÎªÏµÍ³Ê±ÖÓÔ´
	sbit 		CLKPSC_H 	= CLKCON^1;	
	sbit 		CLKPSC_L	= CLKCON^0;	
	//********************************************************************************************************
	#define  	SCKTYPE_SRC    	CLKCON=(CLKCON&0x7f)
	#define  	SCKTYPE_SXT    	CLKCON=(CLKCON&0x7f)|0x80
	#define		FCKTYPE_FRC		CLKCON=(CLKCON&0x9f)
	#define		FCKTYPE_FXT		CLKCON=(CLKCON&0x9f)|0x40
	#define		STPPCK_OPEN		CLKCON=(CLKCON&0xef)|0x10
	#define		STPPCK_OFF		CLKCON=(CLKCON&0xef)
	#define		STPFCK_OPEN		CLKCON=(CLKCON&0xf7)|0x08
	#define		STPFCK_OFF		CLKCON=(CLKCON&0xf7)
	#define		SELFCK_SLOW		CLKCON=(CLKCON&0xfb)
	#define		SELFCK_FAST		CLKCON=(CLKCON&0xfb)|0x04
	//--------------------------------------------------------------------------------------------
	//CLKPSC:CLKCON Bit[1:0],ÏµÍ³Ê±ÖÓÔ¤·ÖÆµ£¬SYSCLK Prescaler, 0:div16, 1:div4, 2:div2, 3:div1
	#define		CLKPSC_Mask							~0x03
	#define		CLKPSC_Div16 					0x00
	#define		CLKPSC_Div4	 					0x01
	#define		CLKPSC_Div2	 					0x02
	#define		CLKPSC_Div1						0x03						
	#define		SYSCLOCK_DIV_16		CLKCON=(CLKCON&0xfc)
	#define		SYSCLOCK_DIV_4		CLKCON=(CLKCON&0xfc)|CLKPSC_Div4
	#define		SYSCLOCK_DIV_2		CLKCON=(CLKCON&0xfc)|CLKPSC_Div2
	#define		SYSCLOCK_DIV_1		CLKCON=(CLKCON&0xfc)|CLKPSC_Div1	



sfr     ACC     =0xe0;
sfr     B       =0xf0;
sfr     CFGWL   =0xf7;
	//--------------------------------------------------------------------------------------------
	#define 	WDTEMask	0xC0		//
	#define 	WDTE11		0xC0		//WDT×ÜÊÇÊ¹ÄÜ
	#define 	WDTE10		0x80		//WDTÊ¹ÄÜ,µ«ÔÚIDLE/PDOWNÄ£Ê½ÏÂ½ûÖ¹
	#define 	WDTE0X		0x00		//WDT×ÜÊÇ½ûÖ¹
 	#define 	IRCMask		0x0F		//
	
	#define  	WDT_IS_OPEN                         CFGWL=(CFGWL&0x3f)|0xC0	//11£ºWDT Always Enable
	#define   	WDT_RUN_FAST_DIS_ILDE               CFGWL=(CFGWL&0x3f)|0x80	//10: WDT Enable in Fast/Slow, Disable in Idle/Stop mode
	#define  	WDT_IS_STOP                         CFGWL=CFGWL&0x3f  		//0X: WDT Disable

//---------------------------
sfr     AUX1    =0xf8;
	//--------------------------------------------------------------------------------------------
    sbit 		CLRWDT		= AUX1^7;
	#define     CLR_WDT         CLRWDT=1                   //ÉèÖÃÒÔÇå³ý¿´ÃÅ¹·¶¨Ê±Æ÷,H/W×Ô¶¯ÔÚÒ»¸öÊ±ÖÓÖÜÆÚÇå³ýËü     	
    sbit 		CLRTM3		= AUX1^6;//ÇåÁãTM3Ò²ÊÇÆô¶¯TM3
    sbit 		TKSOC		  = AUX1^5;//´¥Ãþ¼ü¿ªÊ¼£¬½áÊøÊ±×Ô¶¯ÇåÁã
    sbit 		ADSOC		  = AUX1^4;//ADC¿ªÊ¼£¬½áÊøÊ±Ó²¼þ×Ô¶¯ÇåÁã
    sbit 		CLRPWM0		= AUX1^3;
    sbit 		DPSEL		  = AUX1^0;//0±íÑ¡ÔñDPTR;1±íÑ¡ÔñDPTR1
/*
******************************************************************************************************
*/	
sfr 	ICECON 		= 0xF9;
	#define 	HWBRK		          0x80		//H/W Break
	#define 	RETROREQ          0x40		//Retro-OPCode Request,HW set at SWBRK,clear at NMI return
	#define 	TXRDY		          0x20		//Transmitt Ready
	#define 	CMDRDY	          0x10		//Ready for Command
	#define 	XFIRCK	          0x08		//Swich to FIRC 4MHZ
	#define 	WRFAIL	          0x01		//EEPROM Write Fail
/*
******************************************************************************************************
*/	
sfr 	RETROCODE	= 0xFA;//ICE Mode Retro-OPCode
/*
******************************************************************************************************
*/	
sfr 	ICERCD 		= 0xFB;//ICE Mode Receive Data
/*
******************************************************************************************************
*/	
sfr 	ICECMDL		= 0xFC;//ICE Mode Command Low Byte
/*
******************************************************************************************************
*/	
sfr 	ICECMDH		= 0xFD;//ICE Mode Command High Byte
/*
******************************************************************************************************
*/	
sfr 	ICETXD 		= 0xFE;//ICE Mode Transmit Data
/*
******************************************************************************************************
*/	
sfr 	INDSFR 		= 0xFF;//SFR direct Adr replaced by ICECMDL in NMI"mov dir,a"&"mov a,dir"
/*
******************************************************************************************************
*/
#define	 All_Interrupt_Enable()		EA = 1		//È«¾ÖÖÐ¶ÏÊ¹ÄÜ
#define	 All_Interrupt_Disable()	EA = 0		//È«¾ÖÖÐ¶Ï¹Ø±Õ
/*
******************************************************************************************************
*/
#define	 PowerDown()			PCON = PCON | PD	//½øÈëµôµçÄ£Ê½
#define	 PowerIdel()			PCON = PCON | IDL	//½øÈëIDELÄ£Ê½
#endif
