/* LBPMATCH module=EBOOT.BIN start=0x08b8cff8 end=0x08b8d018 symbol=FUN_08b8cff8 lang=c99 cc=gcc402x-O2 */
/* Mechanical translation of Ghidra pseudocode (lbpgen.py tag g8); exact match verified; names and types await human review. */
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

extern undefined4 DAT_08be4bf8;
extern undefined DAT_08c15090;

undefined * FUN_08b8cff8(void)
{
  undefined *puVar1;
  
  puVar1 = (undefined *)0x0;
  if (DAT_08be4bf8 == 0) {
    puVar1 = &DAT_08c15090;
  }
  return puVar1;
}
