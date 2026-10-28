/* LBPMATCH module=EBOOT.BIN start=0x08b8b364 end=0x08b8b37c symbol=FUN_08b8b364 lang=c99 cc=gcc410-Os */
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

extern int * FUN_08b8b160();

void FUN_08b8b364(int *param_1,int param_2,uint param_3,char param_4)
{
  FUN_08b8b160(param_1,param_2 - *param_1,0,param_3,param_4);
  return;
}
