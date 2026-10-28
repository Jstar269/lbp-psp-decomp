/* LBPMATCH module=EBOOT.BIN start=0x0896ee40 end=0x0896ee90 symbol=FUN_0896ee40 lang=c99 cc=gcc402x-Os */
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

extern int DAT_08be85f8;
extern undefined4 DAT_08be85fc;
extern void FUN_08966c40();
extern void FUN_089720f8();
extern void FUN_08adb8a4();

void FUN_0896ee40(void)
{
  int iVar1;
  
  iVar1 = DAT_08be85f8;
  if (DAT_08be85f8 != 0) {
    FUN_08966c40(DAT_08be85f8);
    FUN_08adb8a4(iVar1);
  }
  DAT_08be85f8 = 0;
  FUN_089720f8(DAT_08be85fc);
  return;
}
