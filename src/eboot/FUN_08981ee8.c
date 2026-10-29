/* LBPMATCH module=EBOOT.BIN start=0x08981ee8 end=0x08982010 symbol=FUN_08981ee8 lang=c99 rodata=0x08bbec94 */
/* Ghidra pseudocode (lbpgen.py tag gen) corrected by hand (lane lbp3d, Claude Sonnet 5.5): declared the locals in a different order for the stack layout, and called the hash function separately in each branch of the theme/category test; exact match verified; names and types await human review. */
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

extern void FUN_08970b6c();
extern undefined4 * FUN_08981e68();
extern void FUN_089dcfac();
extern uint FUN_08adbd60();

void FUN_08981ee8(int param_1)
{
  undefined4 *puVar1;
  int iVar2;
  uint uVar3;
  code *pcVar4;
  char *pcVar5;
  int *piVar6;
  undefined4 *local_28 [2];
  undefined4 *local_30;
  undefined4 local_2c;
  
  local_2c = 0xffffffff;
  FUN_08981e68(local_28,0x1397,&local_2c);
  puVar1 = local_28[0];
  if (local_28[0] != (undefined4 *)0x0) {
    *(short *)((int)local_28[0] + 6) = *(short *)((int)local_28[0] + 6) + 1;
  }
  piVar6 = *(int **)(param_1 + 8);
  for (; piVar6 != (int *)0x0; piVar6 = (int *)piVar6[2]) {
    local_30 = puVar1;
    pcVar4 = *(code **)(*piVar6 + 8);
    if (puVar1 != (undefined4 *)0x0) {
      *(short *)((int)puVar1 + 6) = *(short *)((int)puVar1 + 6) + 1;
    }
    iVar2 = (*pcVar4)(piVar6,&local_30);
    if (local_30 != (undefined4 *)0x0) {
      FUN_08970b6c(local_30);
    }
    if (iVar2 == 0) break;
  }
  if (puVar1 != (undefined4 *)0x0) {
    FUN_08970b6c(puVar1);
  }
  if (local_28[0][3] != -1) {
    if (local_28[0][3] == 0) { uVar3 = FUN_08adbd60((byte *)"theme"); } else { uVar3 = FUN_08adbd60((byte *)"category"); }
    FUN_089dcfac(param_1,~uVar3);
  }
  if (local_28[0] != (undefined4 *)0x0) {
    FUN_08970b6c(local_28[0]);
  }
  return;
}
