/* LBPMATCH module=EBOOT.BIN start=0x088231a0 end=0x088231bc symbol=FUN_088231a0 lang=c99 cc=gcc410-Os rodata=0x08bac170 */
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


float FUN_088231a0(int param_1)
{
  return (float)*(int *)(*(int *)(param_1 + 0xc) + 8) / 1100.0f;
}
