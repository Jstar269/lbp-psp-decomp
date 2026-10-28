/* LBPMATCH module=EBOOT.BIN start=0x08a4d7dc end=0x08a4d804 symbol=FUN_08a4d7dc lang=c99 cc=gcc410-Os */
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

extern void FUN_08a6b5c4();
extern void FUN_08a718dc();

void FUN_08a4d7dc(int *param_1)
{
  FUN_08a6b5c4(param_1);
  FUN_08a718dc(param_1);
  return;
}
