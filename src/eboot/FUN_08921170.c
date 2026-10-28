/* LBPMATCH module=EBOOT.BIN start=0x08921170 end=0x089211a8 symbol=FUN_08921170 lang=c99 cc=gcc171-Os */
/* Mechanical translation of Ghidra pseudocode (lbpgen.py tag g3); exact match verified; names and types await human review. */
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

extern void FUN_08a9df6c();

void FUN_08921170(undefined4 param_1,int *param_2)
{
  if (*param_2 != 0) {
    FUN_08a9df6c(*param_2);
    *param_2 = 0;
  }
  return;
}
