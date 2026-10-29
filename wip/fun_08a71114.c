/* LBPMATCH module=EBOOT.BIN start=0x08a71114 end=0x08a711c0 symbol=FUN_08a71114 lang=c99 cc=gcc404xs-O2 */
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

extern void FUN_08a10118();
extern undefined4 * FUN_08a10f1c();
extern undefined4 * FUN_08a11918();

void FUN_08a71114(int param_1,unsigned char param_2)
{
  undefined4 *puVar1;
  int iVar2;
  
  if (param_2 != 0) {
    puVar1 = FUN_08a10f1c();
    *(undefined4 *)(param_1 + 0xa8) = puVar1[1];
    iVar2 = *(int *)(param_1 + 0xa4);
  } else {
    puVar1 = FUN_08a10f1c();
    puVar1 = FUN_08a11918((int)puVar1,3,param_1);
    *(undefined4 **)(param_1 + 0xa8) = puVar1;
    FUN_08a10118((int)puVar1,(undefined4 *)(param_1 + 0x50));
    iVar2 = *(int *)(param_1 + 0xa4);
  }
  if (iVar2 != 0) {
    *(undefined4 *)(iVar2 + 0x40) = *(undefined4 *)(param_1 + 0xa8);
    if (param_2 == '\0') {
      *(int *)(*(int *)(param_1 + 0xa8) + 4) = iVar2;
      return;
    }
    *(undefined4 *)(*(int *)(param_1 + 0xa8) + 4) = 0;
  }
  return;
}



// O2 8 words differ: a4 object load register and order, argument setup; branch polarity and integer fields restored.
// near miss from lane lbp8e (unreviewed)
