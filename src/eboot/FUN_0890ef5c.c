/* LBPMATCH module=EBOOT.BIN start=0x0890ef5c end=0x0890ef78 symbol=FUN_0890ef5c lang=c99 cc=gcc410-Os */
/* Mechanical translation of Ghidra pseudocode (lbpgen.py tag g2); exact match verified; names and types await human review. */
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

extern void FUN_088050b8();

void FUN_0890ef5c(int param_1)
{
  if (*(int **)(param_1 + 0x1814) != (int *)0x0) {
    FUN_088050b8(*(int **)(param_1 + 0x1814));
    return;
  }
  return;
}
