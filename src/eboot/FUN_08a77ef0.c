/* LBPMATCH module=EBOOT.BIN start=0x08a77ef0 end=0x08a77f20 symbol=FUN_08a77ef0 lang=c99 cc=gcc402x-O2 */
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

extern undefined4 DAT_08bf7304;
extern undefined4 FUN_08a50fbc();

int FUN_08a77ef0(void)
{
  FUN_08a50fbc();
  FUN_08a50fbc();
  return DAT_08bf7304 + 0x64b0;
}
