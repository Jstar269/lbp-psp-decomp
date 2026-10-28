/* LBPMATCH module=EBOOT.BIN start=0x089da734 end=0x089da744 symbol=FUN_089da734 lang=c99 cc=gcc171-Os */
/* Mechanical translation of Ghidra pseudocode (lbpgen.py tag g3); exact match verified; names and types await human review. */
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


int FUN_089da734(int param_1)
{
  int iVar1;
  
  iVar1 = *(int *)(param_1 + 0x20) + 0x300;
  if (*(int *)(param_1 + 0x20) == 0) {
    iVar1 = 0;
  }
  return iVar1;
}
