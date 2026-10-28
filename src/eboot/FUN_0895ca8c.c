/* LBPMATCH module=EBOOT.BIN start=0x0895ca8c end=0x0895cacc symbol=FUN_0895ca8c lang=c99 cc=gcc410-Os */
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

extern int * DAT_08befcac;

void FUN_0895ca8c(void)
{
  if (DAT_08befcac != (int *)0x0) {
    (**(code **)(*DAT_08befcac + 4))(DAT_08befcac);
  }
  DAT_08befcac = (int *)0x0;
  return;
}
