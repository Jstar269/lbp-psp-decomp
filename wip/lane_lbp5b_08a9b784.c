/* LBPMATCH module=EBOOT.BIN start=0x08a9b784 end=0x08a9b7d8 symbol=FUN_08a9b784 lang=c99 */
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

extern void FUN_08a9b5d4();

void FUN_08a9b784(int param_1,undefined4 *param_2)
{
  undefined4 uVar1;
  undefined4 uVar2;
  undefined4 *puVar3;
  
  puVar3 = *(undefined4 **)(param_1 + 0xc);
  if (puVar3 != *(undefined4 **)(param_1 + 0x10)) {
    if (puVar3 != (undefined4 *)0x0) {
      uVar1 = *param_2;
      uVar2 = param_2[1];
      puVar3[2] = param_2[2];
      *puVar3 = uVar1;
      puVar3[1] = uVar2;
    }
    *(undefined4 **)(param_1 + 0xc) = puVar3 + 3;
    return;
  }
  FUN_08a9b5d4((int *)(param_1 + 8),puVar3,param_2);
  return;
}

// NEAR: 5 differing words; primary and O2 profiles tested.
// near miss from lane lbp5b (unreviewed)
