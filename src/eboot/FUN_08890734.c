/* LBPMATCH module=EBOOT.BIN start=0x08890734 end=0x08890784 symbol=FUN_08890734 lang=c99 cc=gcc402x-Os */
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

extern void FUN_0888b8c4();
extern void FUN_0888b8cc();
extern void FUN_088906d4();

void FUN_08890734(int param_1,undefined4 param_2)
{
  FUN_0888b8c4(param_1 + 0x2c);
  FUN_088906d4(param_1,param_2);
  FUN_0888b8cc(param_1 + 0x2c);
  return;
}
