/* LBPMATCH module=EBOOT.BIN start=0x0880bf6c end=0x0880c03c symbol=FUN_0880bf6c lang=c99 */
/* Ghidra pseudocode (lbpgen.py tag g4) corrected by hand (lane lbp4c, Claude Sonnet 5.5): flag test written !(x & 1) (andi+beqz, not xori), and the address &param_2[0x24] kept in a local declared before the -1 test (puts addiu a1 in the beq delay slot); exact match verified; names and types await human review. */
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

extern undefined4 FUN_08a50fbc();
extern undefined4 FUN_08a51e74();
extern undefined4 FUN_08a52bb8();

undefined4 FUN_0880bf6c(undefined4 param_1,int param_2)
{
  int iVar1;
  int iVar2;
  
  iVar1 = *(int *)(param_2 + 0x44);
  if (iVar1 != 0x2b) {
    if (iVar1 == 0xd) {
      return 1;
    }
    if (iVar1 == 0x28) {
      return 1;
    }
    if (iVar1 != 0x23) {
      return 0;
    }
    iVar1 = FUN_08a50fbc();
    if (*(uint *)(param_2 + 0x98) == 0xffffffff) {
      iVar2 = *(int *)(param_2 + 0x90);
    }
    else {
      iVar2 = FUN_08a51e74(iVar1,*(uint *)(param_2 + 0x98));
      if (iVar2 == 0) {
        iVar2 = *(int *)(param_2 + 0x90);
      }
      else {
        if (!(*(uint *)(iVar2 + 0x20) & 1)) {
          return 1;
        }
        iVar2 = *(int *)(param_2 + 0x90);
      }
    }
    uint *q = (uint *)(param_2 + 0x90);
    if (iVar2 == -1) {
      return 0;
    }
    iVar1 = FUN_08a52bb8(iVar1,q);
    if (iVar1 == 0) {
      return 0;
    }
    if (*(int *)(iVar1 + 0x44) != 0x23) {
      return 0;
    }
  }
  return 1;
}
