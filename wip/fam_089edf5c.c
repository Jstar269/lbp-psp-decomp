/* LBPMATCH module=EBOOT.BIN start=0x089edf5c end=0x089ee13c symbol=FUN_089edf5c lang=c99 */
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

extern int FUN_089edb64();
extern ulonglong FUN_089ede34();
extern int FUN_08b89838();
extern int FUN_08b898a8();

int FUN_089edf5c(int param_1,int param_2,uint *param_3)
{
  int iVar1;
  int iVar2;
  int iVar3;
  ulonglong uVar4;
  
  if (param_1 + 4 == param_2) {
    if ((*(int *)(param_1 + 0x14) == 0) ||
       (param_2 = *(int *)(param_1 + 0x10), *param_3 <= *(uint *)(param_2 + 0x10))) {
      uVar4 = FUN_089ede34(param_1,param_3);
      return (int)uVar4;
    }
  }
  else {
    if (*param_3 < *(uint *)(param_2 + 0x10)) {
      if (param_2 == *(int *)(param_1 + 0xc)) {
        iVar1 = FUN_089edb64(param_1,param_2,param_2,param_3);
        return iVar1;
      }
      iVar1 = FUN_08b898a8((int *)param_2);
      if (*param_3 <= *(uint *)(iVar1 + 0x10)) {
        uVar4 = FUN_089ede34(param_1,param_3);
        return (int)uVar4;
      }
      iVar2 = *(int *)(iVar1 + 0xc);
      iVar3 = param_2;
      param_2 = iVar1;
    }
    else {
      if (*param_3 <= *(uint *)(param_2 + 0x10)) {
        return param_2;
      }
      if (*(int *)(param_1 + 0x10) == param_2) goto LAB_089ee04c;
      iVar3 = FUN_08b89838(param_2);
      if (*(uint *)(iVar3 + 0x10) <= *param_3) {
        uVar4 = FUN_089ede34(param_1,param_3);
        return (int)uVar4;
      }
      iVar2 = *(int *)(param_2 + 0xc);
    }
    if (iVar2 != 0) {
      iVar1 = FUN_089edb64(param_1,iVar3,iVar3,param_3);
      return iVar1;
    }
  }
LAB_089ee04c:
  iVar1 = FUN_089edb64(param_1,0,param_2,param_3);
  return iVar1;
}

// Primary-profile generated baseline: 115 words differ; insertion paths and stack frame need reconstruction.
// near miss from lane lbp1a (unreviewed)
