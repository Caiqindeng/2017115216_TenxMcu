#define __keys_c
#include "includeAll.h"
//=============================================================================
void GetKeys() {
  //if (P_key1 == 0) {
		static uint8_t lastKeyValue = D_keyNull;
    if(P_key1==0){
		  lastKeyValue = D_keyValue1;
		}else{
		  keyValue=lastKeyValue;
			lastKeyValue=D_keyNull;
	//	}
		
		//keyValue = D_keyValue1;
  }
}