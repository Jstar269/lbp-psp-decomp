/* LBPMATCH module=EBOOT.BIN start=0x08a16730 end=0x08a16778 symbol=FUN_08a16730 lang=c99 cc=gcc402x-O2 */
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


undefined4 FUN_08a16730(int *param_1,int param_2)
{
  if (((uint)(*(int *)(*param_1 + 4) + param_2 * 2) < 0xffe) &&
     ((uint)(param_2 * 2 + *(int *)(param_1[1] + 4)) < 0xffe)) {
    return 1;
  }
  return 0;
}
