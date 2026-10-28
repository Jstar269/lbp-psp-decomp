/* LBPMATCH module=EBOOT.BIN start=0x08842dbc end=0x08842e0c symbol=FUN_08842dbc lang=c99 cc=gcc402x-Os */
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

extern undefined4 * DAT_08bedb74;
extern void FUN_088050b8();
extern void FUN_08a9e0cc();

void FUN_08842dbc(void)
{
  undefined4 *puVar1;
  
  puVar1 = DAT_08bedb74;
  if (DAT_08bedb74 != (undefined4 *)0x0) {
    if ((int *)*DAT_08bedb74 != (int *)0x0) {
      FUN_088050b8((int *)*DAT_08bedb74);
    }
    FUN_08a9e0cc((uint)puVar1);
  }
  DAT_08bedb74 = (undefined4 *)0x0;
  return;
}
