/* LBPMATCH module=EBOOT.BIN start=0x08925300 end=0x089253dc symbol=FUN_08925300 lang=c99 cc=gcc404xs-Os */
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

void FUN_08925300(int *param_1,int param_2,undefined1 param_3)
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
    iVar2 = FUN_08adb810(param_2 * 0x1a4,0x10,0,0);
    iVar4 = param_1[2];
    iVar6 = 0;
    iVar5 = 0;
    piVar3 = (int *)(iVar2 + iVar4 * 0x1a0);
    *param_1 = iVar2;
    param_1[1] = (int)piVar3;
    while( true ) {
      bVar1 = iVar4 <= iVar6;
      iVar6 = iVar6 + 1;
      if (bVar1) break;
      *piVar3 = *param_1 + iVar5;
      iVar5 = iVar5 + 0x1a0;
      piVar3 = piVar3 + 1;
    }
  }
  *(undefined1 *)(param_1 + 5) = param_3;
  return;
}

// profile sweep: 29 differing words left; kept the generator key (normalising was worse or equal).
// near miss from lane lbp2d (unreviewed)
