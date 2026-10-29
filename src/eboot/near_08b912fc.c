/* LBPMATCH module=EBOOT.BIN start=0x08b912fc end=0x08b9138c symbol=FUN_08b912fc lang=c99 cc=gcc404xs-O2 */
/* Ghidra pseudocode (lbpgen.py tag g8) corrected by hand (lane lbp3a, Claude Sonnet 5.5): needs cc=gcc404xs-O2 (grow path out of line) and the capacity test written as (size + n) > capacity; exact match verified; names and types await human review. */
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

extern void FUN_08b911f4();
extern undefined4 * FUN_08b9e7a8();

void FUN_08b912fc(int param_1,undefined4 *param_2,int param_3)
{
  int iVar1;
  int iVar2;
  
  iVar2 = *(int *)(param_1 + 4);
  if (iVar2 != 0) {
    iVar1 = *(int *)(param_1 + 8);
    if ((uint)(iVar1 + param_3) > *(uint *)(param_1 + 0xc)) {
      FUN_08b911f4(param_1,param_3);
      iVar2 = *(int *)(param_1 + 4);
      if (iVar2 == 0) {
        return;
      }
      iVar1 = *(int *)(param_1 + 8);
    }
    FUN_08b9e7a8((undefined4 *)(iVar2 + iVar1),param_2,param_3);
    *(int *)(param_1 + 8) = param_3 + *(int *)(param_1 + 8);
  }
  return;
}
