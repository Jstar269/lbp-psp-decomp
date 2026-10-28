/* LBPMATCH module=EBOOT.BIN start=0x08887b8c end=0x08887bc0 symbol=FUN_08887b8c lang=c99 cc=gcc410-Os */
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

extern undefined4 DAT_08bedd84;
extern int FUN_0888f6a8();

void FUN_08887b8c(undefined4 *param_1)
{
  DAT_08bedd84 = param_1;
  FUN_0888f6a8(param_1 + 1);
  *param_1 = 0;
  return;
}
