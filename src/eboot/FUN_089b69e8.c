/* LBPMATCH module=EBOOT.BIN start=0x089b69e8 end=0x089b6a58 symbol=FUN_089b69e8 lang=c99 cc=gcc410-Os */
/* Mechanical translation of Ghidra pseudocode (lbpgen.py tag g4); exact match verified; names and types await human review. */
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

extern int * FUN_089ae920();
extern int FUN_089af564();
extern void FUN_089b370c();
extern void FUN_089d9260();

void FUN_089b69e8(int param_1)
{
  int *piVar1;
  int iVar2;
  
  piVar1 = FUN_089ae920('\x01');
  iVar2 = FUN_089af564(0x104,1,1,-1,1,0);
  FUN_089d9260((int)piVar1,iVar2);
  FUN_089b370c(param_1,0x33c,0x353,(int)piVar1,0xa0);
  return;
}
