/* LBPMATCH module=EBOOT.BIN start=0x089e53c8 end=0x089e53dc symbol=FUN_089e53c8 lang=c99 cc=gcc410-Os */
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

void FUN_089e53c8(undefined4 param_1,char *param_2)
{
  *(undefined1 *)(param_2 + DAT_08be8600 + 0x322) = 0;
  return;
}
