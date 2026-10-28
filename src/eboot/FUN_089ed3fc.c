/* LBPMATCH module=EBOOT.BIN start=0x089ed3fc end=0x089ed42c symbol=FUN_089ed3fc lang=c99 cc=gcc410-Os */
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

extern void FUN_0897bf9c();
extern undefined4 * FUN_0897c1a4();
extern void FUN_089f62bc();
extern undefined4 * FUN_089f683c();

void FUN_089ed3fc(void)
{
  undefined4 *puVar1;
  int *piVar2;
  
  puVar1 = FUN_089f683c();
  FUN_089f62bc(puVar1);
  piVar2 = FUN_0897c1a4();
  FUN_0897bf9c(piVar2);
  return;
}
