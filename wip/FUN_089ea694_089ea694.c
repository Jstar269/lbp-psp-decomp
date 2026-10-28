/* LBPMATCH module=EBOOT.BIN start=0x089ea694 end=0x089ea758 symbol=FUN_089ea694 lang=c99 cc=gcc402x-O2 rodata=0x08bad80c */
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

extern undefined4 FUN_089ece58();
extern undefined4 FUN_089ece70();
extern void FUN_08a1fc44();
extern void FUN_08a23344();

void FUN_089ea694(int param_1)
{
  float *pfVar1;
  int iVar2;
  int iVar3;
  float *pfVar4;
  int iVar5;
  float fVar6;
  float fVar7;
  float fVar8;
  
  iVar5 = 0;
  FUN_08a1fc44((uint *)(param_1 + 4),0x11);
  FUN_08a23344(param_1);
  fVar8 = 3.0f;
  pfVar4 = (float *)(param_1 + 0x90);
  do {
    fVar6 = (float)FUN_089ece58(iVar5);
    fVar7 = (float)FUN_089ece70(iVar5);
    iVar2 = 0;
    pfVar1 = pfVar4;
    do {
      pfVar1 = pfVar1 + 1;
      iVar3 = iVar2 + 1;
      *pfVar1 = fVar6 + ((float)iVar2 * (fVar7 - fVar6)) / fVar8;
      iVar2 = iVar3;
    } while (iVar3 != 3);
    iVar5 = iVar5 + 1;
    pfVar4 = pfVar4 + 3;
  } while (iVar5 != 5);
  return;
}

// best of the profile sweep: cc=gcc402x-O2, 24 differing words left of 49.
// near miss from lane lbp2c (unreviewed)
