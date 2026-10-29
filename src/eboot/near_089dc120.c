/* LBPMATCH module=EBOOT.BIN start=0x089dc120 end=0x089dc178 symbol=FUN_089dc120 lang=c99 */
/* Ghidra pseudocode (lbpgen.py tag g14) corrected by hand (lane lbp3a, Claude Sonnet 5.5): the cleared field is reset by a separate non-inlined call (tail call to 0x089e06a8, which stores zero at +0x10); retail does not inline it; exact match verified; names and types await human review. */
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

extern void FUN_08a9e0cc();
extern void FUN_089e06a8(int);

void FUN_089dc120(int param_1)
{
  int *piVar1;
  int iVar2;
  
  piVar1 = *(int **)(param_1 + 0x10);
  if (piVar1 != (int *)0x0) {
    iVar2 = (**(code **)(*piVar1 + 0x4c))(piVar1);
    FUN_08a9e0cc(*(uint *)(iVar2 + 0x14));
    *(undefined4 *)(iVar2 + 0x14) = 0;
  }
  FUN_089e06a8(param_1);
  return;
}
