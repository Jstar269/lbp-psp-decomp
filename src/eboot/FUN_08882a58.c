/* LBPMATCH module=EBOOT.BIN start=0x08882a58 end=0x08882a80 symbol=FUN_08882a58 lang=c99 cc=gcc171-Os */
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

extern undefined * DAT_08bedfb4;

undefined4 FUN_08882a58(void)
{
  undefined4 uVar1;
  
  uVar1 = 0;
  if ((DAT_08bedfb4 == 0) || (*(uchar *)(DAT_08bedfb4 + 0xd6) != '\0')) {
    uVar1 = 1;
  }
  return uVar1;
}
