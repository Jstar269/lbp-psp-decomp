/* LBPMATCH module=EBOOT.BIN start=0x0894bc0c end=0x0894bc14 symbol=FUN_0894bc0c lang=c99 cc=gcc402x-Os */
/* Mechanical translation of Ghidra pseudocode (lbpgen.py tag g12); exact match verified; names and types await human review. */
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

extern void FUN_0894b890();

void FUN_0894bc0c(int param_1,int param_2,int param_3,int param_4)
{
  FUN_0894b890(*(int **)(param_1 + 8),param_2,param_3,param_4);
  return;
}
