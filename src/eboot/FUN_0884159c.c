/* LBPMATCH module=EBOOT.BIN start=0x0884159c end=0x088415f8 symbol=FUN_0884159c lang=c99 cc=gcc410-Os */
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

extern int * DAT_08bedb54;
extern void FUN_088050b8();

void FUN_0884159c(void)
{
  int *piVar1;
  
  piVar1 = (int *)DAT_08bedb54[2];
  DAT_08bedb54[2] = 0;
  if (piVar1 != (int *)0x0) {
    FUN_088050b8(piVar1);
  }
  if (DAT_08bedb54 != (int *)0x0) {
    (**(code **)(*DAT_08bedb54 + 4))(DAT_08bedb54);
  }
  DAT_08bedb54 = (int *)0x0;
  return;
}
