/* LBPMATCH module=EBOOT.BIN start=0x088859e4 end=0x08885a8c symbol=FUN_088859e4 lang=c99 cc=gcc404xs-O2 */
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

extern int FUN_08885394();
extern undefined4 FUN_088858f4();

undefined4 FUN_088859e4(int param_1,int *param_2,uint param_3)
{
  int iVar1;
  undefined4 uVar2;
  
  iVar1 = FUN_08885394(param_1 + 0x10,param_2);
  uVar2 = 0;
  if (iVar1 != param_1 + 0x14) {
    if ((param_3 & 1) == 0) {
      if ((param_3 & 2) != 0) {
        *(undefined4 *)(iVar1 + 0x20) = 1;
      }
    }
    else {
      *(undefined4 *)(iVar1 + 0x20) = 0;
    }
    if ((param_3 & 4) != 0) {
      *(undefined1 *)(iVar1 + 0x1c) = 1;
    }
    uVar2 = 1;
    if (*(uint **)(param_1 + 0xc) != (uint *)0x0) {
      FUN_088858f4(*(uint **)(param_1 + 0xc),param_2,1);
      uVar2 = 1;
    }
  }
  return uVar2;
}
// O2 21 words differ; structured field rewrite 32 words differs.
// near miss from lane lbp13a (unreviewed)
