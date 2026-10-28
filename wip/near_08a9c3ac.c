/* LBPMATCH module=EBOOT.BIN start=0x08a9c3ac end=0x08a9c444 symbol=FUN_08a9c3ac lang=c99 */
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

int * FUN_08a9c3ac(int *param_1,undefined4 *param_2)
{
  undefined1 *puVar1;
  undefined1 *puVar2;
  undefined1 *puVar3;
  int iVar4;
  undefined1 local_30 [16];
  
  iVar4 = param_2[1];
  puVar3 = (undefined1 *)*param_2;
  local_30[0] = 0;
  FUN_0894af10(param_1 + 2,iVar4 + 1,local_30);
  puVar1 = (undefined1 *)param_1[2];
  puVar2 = puVar3 + iVar4;
  for (; puVar3 != puVar2; puVar3 = puVar3 + 1) {
    *puVar1 = *puVar3;
    puVar1 = puVar1 + 1;
  }
  *puVar1 = 0;
  iVar4 = param_1[2];
  *param_1 = iVar4;
  param_1[1] = (param_1[3] - iVar4) + -1;
  return param_1;
}

// Primary profile initial candidate: 1 differing words; disassembly and diff retained in try/lane-work.
// near miss from lane lbp1b (unreviewed)
