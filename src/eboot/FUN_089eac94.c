/* LBPMATCH module=EBOOT.BIN start=0x089eac94 end=0x089eacc4 symbol=FUN_089eac94 lang=c99 cc=gcc402x-O2 */
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

extern undefined DAT_08bf325c;

void FUN_089eac94(uint param_1)
{
  (&DAT_08bf325c)[param_1 >> 3] =
       (byte)(1 << (param_1 + (param_1 >> 3) * -8 & 0x1f)) | (&DAT_08bf325c)[param_1 >> 3];
  return;
}
