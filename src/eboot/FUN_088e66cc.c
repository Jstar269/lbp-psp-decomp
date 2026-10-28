/* LBPMATCH module=EBOOT.BIN start=0x088e66cc end=0x088e66e8 symbol=FUN_088e66cc lang=c99 cc=gcc410-Os */
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

extern void FUN_08881a14();
extern void FUN_08881bf8();

void FUN_088e66cc(int param_1,int param_2)
{
  if (param_2 == 0x17) {
    FUN_08881a14(*(int *)(param_1 + 0x40));
    return;
  }
  FUN_08881bf8(*(int *)(param_1 + 0x40),param_2);
  return;
}
