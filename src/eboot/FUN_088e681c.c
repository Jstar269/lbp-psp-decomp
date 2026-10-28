/* LBPMATCH module=EBOOT.BIN start=0x088e681c end=0x088e6838 symbol=FUN_088e681c lang=c99 cc=gcc410-Os */
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

extern undefined * DAT_08beee0c;

void FUN_088e681c(int param_1)
{
  if (param_1 == 1) {
    *(undefined1 *)(DAT_08beee0c + 0x2b4) = 1;
  }
  return;
}
