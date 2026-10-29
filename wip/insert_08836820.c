/* LBPMATCH module=EBOOT.BIN start=0x08836820 end=0x08836914 symbol=FUN_08836820 lang=c99 */
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

extern undefined4 DAT_08be84a0;
extern undefined4 FUN_08adbb84();
extern void FUN_08b899e4();

int FUN_08836820(int param_1,int param_2,int param_3,short *param_4)
{
  int *piVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  int iVar6;
  int iVar7;
  int iVar8;
  char cVar9;
  
  if ((param_2 != 0) ||
     ((cVar9 = '\x01', param_3 != param_1 + 4 &&
      (cVar9 = '\0', *param_4 < *(short *)(param_3 + 0x10))))) {
    cVar9 = '\x01';
  }
  piVar1 = (int *)FUN_08adbb84(DAT_08be84a0,0x30);
  if ((char *)piVar1 + 0x10 != (char *)0) {
    iVar8 = *(int *)(param_4 + 0xe);
    iVar2 = *(int *)(param_4 + 2);
    iVar3 = *(int *)(param_4 + 4);
    iVar4 = *(int *)(param_4 + 6);
    iVar5 = *(int *)(param_4 + 8);
    iVar6 = *(int *)(param_4 + 10);
    iVar7 = *(int *)(param_4 + 0xc);
    piVar1[4] = *(int *)param_4;
    piVar1[0xb] = iVar8;
    piVar1[5] = iVar2;
    piVar1[6] = iVar3;
    piVar1[7] = iVar4;
    piVar1[8] = iVar5;
    piVar1[9] = iVar6;
    piVar1[10] = iVar7;
  }
  FUN_08b899e4(cVar9,piVar1,param_3,param_1 + 4);
  *(int *)(param_1 + 0x14) = *(int *)(param_1 + 0x14) + 1;
  return (int)piVar1;
}

// 40 differing words; likely placement-new struct copy and bool selection require reconstruction.
// near miss from lane lbp7a (unreviewed)
