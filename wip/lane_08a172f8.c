/* LBPMATCH module=EBOOT.BIN start=0x08a172f8 end=0x08a17560 symbol=FUN_08a172f8 lang=c99 */
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


void FUN_08a172f8(int *param_1,int param_2)
{
  int iVar1;
  uint uVar2;
  uint uVar3;
  int iVar4;
  uint *puVar5;
  int iVar6;
  int *piVar7;
  int *piVar8;
  int iVar9;
  uint uVar10;
  
  iVar1 = *param_1;
  uVar2 = (uint)*(ushort *)(iVar1 * 2 + param_2 + 0xc);
  uVar10 = param_1[1] - 1;
  piVar7 = param_1 + (uVar2 + 1) * 2 + 2;
  puVar5 = (uint *)(param_1 + uVar2 * 2 + 2);
  iVar9 = (int)puVar5 - (int)piVar7;
  for (; uVar2 < uVar10; uVar2 = uVar2 + 1) {
    piVar8 = (int *)(iVar9 + (int)piVar7);
    iVar4 = piVar7[1];
    iVar6 = *(int *)(param_1[0x2002] + 8);
    *piVar8 = *piVar7;
    piVar8[1] = iVar4;
    iVar4 = iVar1 * 2 + *(int *)(iVar6 + 0x18) + (*puVar5 & 0x7fff) * 0x20;
    if ((int)*puVar5 < 0) {
      *(short *)(iVar4 + 0xc) = (short)uVar2;
    }
    else {
      *(short *)(iVar4 + 0x10) = (short)uVar2;
    }
    puVar5 = puVar5 + 2;
    piVar7 = piVar7 + 2;
  }
  param_1[1] = uVar10;
  param_1[uVar10 * 2 + 3] = 0;
  param_1[uVar10 * 2 + 2] = param_1[uVar10 * 2 + 2] & 0x80000000U | 0x7fffffff;
  iVar1 = *param_1;
  uVar2 = (uint)*(ushort *)(iVar1 * 2 + param_2 + 0x10);
  uVar10 = param_1[1] - 1;
  piVar7 = param_1 + (uVar2 + 1) * 2 + 2;
  puVar5 = (uint *)(param_1 + uVar2 * 2 + 2);
  iVar9 = (int)puVar5 - (int)piVar7;
  for (; uVar2 < uVar10; uVar2 = uVar2 + 1) {
    piVar8 = (int *)(iVar9 + (int)piVar7);
    iVar4 = piVar7[1];
    iVar6 = *(int *)(param_1[0x2002] + 8);
    *piVar8 = *piVar7;
    piVar8[1] = iVar4;
    iVar4 = iVar1 * 2 + *(int *)(iVar6 + 0x18) + (*puVar5 & 0x7fff) * 0x20;
    if ((int)*puVar5 < 0) {
      *(short *)(iVar4 + 0xc) = (short)uVar2;
    }
    else {
      *(short *)(iVar4 + 0x10) = (short)uVar2;
    }
    puVar5 = puVar5 + 2;
    piVar7 = piVar7 + 2;
  }
  param_1[1] = uVar10;
  param_1[uVar10 * 2 + 3] = 0;
  param_1[uVar10 * 2 + 2] = param_1[uVar10 * 2 + 2] & 0x80000000U | 0x7fffffff;
  uVar2 = 0;
  if (param_1[1] != 0) {
    uVar10 = 0;
    piVar7 = param_1;
    do {
      while (uVar3 = piVar7[2], (int)uVar3 < 0) {
        uVar2 = uVar2 + 1;
        piVar7[2] = uVar3 & 0x80007fff | (uVar2 & 0xffff) << 0xf;
        uVar10 = uVar10 + 1;
        piVar7 = piVar7 + 2;
        if ((uint)param_1[1] <= uVar10) {
          return;
        }
      }
      uVar2 = uVar2 - 1;
      piVar7[2] = uVar3 & 0x80007fff | (uVar2 & 0xffff) << 0xf;
      uVar10 = uVar10 + 1;
      piVar7 = piVar7 + 2;
    } while (uVar10 < (uint)param_1[1]);
  }
  return;
}



// Generated near miss: register allocation and unaligned block copies differ; Os 154 words, O2 156 words.
// near miss from lane lbp15d (unreviewed)
