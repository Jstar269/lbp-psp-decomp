/* LBPMATCH module=EBOOT.BIN start=0x08a5521c end=0x08a55260 symbol=FUN_08a5521c lang=c99 cc=gcc402x-Os */
/* Mechanical translation of Ghidra pseudocode (lbpgen.py tag g6); exact match verified; names and types await human review. */
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

extern void FUN_088266f0();

void FUN_08a5521c(undefined4 param_1,undefined4 *param_2)
{
  FUN_088266f0(param_1,6,param_2);
  FUN_088266f0(param_1,2,param_2 + 1);
  return;
}
