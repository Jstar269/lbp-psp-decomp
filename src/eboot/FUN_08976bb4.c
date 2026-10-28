/* LBPMATCH module=EBOOT.BIN start=0x08976bb4 end=0x08976bfc symbol=FUN_08976bb4 lang=c99 cc=gcc402x-Os */
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

extern void FUN_088cc71c();
extern void FUN_08975c1c();
extern void FUN_08a9e0cc();

void FUN_08976bb4(int param_1)
{
  uint uVar1;
  
  uVar1 = *(uint *)(param_1 + 0x14);
  if (uVar1 != 0) {
    FUN_08975c1c(uVar1);
    FUN_08a9e0cc(uVar1);
  }
  FUN_088cc71c((int *)(param_1 + 8));
  return;
}
