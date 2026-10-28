/* LBPMATCH module=EBOOT.BIN start=0x0889bc0c end=0x0889bc3c symbol=FUN_0889bc0c lang=c99 cc=gcc410-Os */
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

extern void FUN_0889cf44();
extern undefined4 * FUN_0889d194();

void FUN_0889bc0c(int *param_1)
{
  undefined4 *puVar1;
  
  (**(code **)(*param_1 + 0xc))();
  puVar1 = FUN_0889d194();
  FUN_0889cf44(puVar1);
  return;
}
