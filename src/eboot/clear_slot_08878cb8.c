/* LBPMATCH module=EBOOT.BIN start=0x08878cb8 end=0x08878d24 symbol=FUN_08878cb8 lang=c99 */
/* Ghidra pseudocode (lbpgen.py tag g14) corrected by hand (lane lbp4a, Claude Sonnet 5.5): swapped the two final stores; exact match verified; names and types await human review. */
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

extern void FUN_08a9e0c4();

void FUN_08878cb8(int param_1,undefined4 param_2,undefined4 param_3)
{
  uint uVar1;
  undefined4 *puVar2;
  
  uVar1 = *(uint *)(*(int *)(param_1 + 0x10) * 4 + param_1);
  if (uVar1 != 0) {
    FUN_08a9e0c4(uVar1);
  }
  puVar2 = (undefined4 *)(*(int *)(param_1 + 0x10) * 4 + param_1);
  *puVar2 = param_2;
  puVar2[2] = param_3;
  return;
}
