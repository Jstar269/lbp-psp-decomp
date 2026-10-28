/* LBPMATCH module=EBOOT.BIN start=0x08a3e220 end=0x08a3e264 symbol=FUN_08a3e220 lang=c99 cc=gcc402x-Os */
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

extern void FUN_08a3fa40();
extern undefined4 FUN_08a50fbc();
extern void FUN_08a70db4();

void FUN_08a3e220(int param_1,uchar param_2)
{
  int iVar1;
  
  iVar1 = FUN_08a50fbc();
  FUN_08a3fa40(iVar1 + 0xc20,param_1 + 0x24c);
  FUN_08a70db4((int *)param_1,param_2);
  return;
}
