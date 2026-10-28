/* LBPMATCH module=EBOOT.BIN start=0x08991e50 end=0x08991e8c symbol=FUN_08991e50 lang=c99 cc=gcc410-Os */
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

extern undefined4 DAT_08be8510;
extern undefined * DAT_08bf03b8;
extern void FUN_0880b148();
extern void FUN_08974360();

void FUN_08991e50(void)
{
  FUN_08974360();
  FUN_0880b148(DAT_08be8510,0);
  *(undefined1 *)(DAT_08bf03b8 + 0x8c) = 1;
  return;
}
