/* LBPMATCH module=EBOOT.BIN start=0x08964a9c end=0x08964ac4 symbol=FUN_08964a9c lang=c99 cc=gcc171-Os */
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

extern int * DAT_08bf5e44;

undefined4 FUN_08964a9c(void)
{
  undefined4 uVar1;
  
  uVar1 = 1;
  if ((DAT_08bf5e44 == (int *)0x0) || (*DAT_08bf5e44 == 0)) {
    uVar1 = 0;
  }
  return uVar1;
}
