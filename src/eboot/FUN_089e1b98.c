/* LBPMATCH module=EBOOT.BIN start=0x089e1b98 end=0x089e1bb8 symbol=FUN_089e1b98 lang=c99 cc=gcc402x-O1 */
/* Mechanical translation of Ghidra pseudocode (lbpgen.py tag g13); exact match verified; names and types await human review. */
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


void FUN_089e1b98(undefined4 *param_1)
{
  *param_1 = 0xffffffff;
  param_1[1] = 3;
  param_1[4] = 0;
  param_1[2] = 0;
  param_1[3] = 0;
  return;
}
