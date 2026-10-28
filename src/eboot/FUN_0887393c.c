/* LBPMATCH module=EBOOT.BIN start=0x0887393c end=0x0887394c symbol=FUN_0887393c lang=c99 cc=gcc410-Os */
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

extern undefined4 FUN_08af7480();

void FUN_0887393c(int param_1,int *param_2)
{
  FUN_08af7480((uint *)(param_1 + 0x18),(undefined1 *)(*param_2 + 0xc));
  return;
}
