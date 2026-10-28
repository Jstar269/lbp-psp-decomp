/* LBPMATCH module=EBOOT.BIN start=0x0891baf4 end=0x0891bb24 symbol=FUN_0891baf4 lang=c99 cc=gcc410-Os */
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

extern void FUN_0891953c();
extern void FUN_0891aad8();
extern void FUN_0891b7e4();

void FUN_0891baf4(int param_1)
{
  FUN_0891b7e4(param_1);
  FUN_0891953c(param_1);
  FUN_0891aad8(param_1);
  return;
}
