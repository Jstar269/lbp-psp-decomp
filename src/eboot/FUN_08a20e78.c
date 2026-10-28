/* LBPMATCH module=EBOOT.BIN start=0x08a20e78 end=0x08a20ec0 symbol=FUN_08a20e78 lang=c99 cc=gcc410-Os */
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

extern int * DAT_08bf5df8;
extern void FUN_08a20de8();
extern void FUN_08a9e0cc();

void FUN_08a20e78(void)
{
  int *piVar1;
  
  piVar1 = DAT_08bf5df8;
  if (DAT_08bf5df8 != (int *)0x0) {
    FUN_08a20de8(DAT_08bf5df8);
    FUN_08a9e0cc((uint)piVar1);
  }
  DAT_08bf5df8 = (int *)0x0;
  return;
}
