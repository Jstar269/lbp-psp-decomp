/* LBPMATCH module=EBOOT.BIN start=0x08919630 end=0x089196f4 symbol=FUN_08919630 lang=c99 */
/* Ghidra pseudocode (lbpgen.py tag g14) corrected by hand (lane lbp1b, Codex GPT-6): restored virtual call object argument; matching idiom: goto; exact match verified; names and types await human review. */
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

extern void FUN_08a33068();

void FUN_08919630(undefined4 param_1,int param_2)
{
  int iVar1;
  int *piVar2;
  undefined4 *puVar3;
  
  if (*(int *)(param_2 + 4) != 0) {
    piVar2 = *(int **)(*(int *)(param_2 + 4) + 0x98);
    if (piVar2[0x11] != 0) {
      iVar1 = *(int *)(param_2 + 8);
      goto LAB_08919678;
    }
    if (piVar2[0x9d] != 3) {
      iVar1 = *(int *)(param_2 + 8);
      goto LAB_08919678;
    }
    FUN_08a33068(piVar2);
  }
  iVar1 = *(int *)(param_2 + 8);
LAB_08919678:
  if (iVar1 != 0) {
    puVar3 = *(undefined4 **)(iVar1 + 0x9c);
    while (puVar3 != (undefined4 *)(*(int *)(param_2 + 8) + 0x9c)) {
      iVar1 = (**(code **)(*(int *)puVar3[2] + 0x94))(puVar3[2]);
      if (*(int *)(iVar1 + 4) == 0) {
        puVar3 = (undefined4 *)*puVar3;
      }
      else {
        piVar2 = *(int **)(*(int *)(iVar1 + 4) + 0x98);
        if (piVar2[0x11] == 0) {
          if (piVar2[0x9d] == 3) {
            FUN_08a33068(piVar2);
          }
          puVar3 = (undefined4 *)*puVar3;
        }
        else {
          puVar3 = (undefined4 *)*puVar3;
        }
      }
    }
  }
  return;
}


