/* LBPMATCH module=EBOOT.BIN start=0x0898e3f4 end=0x0898e428 symbol=FUN_0898e3f4 lang=c99 cc=gcc410-Os */
/* Mechanical translation of Ghidra pseudocode (lbpgen.py tag g2); exact match verified; names and types await human review. */
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

extern void FUN_08921a38();
extern void FUN_08a9bff8();

void FUN_0898e3f4(int param_1)
{
  FUN_08921a38((undefined4 *)(param_1 + 0x3c));
  FUN_08921a38((undefined4 *)(param_1 + 0x20));
  FUN_08a9bff8(param_1 + 8);
  return;
}
