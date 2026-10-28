/* LBPMATCH module=EBOOT.BIN start=0x088b5c24 end=0x088b5c5c symbol=FUN_088b5c24 lang=c99 cc=gcc410-Os */
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

extern undefined4 DAT_08bee4f8;
extern void FUN_0883c3b4();
extern void FUN_08a2d0d0();

void FUN_088b5c24(int param_1)
{
  FUN_0883c3b4(param_1 + 0x2c);
  FUN_0883c3b4(param_1 + 0x14);
  FUN_08a2d0d0(DAT_08bee4f8);
  return;
}
