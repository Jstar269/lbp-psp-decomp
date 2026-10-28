/* LBPMATCH module=EBOOT.BIN start=0x08aa2ce0 end=0x08aa2d38 symbol=FUN_08aa2ce0 lang=c99 cc=gcc410-Os rodata=0x08bcaee8 */
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
typedef float undefined4;

extern undefined4 DAT_08bf9374;
extern undefined4 DAT_08bf9378;
extern float FUN_08b83fcc(float param_1);
extern float FUN_08b842a8(float param_1);

void FUN_08aa2ce0(int param_1,int param_2)
{
  if ((param_1 == 1) && (param_2 == 0xffff)) {
    DAT_08bf9378 = FUN_08b83fcc(0.57595867f);
    DAT_08bf9374 = FUN_08b842a8(0.57595867f);
  }
  return;
}
