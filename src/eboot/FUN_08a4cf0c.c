/* LBPMATCH module=EBOOT.BIN start=0x08a4cf0c end=0x08a4cf2c symbol=FUN_08a4cf0c lang=c99 cc=gcc402x-O2 */
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

extern void FUN_08a4b914();
extern void FUN_08a4c794();

void FUN_08a4cf0c(int *param_1,int param_2)
{
  if (*(int *)(*param_1 + 0x34) != 0) {
    FUN_08a4c794(param_2);
    return;
  }
  FUN_08a4b914(param_2);
  return;
}
