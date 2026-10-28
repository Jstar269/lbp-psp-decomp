/* LBPMATCH module=EBOOT.BIN start=0x089d85e4 end=0x089d8610 symbol=FUN_089d85e4 lang=c99 cc=gcc410-Os */
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

extern void FUN_0896db58();
extern void FUN_0896dbfc();

void FUN_089d85e4(int param_1)
{
  if (*(int *)(param_1 + 0xa4) == 0) {
    FUN_0896db58(param_1 + 0xb4,1,1,0);
    return;
  }
  FUN_0896dbfc(param_1 + 0xb4,1,1,0);
  return;
}
