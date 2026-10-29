/* LBPMATCH module=EBOOT.BIN start=0x08b9b850 end=0x08b9b928 symbol=FUN_08b9b850 lang=c99 cc=gcc404xs-O2 */
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

extern void FUN_08b9b72c();

void FUN_08b9b850(undefined4 param_1,undefined *param_2,int param_3)
{
  undefined4 uVar1;
  int iVar2;
  uint uVar3;
  undefined4 *puVar4;
  undefined4 *puVar5;
  uint uVar6;
  int iVar7;
  int iVar8;
  
  uVar6 = *(uint *)(param_3 + 4);
  iVar7 = (uVar6 >> 1) - 1;
  puVar5 = (undefined4 *)(param_3 + 8);
  if (-1 < iVar7) {
    uVar3 = 0;
    iVar8 = 0;
    do {
      uVar3 = uVar3 + 1;
      FUN_08b9b72c(param_1,param_2,(int)puVar5,iVar7 + iVar8,uVar6);
      iVar8 = -uVar3;
    } while (uVar3 != uVar6 >> 1);
  }
  iVar7 = uVar6 - 1;
  if (0 < iVar7) {
    puVar4 = puVar5 + iVar7;
    iVar8 = 0;
    do {
      uVar1 = *puVar5;
      iVar2 = iVar7 - iVar8;
      *puVar5 = *puVar4;
      *puVar4 = uVar1;
      iVar8 = iVar8 + 1;
      FUN_08b9b72c(param_1,param_2,(int)puVar5,0,iVar2);
      puVar4 = puVar4 + -1;
    } while (iVar8 != iVar7);
  }
  return;
}

// Baseline generated candidate; 37 differing words. Tested primary and O2 profiles; control flow and types need reconstruction.
// near miss from lane lbp8f (unreviewed)
