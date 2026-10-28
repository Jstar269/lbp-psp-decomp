/* LBPMATCH module=EBOOT.BIN start=0x088508c8 end=0x08850b9c symbol=FUN_088508c8 lang=c99 */
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

extern int FUN_088506ac();
extern undefined8 FUN_08850780();
extern int FUN_08b89838();
extern int FUN_08b898a8();
extern int FUN_08b9e714();

int FUN_088508c8(int param_1,int param_2,undefined4 *param_3)
{
  int iVar1;
  int iVar2;
  int iVar3;
  int *piVar4;
  undefined8 uVar5;
  
  if (param_2 == param_1 + 4) {
    if (*(int *)(param_1 + 0x14) != 0) {
      iVar3 = *(int *)(param_1 + 0x10);
      if (*(int *)(iVar3 + 0x18) == 0) {
        if (param_3[2] != 0) {
          iVar1 = param_3[2];
          goto LAB_08850930;
        }
        iVar1 = FUN_08b9e714((byte *)(*(int *)(iVar3 + 0x14) + 0xc),(byte *)(param_3[1] + 0xc),0x14)
        ;
      }
      else {
        iVar1 = param_3[2];
LAB_08850930:
        iVar1 = *(int *)(iVar3 + 0x18) - iVar1;
      }
      if (iVar1 < 0) goto LAB_08850a98;
    }
    uVar5 = FUN_08850780(param_1,param_3);
    iVar3 = (int)uVar5;
  }
  else {
    iVar3 = param_3[2];
    piVar4 = param_3 + 2;
    if ((iVar3 == 0) && (*(int *)(param_2 + 0x18) == 0)) {
      iVar1 = FUN_08b9e714((byte *)(param_3[1] + 0xc),(byte *)(*(int *)(param_2 + 0x14) + 0xc),0x14)
      ;
    }
    else {
      iVar1 = iVar3 - *(int *)(param_2 + 0x18);
    }
    if (iVar1 < 0) {
      iVar1 = param_2;
      if (param_2 != *(int *)(param_1 + 0xc)) {
        iVar3 = FUN_08b898a8((int *)param_2);
        if ((*(int *)(iVar3 + 0x18) == 0) && (*piVar4 == 0)) {
          iVar2 = FUN_08b9e714((byte *)(*(int *)(iVar3 + 0x14) + 0xc),(byte *)(param_3[1] + 0xc),
                               0x14);
        }
        else {
          iVar2 = *(int *)(iVar3 + 0x18) - *piVar4;
        }
        if (-1 < iVar2) {
          uVar5 = FUN_08850780(param_1,param_3);
          return (int)uVar5;
        }
        if (*(int *)(iVar3 + 0xc) == 0) goto LAB_08850a98;
      }
    }
    else {
      if ((*(int *)(param_2 + 0x18) == 0) && (iVar3 == 0)) {
        iVar3 = FUN_08b9e714((byte *)(*(int *)(param_2 + 0x14) + 0xc),(byte *)(param_3[1] + 0xc),
                             0x14);
      }
      else {
        iVar3 = *(int *)(param_2 + 0x18) - iVar3;
      }
      if (-1 < iVar3) {
        return param_2;
      }
      iVar3 = param_2;
      if (param_2 != *(int *)(param_1 + 0x10)) {
        iVar1 = FUN_08b89838(param_2);
        if ((*piVar4 == 0) && (*(int *)(iVar1 + 0x18) == 0)) {
          iVar2 = FUN_08b9e714((byte *)(param_3[1] + 0xc),(byte *)(*(int *)(iVar1 + 0x14) + 0xc),
                               0x14);
        }
        else {
          iVar2 = *piVar4 - *(int *)(iVar1 + 0x18);
        }
        if (-1 < iVar2) {
          uVar5 = FUN_08850780(param_1,param_3);
          return (int)uVar5;
        }
        piVar4 = (int *)(param_2 + 0xc);
        param_2 = iVar1;
        if (*piVar4 != 0) goto LAB_08850ab0;
      }
LAB_08850a98:
      iVar1 = 0;
      param_2 = iVar3;
    }
LAB_08850ab0:
    iVar3 = FUN_088506ac(param_1,iVar1,param_2,param_3);
  }
  return iVar3;
}

// Generated baseline 179 differing words; target includes inlined destructor and C++ temporary handling.
// near miss from lane lbp1a (unreviewed)
