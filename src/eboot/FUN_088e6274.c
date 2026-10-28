/* LBPMATCH module=EBOOT.BIN start=0x088e6274 end=0x088e62a8 symbol=FUN_088e6274 lang=c99 cc=gcc402x-Os */
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


void FUN_088e6274(undefined4 param_1,undefined4 *param_2,int *param_3)
{
  (**(code **)(*param_3 + 0xc))(param_3);
  *param_2 = 0;
  return;
}
