/* LBPMATCH module=EBOOT.BIN start=0x08916d28 end=0x08916d40 symbol=FUN_08916d28 lang=c99 cc=gcc410-Os */
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

extern undefined4 DAT_08bef4b0;
extern int FUN_089162d8();

void FUN_08916d28(int *param_1,int param_2)
{
  FUN_089162d8(DAT_08bef4b0,param_1,param_2);
  return;
}
