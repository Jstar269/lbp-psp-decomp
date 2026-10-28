/* LBPMATCH module=EBOOT.BIN start=0x08b8b7dc end=0x08b8b818 symbol=FUN_08b8b7dc lang=c99 cc=gcc410-Os */
/* Mechanical translation of Ghidra pseudocode (lbpgen.py tag g2); exact match verified; names and types await human review. */
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

extern void FUN_08b8b6d8();

int FUN_08b8b7dc(int *param_1)
{
  int iVar1;
  
  iVar1 = *param_1;
  if (-1 < *(int *)(iVar1 + -4)) {
    FUN_08b8b6d8(param_1);
    iVar1 = *param_1;
  }
  return iVar1;
}
