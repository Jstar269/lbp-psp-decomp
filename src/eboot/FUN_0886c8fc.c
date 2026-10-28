/* LBPMATCH module=EBOOT.BIN start=0x0886c8fc end=0x0886c924 symbol=FUN_0886c8fc lang=c99 cc=gcc171-Os */
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

extern bool FUN_0886c86c();

void FUN_0886c8fc(int *param_1,int *param_2)
{
  FUN_0886c86c((int *)(*param_1 + 0x10),(int *)(*param_2 + 0x10));
  return;
}
