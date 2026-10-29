/* LBPMATCH module=EBOOT.BIN start=0x089703c8 end=0x08970494 symbol=FUN_089703c8 lang=c99 */
/* Ghidra pseudocode (lbpgen.py tag gen) corrected by hand (lane lbp3d, Claude Sonnet 5.5): stored the copied smart pointer into its stack slot before the refcount increment; exact match verified; names and types await human review. */
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

extern undefined4 FUN_0896b420();
extern void FUN_08970b6c();

void FUN_089703c8(int *param_1,int *param_2)
{
  code *pcVar1;
  int *piVar2;
  undefined4 *puVar3;
  undefined4 *local_1c [3];
  undefined4 *local_20;
  
  puVar3 = (undefined4 *)*param_2;
  if (puVar3 != (undefined4 *)0x0) {
    *(short *)((int)puVar3 + 6) = *(short *)((int)puVar3 + 6) + 1;
  }
  piVar2 = (int *)param_1[4];
  local_20 = puVar3;
  if (puVar3 != (undefined4 *)0x0) {
    *(short *)((int)puVar3 + 6) = *(short *)((int)puVar3 + 6) + 1;
  }
  FUN_0896b420(piVar2,(int *)&local_20);
  if (local_20 != (undefined4 *)0x0) {
    FUN_08970b6c(local_20);
  }
  if (puVar3 != (undefined4 *)0x0) {
    FUN_08970b6c(puVar3);
  }
  local_1c[0] = (undefined4 *)*param_2;
  pcVar1 = *(code **)(*param_1 + 8);
  if (local_1c[0] != (undefined4 *)0x0) {
    *(short *)((int)local_1c[0] + 6) = *(short *)((int)local_1c[0] + 6) + 1;
  }
  (*pcVar1)(param_1,local_1c);
  if (local_1c[0] != (undefined4 *)0x0) {
    FUN_08970b6c(local_1c[0]);
  }
  return;
}
