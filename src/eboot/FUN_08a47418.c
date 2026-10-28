/* LBPMATCH module=EBOOT.BIN start=0x08a47418 end=0x08a47464 symbol=FUN_08a47418 lang=c99 cc=gcc402x-Os */
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

extern void FUN_0895541c();
extern void FUN_08a34774();
extern void FUN_08a56ec8();

void FUN_08a47418(int param_1,int *param_2)
{
  FUN_08a34774(param_1,param_2,0x56414e43);
  FUN_08a56ec8((int *)(param_1 + 0xbc),param_2,(int *)param_1);
  FUN_0895541c(param_2);
  return;
}
