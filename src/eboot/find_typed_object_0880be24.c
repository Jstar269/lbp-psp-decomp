/* LBPMATCH module=EBOOT.BIN start=0x0880be24 end=0x0880bef0 symbol=FUN_0880be24 lang=c99 */
/* Ghidra pseudocode (lbpgen.py tag g14) corrected by hand (lane lbp4a, Claude Sonnet 5.5): replaced the compare ladder by a switch over the six accepted types; exact match verified; names and types await human review. */
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
extern undefined4 FUN_08a52bb8();

int FUN_0880be24(undefined4 param_1,int param_2)
{
  int iVar1;
  int iVar2;
  int iVar3;
  uint uVar4;
  uint local_20 [4];
  
  if ((param_2 != 0) && (uVar4 = 0, *(int *)(param_2 + 0x44) == 0x23)) {
    while (uVar4 < *(uint *)(param_2 + 0x9c)) {
      iVar1 = FUN_08a50fbc();
      local_20[0] = *(uint *)(uVar4 * 4 + *(int *)(param_2 + 0xa0));
      uVar4 = uVar4 + 1;
      iVar1 = FUN_08a52bb8(iVar1,local_20);
      iVar3 = *(int *)(iVar1 + 0x44);
      switch (iVar3) {
      case 6: case 0x2b: case 0x30: case 0x31: case 0x35: case 0x37:
        return iVar1;
      }
    }
  }
  return param_2;
}
