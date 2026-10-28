/* LBPMATCH module=EBOOT.BIN start=0x088375fc end=0x08837728 symbol=FUN_088375fc lang=c99 */
/* Ghidra pseudocode (lbpgen.py tag g14) corrected by hand (lane lbp1b, Codex GPT-6): restored virtual call object argument; exact match verified; names and types await human review. */
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

extern void FUN_088050b8();
extern void FUN_088374f0();
extern void FUN_08a1d8d0();
extern void FUN_08a34728();
extern void FUN_08a9e0c4();
extern void FUN_08a9e0cc();

void FUN_088375fc(undefined4 *param_1)
{
  uint *puVar1;
  int *piVar2;
  uint uVar3;
  int iVar4;
  undefined4 *puVar5;
  
  piVar2 = (int *)param_1[0x10];
  param_1[0x10] = 0;
  if (piVar2 != (int *)0x0) {
    FUN_088050b8(piVar2);
  }
  piVar2 = (int *)param_1[9];
  param_1[9] = 0;
  if (piVar2 != (int *)0x0) {
    FUN_088050b8(piVar2);
  }
  piVar2 = (int *)param_1[0x11];
  param_1[0x11] = 0;
  if (piVar2 != (int *)0x0) {
    FUN_088050b8(piVar2);
  }
  if (param_1[2] != 0) {
    FUN_08a9e0c4(param_1[2]);
  }
  FUN_088374f0((int)(param_1 + 3));
  puVar5 = (undefined4 *)param_1[0x13];
  param_1[10] = 0;
  if (puVar5 != (undefined4 *)0x0) {
    FUN_08a1d8d0(puVar5);
    FUN_08a9e0cc((uint)puVar5);
  }
  puVar5 = (undefined4 *)param_1[0x14];
  if (puVar5 != (undefined4 *)0x0) {
    FUN_08a1d8d0(puVar5);
    FUN_08a9e0cc((uint)puVar5);
  }
  uVar3 = param_1[0x34];
  if (uVar3 != 0) {
    FUN_08a9e0c4(uVar3);
    param_1[0x34] = 0;
  }
  uVar3 = param_1[0x46];
  if (uVar3 != 0) {
    FUN_08a9e0c4(uVar3);
    param_1[0x46] = 0;
  }
  uVar3 = param_1[0x44];
  if (uVar3 != 0) {
    FUN_08a9e0c4(uVar3);
    param_1[0x44] = 0;
  }
  piVar2 = (int *)*param_1;
  puVar1 = (uint *)(**(code **)(*piVar2 + 0x94))(piVar2);
  iVar4 = *param_1;
  *puVar1 = *puVar1 & 0xffffafff;
  FUN_08a34728(iVar4,1);
  return;
}

