/* LBPMATCH module=EBOOT.BIN start=0x08812040 end=0x088120c8 symbol=FUN_08812040 lang=c99 */
/* Ghidra pseudocode (lbpgen.py tag g14) corrected by hand (lane lbp2a, Codex GPT-6): reorder independent loads; exact match verified; names and types await human review. */
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

extern int FUN_0880d434();
extern void FUN_089757c0();
extern void FUN_08a34728();

void FUN_08812040(char *param_1,undefined1 param_2)
{
  int iVar1;
  int iVar2;
  uint local_20 [4];
  
  iVar2 = *(int *)(*(int *)(param_1 + 0x24) + 0x14);
  local_20[0] = *(uint *)(*(int *)(param_1 + 0x24) + 0x10);
  iVar1 = FUN_0880d434(param_1 + 0x5ec,local_20);
  if (iVar1 == param_1 + 0x5f0) {
    *(undefined1 *)(param_1 + 800) = 1;
    *(undefined1 *)(param_1 + 0x321) = param_2;
    *(int *)(param_1 + 0x2e4) = iVar2;
    FUN_08a34728(iVar2,0);
    *(undefined2 *)(param_1 + 0x322) = 2;
  }
  else {
    FUN_089757c0(9);
  }
  return;
}



