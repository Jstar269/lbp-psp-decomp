/* LBPMATCH module=EBOOT.BIN start=0x0891bf24 end=0x0891bf5c symbol=FUN_0891bf24 lang=c99 cc=gcc171-Os */
/* Mechanical translation of Ghidra pseudocode (lbpgen.py tag g3); exact match verified; names and types await human review. */
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

extern int * FUN_08ac8994();

void FUN_0891bf24(int param_1)
{
  int *piVar1;
  
  piVar1 = FUN_08ac8994(*(int **)(param_1 + 4),0,0,0);
  *(int **)(param_1 + 0xc) = piVar1;
  return;
}
