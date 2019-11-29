#define __keys_c
#include "includeAll.h"
//=============================================================================
void GetKeys() {
  static uint8_t tempKeyValue = D_keyNull;

  //按键口 P10 设为上拉输入
  P1MODL = 0xa8;
  _nop_();
  _nop_();
  _nop_();
  _nop_();
  _nop_();
  if (P_key1 == 0) {
    tempKeyValue = D_keyValue1;
  } else {
    keyValue = tempKeyValue;
    tempKeyValue = D_keyNull;
  }
  //按键口P10，恢复为输出 
  P1MODL = 0xaa;
}