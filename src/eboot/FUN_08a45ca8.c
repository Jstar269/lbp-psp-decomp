/* LBPMATCH module=EBOOT.BIN start=0x08a45ca8 end=0x08a45cf8 symbol=FUN_08a45ca8 lang=c99 cc=gcc171-Os */
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

extern uint * DAT_08bf6d90;
extern void FUN_08a9e0cc();

void FUN_08a45ca8(void)
{
  uint *puVar1;
  
  puVar1 = DAT_08bf6d90;
  if (DAT_08bf6d90 != (uint *)0x0) {
    if (*DAT_08bf6d90 != 0) {
      FUN_08a9e0cc(*DAT_08bf6d90);
    }
    FUN_08a9e0cc((uint)puVar1);
  }
  DAT_08bf6d90 = (uint *)0x0;
  return;
}
