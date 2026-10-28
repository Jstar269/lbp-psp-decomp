/* LBPMATCH module=EBOOT.BIN start=0x088cb798 end=0x088cb7bc symbol=FUN_088cb798 lang=c99 cc=gcc410-Os */
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

extern void FUN_08922ed8();
extern void FUN_08924100();
extern void FUN_089474a0();

void FUN_088cb798(void)
{
  FUN_08922ed8();
  FUN_089474a0();
  FUN_08924100();
  return;
}
