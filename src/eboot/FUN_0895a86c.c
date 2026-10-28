/* LBPMATCH module=EBOOT.BIN start=0x0895a86c end=0x0895a8c4 symbol=FUN_0895a86c lang=c99 cc=gcc410-Os */
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

extern undefined4 DAT_08befad0;
extern undefined * DAT_08befba0;
extern void FUN_08a9e0cc();

void FUN_0895a86c(void)
{
  uint *puVar1;
  
  DAT_08befad0 = 0;
  if ((DAT_08befba0 != 0) && (*(int *)(DAT_08befba0 + -8) == 0x11223344)) {
    puVar1 = (uint *)(DAT_08befba0 + -4);
    *(undefined4 *)(DAT_08befba0 + -8) = 0x55667788;
    FUN_08a9e0cc(*puVar1);
  }
  DAT_08befba0 = 0;
  return;
}
