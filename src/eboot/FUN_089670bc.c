/* LBPMATCH module=EBOOT.BIN start=0x089670bc end=0x0896711c symbol=FUN_089670bc lang=c99 cc=gcc402x-Os */
/* Mechanical translation of Ghidra pseudocode (lbpgen.py tag g6); exact match verified; names and types await human review. */
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

extern void FUN_08966e48();
extern void FUN_0896aeec();

void FUN_089670bc(int param_1,int param_2)
{
  if (((*(int **)(param_1 + 0x40))[1] & 4U) != 0) {
    FUN_0896aeec(*(int **)(param_1 + 0x40),param_2);
    FUN_08966e48(param_1,param_2);
    return;
  }
  return;
}
