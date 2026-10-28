/* LBPMATCH module=EBOOT.BIN start=0x08a3bf90 end=0x08a3bfc8 symbol=FUN_08a3bf90 lang=c99 cc=gcc171-Os */
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

extern undefined4 DAT_08be85f8;
extern void FUN_08968924();

void FUN_08a3bf90(int param_1)
{
  FUN_08968924(DAT_08be85f8,0x14);
  *(undefined1 *)(param_1 + 0x2b4) = 1;
  return;
}
