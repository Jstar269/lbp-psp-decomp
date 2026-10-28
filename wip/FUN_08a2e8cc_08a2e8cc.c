/* LBPMATCH module=EBOOT.BIN start=0x08a2e8cc end=0x08a2e9a0 symbol=FUN_08a2e8cc lang=c99  cc=gcc404xs-Os */
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
typedef float undefined4;

extern undefined4 FUN_08adb810();
extern void FUN_08adb8a4();

void FUN_08a2e8cc(int *param_1,int param_2,undefined1 param_3)
{
  int iVar1;
  int *piVar2;
  int iVar3;
  int iVar4;
  
  if (*param_1 != 0) {
    FUN_08adb8a4(*param_1);
  }
  *param_1 = 0;
  param_1[1] = 0;
  param_1[2] = param_2;
  param_1[3] = 0;
  if (0 < param_2) {
    iVar1 = FUN_08adb810((param_2 * 0x14 + 0xfU & 0xfffffff0) + param_2 * 4,0x10,0,0);
    iVar4 = param_1[2];
    *param_1 = iVar1;
    piVar2 = (int *)(iVar1 + (iVar4 * 0x14 + 0xfU & 0xfffffff0));
    param_1[1] = (int)piVar2;
    if (0 < iVar4) {
      iVar3 = 0;
      do {
        iVar3 = iVar3 + 1;
        *piVar2 = iVar1;
        piVar2 = piVar2 + 1;
        iVar1 = iVar1 + 0x14;
      } while (iVar4 != iVar3);
    }
  }
  *(undefined1 *)(param_1 + 5) = param_3;
  return;
}

// best of the profile sweep: cc=gcc404xs-Os, 22 differing words left of 53.
// near miss from lane lbp2c (unreviewed)
