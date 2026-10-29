/* LBPMATCH module=EBOOT.BIN start=0x089f67e8 end=0x089f6810 symbol=FUN_089f67e8 lang=c99 */
/* Ghidra pseudocode (lbpgen.py tag g14) corrected by hand (lane lbp3b, Claude Sonnet 5.5): passed the field at +0x28 to the tail call; exact match verified; names and types await human review. */
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

extern void FUN_0897c25c(undefined4);

void FUN_089f67e8(int param_1,int param_2)
{
  int iVar1;
  
  iVar1 = *(int *)(param_1 + 0xc) + param_2;
  *(int *)(param_1 + 0xc) = iVar1;
  if (1000000 < iVar1) {
    *(undefined4 *)(param_1 + 0xc) = 1000000;
  }
  FUN_0897c25c(*(undefined4 *)(param_1 + 0x28));
  return;
}
