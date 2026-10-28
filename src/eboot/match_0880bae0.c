/* LBPMATCH module=EBOOT.BIN start=0x0880bae0 end=0x0880bb44 symbol=FUN_0880bae0 lang=c99 */
/* Ghidra pseudocode (lbpgen.py tag g14) corrected by hand (lane lbp1b, Codex GPT-6): corrected byte signedness; exact match verified; names and types await human review. */
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

extern void FUN_0882a780();
extern void FUN_0882c01c();

void FUN_0880bae0(int param_1,undefined4 param_2)
{
  int iVar1;
  
  iVar1 = *(int *)(param_1 + 4);
  if (iVar1 != 0) {
    if (*(unsigned char *)(iVar1 + 0x298) != '\0') {
      FUN_0882c01c(iVar1);
    }
    iVar1 = *(int *)(param_1 + 4);
    FUN_0882a780(iVar1,param_2);
    return;
  }
  return;
}

