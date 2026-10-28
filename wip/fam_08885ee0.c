/* LBPMATCH module=EBOOT.BIN start=0x08885ee0 end=0x08886138 symbol=FUN_08885ee0 lang=c99 */
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

extern int FUN_08885cb0();
extern undefined8 FUN_08885dbc();
extern int FUN_08b89838();
extern int FUN_08b898a8();

int FUN_08885ee0(int param_1,int param_2,int *param_3)
{
  int iVar1;
  int iVar2;
  int iVar3;
  undefined8 uVar4;
  
  if (param_2 == param_1 + 4) {
    if (*(int *)(param_1 + 0x14) == 0) {
LAB_08886090:
      uVar4 = FUN_08885dbc(param_1,param_3);
      return (int)uVar4;
    }
    iVar3 = *(int *)(param_1 + 0x10);
    if ((*param_3 <= *(int *)(iVar3 + 0x10)) &&
       ((*(int *)(iVar3 + 0x10) != *param_3 || ((uint)param_3[1] <= *(uint *)(iVar3 + 0x14)))))
    goto LAB_08886090;
  }
  else {
    iVar3 = *param_3;
    if (iVar3 < *(int *)(param_2 + 0x10)) {
LAB_08885f88:
      iVar2 = param_2;
      if (param_2 == *(int *)(param_1 + 0xc)) goto LAB_08885f98;
      iVar3 = FUN_08b898a8((int *)param_2);
      if (*(int *)(iVar3 + 0x10) < *param_3) {
        iVar1 = *(int *)(iVar3 + 0xc);
      }
      else {
        if ((*(int *)(iVar3 + 0x10) != *param_3) || ((uint)param_3[1] <= *(uint *)(iVar3 + 0x14))) {
          uVar4 = FUN_08885dbc(param_1,param_3);
          return (int)uVar4;
        }
        iVar1 = *(int *)(iVar3 + 0xc);
      }
    }
    else {
      if (iVar3 == *(int *)(param_2 + 0x10)) {
        if ((uint)param_3[1] < *(uint *)(param_2 + 0x14)) goto LAB_08885f88;
        iVar2 = *(int *)(param_2 + 0x10);
      }
      else {
        iVar2 = *(int *)(param_2 + 0x10);
      }
      if (iVar3 <= iVar2) {
        if (iVar2 != iVar3) {
          return param_2;
        }
        if ((uint)param_3[1] <= *(uint *)(param_2 + 0x14)) {
          return param_2;
        }
      }
      iVar3 = param_2;
      if (param_2 == *(int *)(param_1 + 0x10)) goto LAB_08885ffc;
      iVar2 = FUN_08b89838(param_2);
      if (*param_3 < *(int *)(iVar2 + 0x10)) {
        iVar1 = *(int *)(param_2 + 0xc);
      }
      else {
        if ((*param_3 != *(int *)(iVar2 + 0x10)) || (*(uint *)(iVar2 + 0x14) <= (uint)param_3[1])) {
          uVar4 = FUN_08885dbc(param_1,param_3);
          return (int)uVar4;
        }
        iVar1 = *(int *)(param_2 + 0xc);
      }
    }
    param_2 = iVar2;
    iVar2 = param_2;
    if (iVar1 != 0) goto LAB_08885f98;
  }
LAB_08885ffc:
  param_2 = 0;
  iVar2 = iVar3;
LAB_08885f98:
  iVar3 = FUN_08885cb0(param_1,param_2,iVar2,param_3);
  return iVar3;
}

// Primary-profile generated baseline; tree construction and control flow remain unresolved.
// near miss from lane lbp1a (unreviewed)
