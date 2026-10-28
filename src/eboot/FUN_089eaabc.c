/* LBPMATCH module=EBOOT.BIN start=0x089eaabc end=0x089eaae0 symbol=FUN_089eaabc lang=c99 cc=gcc410-Os */
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

extern undefined4 DAT_08bf03b8;
extern void FUN_088b4944();
extern void FUN_0896f198();

void FUN_089eaabc(int param_1)
{
  FUN_088b4944((int *)(param_1 + 0x9c));
  FUN_0896f198(DAT_08bf03b8);
  return;
}
