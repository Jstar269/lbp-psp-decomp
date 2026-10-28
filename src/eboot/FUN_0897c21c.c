/* LBPMATCH module=EBOOT.BIN start=0x0897c21c end=0x0897c23c symbol=FUN_0897c21c lang=c99 cc=gcc410-Os */
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

extern void FUN_0897c074();
extern undefined4 * FUN_0897c1a4();

void FUN_0897c21c(void)
{
  int *piVar1;
  
  piVar1 = FUN_0897c1a4();
  FUN_0897c074(piVar1);
  return;
}
