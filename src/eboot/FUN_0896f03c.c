/* LBPMATCH module=EBOOT.BIN start=0x0896f03c end=0x0896f064 symbol=FUN_0896f03c lang=c99 cc=gcc410-Os */
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

extern undefined4 DAT_08be8600;
extern undefined4 DAT_08bf03d8;
extern void FUN_089e45c0();
extern void FUN_089e6cbc();

void FUN_0896f03c(void)
{
  FUN_089e45c0(DAT_08bf03d8);
  FUN_089e6cbc(DAT_08be8600);
  return;
}
