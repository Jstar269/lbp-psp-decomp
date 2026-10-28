/* LBPMATCH module=EBOOT.BIN start=0x0887a564 end=0x0887a718 symbol=FUN_0887a564 lang=c99 */
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

extern int FUN_0887a378();
extern undefined8 FUN_0887a47c();
extern int FUN_08b89838();
extern int FUN_08b898a8();
extern int FUN_08ba0d98();

int FUN_0887a564(char *param_1,char *param_2,undefined4 *param_3)
{
  char *iVar1;
  int iVar2;
  char *iVar3;
  undefined8 uVar4;
  
  if (param_2 == param_1 + 4) {
    if (*(int *)(param_1 + 0x14) == 0) {
LAB_0887a5b4:
      uVar4 = FUN_0887a47c(param_1,param_3);
      return (int)uVar4;
    }
    iVar3 = *(int *)(param_1 + 0x10);
    iVar1 = FUN_08ba0d98((byte *)(iVar3 + 0x10),(byte *)param_3);
    if (-1 < iVar1) goto LAB_0887a5b4;
  }
  else {
    iVar3 = FUN_08ba0d98((byte *)param_3,(byte *)(param_2 + 0x10));
    if (iVar3 < 0) {
      iVar1 = param_2;
      if (param_2 == *(int *)(param_1 + 0xc)) goto LAB_0887a60c;
      iVar3 = FUN_08b898a8((int *)param_2);
      iVar1 = FUN_08ba0d98((byte *)(iVar3 + 0x10),(byte *)param_3);
      if (-1 < iVar1) {
        uVar4 = FUN_0887a47c(param_1,param_3);
        return (int)uVar4;
      }
      iVar2 = *(int *)(iVar3 + 0xc);
    }
    else {
      iVar3 = FUN_08ba0d98((byte *)(param_2 + 0x10),(byte *)param_3);
      if (-1 < iVar3) {
        return param_2;
      }
      iVar3 = param_2;
      if (param_2 == *(int *)(param_1 + 0x10)) goto LAB_0887a6c8;
      iVar1 = FUN_08b89838(param_2);
      iVar2 = FUN_08ba0d98((byte *)param_3,(byte *)(iVar1 + 0x10));
      if (-1 < iVar2) {
        uVar4 = FUN_0887a47c(param_1,param_3);
        return (int)uVar4;
      }
      iVar2 = *(int *)(param_2 + 0xc);
      param_2 = iVar1;
    }
    iVar1 = param_2;
    if (iVar2 != 0) goto LAB_0887a60c;
  }
LAB_0887a6c8:
  param_2 = 0;
  iVar1 = iVar3;
LAB_0887a60c:
  iVar3 = FUN_0887a378(param_1,param_2,iVar1,param_3);
  return iVar3;
}

// Primary-profile generated baseline; function control flow and temporaries remain unresolved.
// near miss from lane lbp1a (unreviewed)
