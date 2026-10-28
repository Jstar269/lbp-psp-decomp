/* LBPMATCH module=EBOOT.BIN start=0x0881059c end=0x088105d0 symbol=FUN_0881059c lang=c99 cc=gcc410-Os */
/* Mechanical translation of Ghidra pseudocode (lbpgen.py tag g1); exact match verified; names and types await human review. */
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

extern void FUN_08810554();

void FUN_0881059c(int param_1)
{
  FUN_08810554(*(int *)(param_1 + 0xc));
  *(undefined1 *)(*(int *)(param_1 + 0xc) + 0xfc) = 1;
  return;
}
