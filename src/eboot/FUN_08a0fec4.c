/* LBPMATCH module=EBOOT.BIN start=0x08a0fec4 end=0x08a0fef0 symbol=FUN_08a0fec4 lang=c99 cc=gcc402x-O2 */
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

extern void FUN_08a0882c();

void FUN_08a0fec4(uint *param_1)
{
  if ((*param_1 & 0x40) == 0) {
    return;
  }
  *param_1 = *param_1 & 0xffffffaf;
  FUN_08a0882c(param_1[1]);
  return;
}
