/* LBPMATCH module=EBOOT.BIN start=0x08a09db4 end=0x08a09df4 symbol=FUN_08a09db4 lang=c99 cc=gcc402x-O2 */
/* Mechanical translation of Ghidra pseudocode (lbpgen.py tag g8); exact match verified; names and types await human review. */
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


void FUN_08a09db4(int *param_1)
{
  int iVar1;
  
  iVar1 = (**(code **)(*param_1 + 0x4c))();
  if (iVar1 == 0) {
    param_1[0x19] = param_1[0x19] | 0x10;
  }
  return;
}
