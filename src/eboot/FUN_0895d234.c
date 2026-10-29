/* LBPMATCH module=EBOOT.BIN start=0x0895d234 end=0x0895d2c8 symbol=FUN_0895d234 lang=c99 */
/* Ghidra pseudocode (lbpgen.py tag gen) corrected by hand (lane lbp3d, Claude Sonnet 5.5): table pointer kept as (result + 4) and indexed by the element number; exact match verified; names and types await human review. */
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

extern undefined4 FUN_0891d6dc();
extern undefined4 FUN_0891d6e4();

int FUN_0895d234(int param_1)
{
  uint *tab;
  int iVar2;
  uint uVar3;
  int iVar4;
  uint uVar5;

  tab = (uint *)(FUN_0891d6e4(*(undefined4 **)(*(int *)(param_1 + 0x50) + 0xa8)) + 4);
  iVar2 = FUN_0891d6e4(*(undefined4 **)(*(int *)(param_1 + 0x50) + 0xa8));
  uVar5 = tab[*(int *)(param_1 + 0x28)];
  uVar3 = FUN_0891d6dc(*(int *)(*(int *)(param_1 + 0x50) + 0xa8));
  iVar4 = 0;
  if (uVar5 < uVar3) {
    iVar4 = iVar2 + tab[*(int *)(param_1 + 0x28)];
  }
  return iVar4;
}
