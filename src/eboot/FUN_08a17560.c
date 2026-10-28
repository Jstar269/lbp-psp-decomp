/* LBPMATCH module=EBOOT.BIN start=0x08a17560 end=0x08a175b0 symbol=FUN_08a17560 lang=c99 cc=gcc402x-Os */
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

extern void FUN_08adb8a4();

void FUN_08a17560(int *param_1)
{
  if (*param_1 != 0) {
    FUN_08adb8a4(*param_1);
  }
  if (param_1[1] != 0) {
    FUN_08adb8a4(param_1[1]);
    return;
  }
  return;
}
