/* LBPMATCH module=EBOOT.BIN start=0x08823170 end=0x088231a0 symbol=FUN_08823170 lang=c99 cc=gcc410-Os rodata=0x08bac16c */
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

extern undefined4 FUN_08a50fbc();

float FUN_08823170(void)
{
  int iVar1;
  
  iVar1 = FUN_08a50fbc();
  return (float)*(int *)(iVar1 + 0x14) / 2047.0f;
}
