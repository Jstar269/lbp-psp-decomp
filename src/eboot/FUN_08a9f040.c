/* LBPMATCH module=EBOOT.BIN start=0x08a9f040 end=0x08a9f058 symbol=FUN_08a9f040 lang=c99 cc=gcc410-Os */
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

extern int FUN_08a9ecb8();

void FUN_08a9f040(undefined4 param_1,uint param_2,uint param_3)
{
  FUN_08a9ecb8(param_2,1 << (param_3 & 0x1f),0,0);
  return;
}
