/* LBPMATCH module=EBOOT.BIN start=0x08a9c9b0 end=0x08a9cab0 symbol=FUN_08a9c9b0 lang=c99 cc=gcc402x-O2 */
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

extern void FUN_0894af10();

void FUN_08a9c9b0(undefined4 *param_1,undefined4 *param_2,undefined4 *param_3)
{
  undefined1 *puVar1;
  undefined1 *puVar2;
  uint uVar3;
  undefined1 *puVar4;
  int iVar5;
  int iVar6;
  undefined1 *puVar7;
  undefined1 local_30 [16];
  
  iVar5 = param_2[1];
  iVar6 = param_3[1];
  puVar4 = (undefined1 *)*param_2;
  puVar7 = (undefined1 *)*param_3;
  uVar3 = iVar5 + iVar6 + 1;
  *param_1 = 0;
  param_1[1] = 0;
  param_1[2] = 0;
  param_1[3] = 0;
  param_1[4] = 0;
  local_30[0] = 0;
  FUN_0894af10(param_1 + 2,uVar3,local_30);
  puVar2 = puVar4 + iVar5;
  *(undefined1 *)(uVar3 + param_1[2] + -1) = 0;
  puVar1 = (undefined1 *)param_1[2];
  param_1[1] = (param_1[3] - (int)puVar1) + -1;
  *param_1 = puVar1;
  for (; puVar4 != puVar2; puVar4 = puVar4 + 1) {
    *puVar1 = *puVar4;
    puVar1 = puVar1 + 1;
  }
  puVar1 = puVar7 + iVar6;
  puVar2 = (undefined1 *)(param_1[2] + iVar5);
  for (; puVar7 != puVar1; puVar7 = puVar7 + 1) {
    *puVar2 = *puVar7;
    puVar2 = puVar2 + 1;
  }
  return;
}

// profile sweep: 34 differing words left; kept the generator key (normalising was worse or equal).
// near miss from lane lbp2d (unreviewed)
