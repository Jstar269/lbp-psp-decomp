/* LBPMATCH module=EBOOT.BIN start=0x08842d9c end=0x08842da8 symbol=FUN_08842d9c lang=c99 cc=gcc410-Os */
/* Mechanical translation of Ghidra pseudocode (lbpgen.py tag g1); exact match verified; names and types await human review. */
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

extern void FUN_08842ab0();

void FUN_08842d9c(void)
{
  FUN_08842ab0(1,0xffff);
  return;
}
