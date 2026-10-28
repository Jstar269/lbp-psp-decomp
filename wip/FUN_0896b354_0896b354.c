/* LBPMATCH module=EBOOT.BIN start=0x0896b354 end=0x0896b420 symbol=FUN_0896b354 lang=c99 cc=gcc404xs-Os */
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

extern void FUN_08970b6c();
extern undefined4 FUN_08979e88();

int FUN_0896b354(int *param_1,int *param_2)
{
  int iVar1;
  int iVar2;
  int iVar3;
  undefined4 *local_30 [4];
  
  iVar1 = (int)(short)((short)param_1[1] + 1);
  iVar2 = 1;
  if (1 < iVar1) {
    iVar1 = iVar1 + -2;
    iVar3 = iVar1 * 4;
    iVar2 = 1;
    while ((0 < iVar1 && (iVar1 = iVar1 + -1, iVar2 != 0))) {
      local_30[0] = (undefined4 *)*param_2;
      iVar2 = *(int *)(*param_1 + iVar3);
      iVar3 = iVar3 + -4;
      if (local_30[0] != (undefined4 *)0x0) {
        *(short *)((int)local_30[0] + 6) = *(short *)((int)local_30[0] + 6) + 1;
      }
      iVar2 = FUN_08979e88(iVar2,(int *)local_30);
      if (local_30[0] != (undefined4 *)0x0) {
        FUN_08970b6c(local_30[0]);
      }
    }
  }
  return iVar2;
}

// profile sweep: 27 differing words left; kept the generator key (normalising was worse or equal).
// near miss from lane lbp2d (unreviewed)
