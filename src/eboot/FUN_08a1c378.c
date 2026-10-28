/* LBPMATCH module=EBOOT.BIN start=0x08a1c378 end=0x08a1c3b0 symbol=FUN_08a1c378 lang=c99 cc=gcc402x-Os */
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

extern void FUN_08a1b424();
extern void FUN_08a9e0c4();

void FUN_08a1c378(int param_1)
{
  if (*(uint *)(param_1 + 0x24) != 0) {
    FUN_08a9e0c4(*(uint *)(param_1 + 0x24));
  }
  FUN_08a1b424((uint *)(param_1 + 0xc));
  return;
}
