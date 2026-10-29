/* LBPMATCH module=EBOOT.BIN start=0x08914644 end=0x08914718 symbol=FUN_08914644 lang=c99 */
/* Hand-written reconstruction (external matching lane); exact match verified; names and types await human review. */
/* Ghidra pseudocode (lbpgen.py candidate) corrected by hand (lane lbp4b, Claude Sonnet 5.5): list end pointer kept in a named local before the first loop; exact match verified; names and types await human review. */
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
extern void FUN_088050b8();
extern void FUN_08918898();
extern void FUN_08a9e0cc();
extern void FUN_08adbc24();

void FUN_08914644(char *param_1)
{
  undefined4 *puVar1;
  undefined4 *puVar2;
  uint *puVar3;
  uint uVar4;
  
  puVar1 = *(undefined4 **)(param_1 + 0x30);
  if (puVar1 != (undefined4 *)0x0) {
    FUN_08918898(puVar1);
    FUN_08a9e0cc((uint)puVar1);
  }
  FUN_08a9e0cc(*(uint *)(param_1 + 0x3c));
  FUN_08a9e0cc(*(uint *)(param_1 + 0x54));
  if (*(int **)(param_1 + 0x58) == (int *)0x0) {
    puVar1 = *(undefined4 **)(param_1 + 0xc);
  }
  else {
    FUN_088050b8(*(int **)(param_1 + 0x58));
    puVar1 = *(undefined4 **)(param_1 + 0xc);
  }
  undefined4 *end = (undefined4 *)(param_1 + 0xc);
  while (puVar1 != end) {
    puVar2 = (undefined4 *)*puVar1;
    FUN_08adbc24(DAT_08be84a0,(uint)puVar1,0xc);
    puVar1 = puVar2;
  }
  puVar3 = (uint *)*(uint *)(param_1 + 4);
  while (puVar3 != (uint *)(param_1 + 4U)) {
    uVar4 = *puVar3;
    if ((int *)puVar3[2] != (int *)0x0) {
      FUN_088050b8((int *)puVar3[2]);
    }
    FUN_08adbc24(DAT_08be84a0,(uint)puVar3,0xc);
    puVar3 = (uint *)uVar4;
  }
  return;
}
