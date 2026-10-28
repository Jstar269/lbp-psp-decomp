/* LBPMATCH module=EBOOT.BIN start=0x08886c2c end=0x08886c6c symbol=FUN_08886c2c lang=c99 cc=gcc410-Os */
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

extern void FUN_08886b74();
extern void FUN_0888b8c4();
extern void FUN_0888b8cc();

void FUN_08886c2c(int param_1)
{
  FUN_0888b8c4(param_1 + 0x30);
  FUN_08886b74(param_1);
  FUN_0888b8cc(param_1 + 0x30);
  return;
}
