/* LBPMATCH module=EBOOT.BIN start=0x0887bde8 end=0x0887be18 symbol=FUN_0887bde8 lang=c99 cc=gcc402x-Os */
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

extern void FUN_08a9e0c4();
extern void FUN_08a9e824();

void FUN_0887bde8(int param_1,uint param_2)
{
  if (param_1 != 0) {
    FUN_08a9e0c4(param_1);
  }
  FUN_08a9e824(param_2);
  return;
}
