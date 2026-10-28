/* LBPMATCH module=EBOOT.BIN start=0x08966c28 end=0x08966c40 symbol=FUN_08966c28 lang=c99 cc=gcc410-Os rodata=0x08bab59c */
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


float FUN_08966c28(float param_1)
{
  return 1.0f - (param_1 - 1.0f) * (param_1 - 1.0f);
}
