/* LBPMATCH module=EBOOT.BIN start=0x088962e8 end=0x088963d4 symbol=FUN_088962e8 lang=c99  cc=gcc404xs-Os */
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

extern undefined4 FUN_08adb810();
extern void FUN_08adb8a4();

void FUN_088962e8(int *param_1,int param_2,undefined1 param_3)
{
  bool bVar1;
  int iVar2;
  int *piVar3;
  int iVar4;
  int iVar5;
  int iVar6;
  
  if (*param_1 != 0) {
    FUN_08adb8a4(*param_1);
  }
  *param_1 = 0;
  param_1[1] = 0;
  param_1[2] = param_2;
  param_1[3] = 0;
  if (0 < param_2) {
    iVar2 = FUN_08adb810((param_2 * 0x4c + 0xfU & 0xfffffff0) + param_2 * 4,0x10,0,0);
    iVar4 = param_1[2];
    iVar6 = 0;
    iVar5 = 0;
    piVar3 = (int *)(iVar2 + (iVar4 * 0x4c + 0xfU & 0xfffffff0));
    *param_1 = iVar2;
    param_1[1] = (int)piVar3;
    for (iVar6 = 0; iVar6 < iVar4; iVar6 = iVar6 + 1) {
      *piVar3 = *param_1 + iVar5;
      iVar5 = iVar5 + 0x4c;
      piVar3 = piVar3 + 1;
    }
  }
  *(undefined1 *)(param_1 + 5) = param_3;
  return;
}

// residual: 21 words. The loop looks like a record-writer (stride 76, `sw v0,-4(a0)` with a0 pre-incremented and
// the test rotated to the bottom), but writing it as a natural `for` still leaves retail's `move a0,v1` and the
// sll order in the prologue different. parked; the four clones 0x08924ad4/0x0892500c/0x0892ffe0 share this shape.
// near miss from lane lbp2c (unreviewed)
