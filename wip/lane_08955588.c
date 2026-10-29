/* LBPMATCH module=EBOOT.BIN start=0x08955588 end=0x08955758 symbol=FUN_08955588 lang=c99 */
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

extern void FUN_08955428();
extern undefined4 * FUN_08b9e7a8();

void FUN_08955588(int param_1,undefined4 *param_2,int param_3,int *param_4)
{
  char cVar1;
  int iVar2;
  int iVar3;
  undefined4 *puVar4;
  int *piVar5;
  undefined4 local_2c;
  int *local_30;
  
  *(undefined4 *)(param_1 + 0x18) = 4;
  while (((uint)*(undefined1 **)(param_1 + 4) & 3) != 0) {
    if (*(char *)(*(int *)(param_1 + 0x30) + 0xc) == '\0') {
      **(undefined1 **)(param_1 + 4) = 0;
    }
    *(int *)(param_1 + 4) = *(int *)(param_1 + 4) + 1;
  }
  param_4[6] = 4;
  while (((uint)param_4[1] & 3) != 0) {
    if (*(char *)(param_4[0xc] + 0xc) == '\0') {
      *(undefined1 *)param_4[1] = 0;
    }
    param_4[1] = param_4[1] + 1;
  }
  local_2c = 0;
  piVar5 = *(int **)(param_1 + 4);
  if (*(char *)(*(int *)(param_1 + 0x30) + 0xc) == '\0') {
    *piVar5 = 0;
  }
  iVar3 = param_4[0xc];
  *(int *)(param_1 + 4) = *(int *)(param_1 + 4) + 4;
  puVar4 = (undefined4 *)param_4[1];
  iVar2 = *param_4;
  cVar1 = *(char *)(iVar3 + 0xc);
  *(int *)(param_1 + 0x14) = *(int *)(param_1 + 0x14) + 4;
  local_30 = piVar5;
  if (cVar1 == '\0') {
    FUN_08b9e7a8(puVar4,param_2,param_3);
  }
  cVar1 = *(char *)(*(int *)(param_1 + 0x30) + 0xc);
  param_4[1] = param_4[1] + param_3;
  param_4[5] = param_4[5] + param_3;
  if (cVar1 == '\0') {
    *piVar5 = (int)puVar4 - iVar2;
  }
  puVar4 = *(undefined4 **)(param_1 + 0x28);
  if (puVar4 == *(undefined4 **)(param_1 + 0x2c)) {
    FUN_08955428((int *)(param_1 + 0x24),puVar4,&local_30);
  }
  else {
    if (puVar4 != (undefined4 *)0x0) {
      *puVar4 = local_30;
    }
    *(undefined4 **)(param_1 + 0x28) = puVar4 + 1;
  }
  *(undefined4 *)(param_1 + 0x18) = 4;
  while (((uint)*(undefined1 **)(param_1 + 4) & 3) != 0) {
    if (*(char *)(*(int *)(param_1 + 0x30) + 0xc) == '\0') {
      **(undefined1 **)(param_1 + 4) = 0;
    }
    *(int *)(param_1 + 4) = *(int *)(param_1 + 4) + 1;
  }
  param_4[6] = 4;
  while (((uint)param_4[1] & 3) != 0) {
    if (*(char *)(param_4[0xc] + 0xc) == '\0') {
      *(undefined1 *)param_4[1] = 0;
    }
    param_4[1] = param_4[1] + 1;
  }
  return;
}

// 134 words differ; generated candidate under the primary profile needs typed structure and unaligned copy reconstruction.
// near miss from lane lbp15d (unreviewed)
