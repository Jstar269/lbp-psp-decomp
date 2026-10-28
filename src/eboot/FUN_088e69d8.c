/* LBPMATCH module=EBOOT.BIN start=0x088e69d8 end=0x088e6a04 symbol=FUN_088e69d8 lang=c99 cc=gcc410-Os */
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

extern void FUN_088e6940();

void FUN_088e69d8(int param_1)
{
  FUN_088e6940(param_1);
  *(undefined1 *)(param_1 + 0x2a0) = 1;
  return;
}
