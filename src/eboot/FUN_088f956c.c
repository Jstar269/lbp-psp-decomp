/* LBPMATCH module=EBOOT.BIN start=0x088f956c end=0x088f95a4 symbol=FUN_088f956c lang=c99 cc=gcc410-Os */
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
typedef float undefined4;

extern undefined * DAT_08bf7304;
extern undefined4 FUN_08a50fbc();

void FUN_088f956c(int *param_1)
{
  FUN_08a50fbc();
  *(undefined4 *)(*param_1 + 0x14) = *(undefined4 *)(DAT_08bf7304 + 0x900);
  return;
}
