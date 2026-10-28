/* LBPMATCH module=EBOOT.BIN start=0x088edc64 end=0x088edca8 symbol=FUN_088edc64 lang=c99 cc=gcc402x-Os */
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

extern void FUN_088ec5d0();
extern void FUN_088edbe8();

void FUN_088edc64(int param_1)
{
  FUN_088edbe8(param_1);
  if (*(int *)(param_1 + 0x2a4) == 2) {
    FUN_088ec5d0(param_1);
    return;
  }
  return;
}
