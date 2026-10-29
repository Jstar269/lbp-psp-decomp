/* LBPMATCH module=EBOOT.BIN start=0x08a9162c end=0x08a916c8 symbol=FUN_08a9162c lang=c99 */
/* Ghidra pseudocode (lbpgen.py tag g14) corrected by hand (lane lbp3b, Claude Sonnet 5.5): the two copied fields are float; exact match verified; names and types await human review. */
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

extern undefined4 * FUN_08a10f1c();
extern void FUN_08a12ec0();
extern undefined4 FUN_08a50fbc();
extern undefined4 FUN_08a52b38();
extern void FUN_08a913f0();
extern void FUN_08a9a5c8();

void FUN_08a9162c(int param_1)
{
  int iVar1;
  int *piVar2;
  int *piVar3;
  undefined4 *puVar4;
  
  FUN_08a9a5c8((int *)param_1);
  FUN_08a913f0((undefined4 *)(param_1 + 0x180),(undefined4 *)(param_1 + 0x184),param_1 + 0x188,
               (undefined4 *)(param_1 + 0x18c));
  *(float *)(param_1 + 0x194) = *(float *)(param_1 + 0x1b0);
  *(float *)(param_1 + 0x198) = *(float *)(param_1 + 0x1bc);
  iVar1 = FUN_08a50fbc();
  piVar2 = (int *)FUN_08a52b38(iVar1,*(uint *)(param_1 + 0x19c));
  iVar1 = FUN_08a50fbc();
  piVar3 = (int *)FUN_08a52b38(iVar1,*(uint *)(param_1 + 0x1a0));
  puVar4 = FUN_08a10f1c();
  FUN_08a12ec0((int)puVar4,piVar2,piVar3,*(int **)(param_1 + 400),param_1,-1);
  return;
}
