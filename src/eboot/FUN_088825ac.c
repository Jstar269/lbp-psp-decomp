/* LBPMATCH module=EBOOT.BIN start=0x088825ac end=0x088825ec symbol=FUN_088825ac lang=c99 cc=gcc171-Os */
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

extern undefined4 DAT_08bedfac;
extern undefined4 DAT_08bee030;
extern void FUN_0888acc0();

void FUN_088825ac(void)
{
  if (DAT_08bedfac == 0) {
    FUN_0888acc0(DAT_08bee030,1);
    DAT_08bedfac = 1;
  }
  return;
}
