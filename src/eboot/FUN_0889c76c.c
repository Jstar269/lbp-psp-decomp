/* LBPMATCH module=EBOOT.BIN start=0x0889c76c end=0x0889c79c symbol=FUN_0889c76c lang=c99 cc=gcc402x-Os */
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

extern undefined4 * FUN_0889a3bc();
extern void FUN_08af0ed4();

void FUN_0889c76c(void)
{
  int *piVar1;
  
  piVar1 = FUN_0889a3bc();
  (**(code **)(*piVar1 + 0x18))(piVar1);
  FUN_08af0ed4();
  return;
}
