/* LBPMATCH module=EBOOT.BIN start=0x08a698c0 end=0x08a698f0 symbol=FUN_08a698c0 lang=c99 cc=gcc402x-Os */
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

extern undefined4 FUN_08a50fbc();
extern void FUN_08a8e428();

void FUN_08a698c0(int param_1)
{
  int iVar1;
  
  iVar1 = FUN_08a50fbc();
  FUN_08a8e428(iVar1 + 0xb7c,param_1,*(int *)(param_1 + 0x24c));
  return;
}
