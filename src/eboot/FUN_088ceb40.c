/* LBPMATCH module=EBOOT.BIN start=0x088ceb40 end=0x088ceb6c symbol=FUN_088ceb40 lang=c99 cc=gcc402x-Os */
/* Mechanical translation of Ghidra pseudocode (lbpgen.py tag g6); exact match verified; names and types await human review. */
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

extern undefined4 DAT_08beee0c;
extern void FUN_088e68a0();
extern void FUN_089757c0();

void FUN_088ceb40(void)
{
  FUN_088e68a0(DAT_08beee0c,'\x01',0x2a);
  FUN_089757c0(0x2d);
  return;
}
