/* LBPMATCH module=EBOOT.BIN start=0x08924540 end=0x08924590 symbol=FUN_08924540 lang=c99 cc=gcc410-Os */
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

extern undefined4 * DAT_08bedb18;
extern void FUN_08adb8a4();

void FUN_08924540(void)
{
  undefined4 *puVar1;
  
  puVar1 = DAT_08bedb18;
  if (DAT_08bedb18 != (undefined4 *)0x0) {
    (**(code **)*DAT_08bedb18)(DAT_08bedb18);
    FUN_08adb8a4(puVar1);
  }
  DAT_08bedb18 = (undefined4 *)0x0;
  return;
}
