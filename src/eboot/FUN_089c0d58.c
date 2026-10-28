/* LBPMATCH module=EBOOT.BIN start=0x089c0d58 end=0x089c0d8c symbol=FUN_089c0d58 lang=c99 cc=gcc402x-Os */
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

extern void FUN_089d1dfc();
extern void FUN_089d222c();

void FUN_089c0d58(int param_1,undefined4 *param_2)
{
  FUN_089d1dfc(*(int *)(param_1 + 0xc),param_2,'\0');
  FUN_089d222c(*(int *)(param_1 + 0xc),'\0');
  return;
}
