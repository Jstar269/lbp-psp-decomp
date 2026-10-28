/* LBPMATCH module=EBOOT.BIN start=0x08a6b97c end=0x08a6b990 symbol=FUN_08a6b97c lang=c99 cc=gcc402x-O2 */
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

extern undefined4 DAT_08bf7194;

void FUN_08a6b97c(int param_1)
{
  *(undefined1 *)(param_1 + 0x1c4) = 1;
  DAT_08bf7194 = 0;
  return;
}
