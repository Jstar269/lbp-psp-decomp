/* LBPMATCH module=EBOOT.BIN start=0x0892d1bc end=0x0892d210 symbol=FUN_0892d1bc lang=c99 */
typedef unsigned char undefined;
typedef unsigned char byte;
typedef unsigned short ushort;
typedef unsigned int uint;
typedef unsigned long long ulonglong;
typedef long long longlong;
typedef unsigned char uchar;
typedef unsigned char bool;
typedef unsigned long long undefined8;
typedef int code();
#define true 1
#define false 0
#define ABS(x) ((x) < 0 ? -(x) : (x))
typedef unsigned char undefined1;
typedef unsigned short undefined2;
typedef unsigned int undefined4;

extern undefined4 FUN_0892cf3c();

undefined4 FUN_0892d1bc(int param_1,uint param_2)
{
  int iVar1;
  undefined4 uVar2;
  
  iVar1 = FUN_0892cf3c(param_1);
  uVar2 = 1;
  if ((iVar1 == 0) || (*(uint *)(param_1 + 0x168) < param_2 >> 10)) {
    uVar2 = 0;
  }
  return uVar2;
}

// NEAR: 5 differing words; primary and O2 profiles tested.
// near miss from lane lbp5b (unreviewed)
