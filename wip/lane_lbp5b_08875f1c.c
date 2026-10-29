/* LBPMATCH module=EBOOT.BIN start=0x08875f1c end=0x08875f4c symbol=FUN_08875f1c lang=c99 */
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


undefined4 FUN_08875f1c(int param_1,undefined4 *param_2)
{
  undefined4 uVar1;
  undefined4 uVar2;
  
  uVar2 = 0;
  if (*(int *)(param_1 + 0x14) == 0) {
    uVar2 = *(undefined4 *)(*(int *)(param_1 + 0x10) + 0x24);
    uVar1 = *(undefined4 *)(*(int *)(param_1 + 0x10) + 0x28);
    *(undefined4 *)(param_1 + 0x14) = uVar1;
    *param_2 = uVar1;
  }
  else {
    *param_2 = 0;
  }
  return uVar2;
}

// NEAR: 6 differing words; primary and O2 profiles tested.
// near miss from lane lbp5b (unreviewed)
