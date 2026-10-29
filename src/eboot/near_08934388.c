/* LBPMATCH module=EBOOT.BIN start=0x08934388 end=0x089343d8 symbol=FUN_08934388 lang=c99 */
/* Clone of src/eboot/near_088b5868.c (lbpclone.py tag c16): addresses substituted; exact match verified; names and types await human review. */
/* Ghidra pseudocode (lbpgen.py tag g14) corrected by hand (lane lbp3a, Claude Sonnet 5.5): the five field stores reordered (0x14, 4, 8, 0xc, 0x10) so the scheduler emits retail's store order; exact match verified; names and types await human review. */
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

extern uint * FUN_08b9eb88();

void FUN_08934388(int param_1)
{
  uint *puVar1;
  
  puVar1 = (uint *)(param_1 + 4);
  FUN_08b9eb88(puVar1,0,0x10);
  *(undefined4 *)(param_1 + 0x14) = 0;
  *(undefined4 *)(param_1 + 4) = 0;
  *(undefined4 *)(param_1 + 8) = 0;
  *(uint **)(param_1 + 0xc) = puVar1;
  *(uint **)(param_1 + 0x10) = puVar1;
  return;
}
