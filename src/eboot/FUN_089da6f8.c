/* LBPMATCH module=EBOOT.BIN start=0x089da6f8 end=0x089da72c symbol=FUN_089da6f8 lang=c99 cc=gcc402x-Os */
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

extern void FUN_089da51c();
extern int FUN_089df2b0();

void FUN_089da6f8(int param_1,int param_2)
{
  FUN_089df2b0(param_1,param_2,0,*(int *)(param_1 + 0x2c) + 1);
  FUN_089da51c(param_1);
  return;
}
