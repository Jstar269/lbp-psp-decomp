/* LBPMATCH module=EBOOT.BIN start=0x089839b8 end=0x089839e0 symbol=FUN_089839b8 lang=c99 cc=gcc410-Os */
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

extern undefined4 DAT_08be85fc;
extern undefined * FUN_08970dbc();
extern int FUN_089836e8();

void FUN_089839b8(int param_1)
{
  short *psVar1;
  
  psVar1 = (short *)FUN_08970dbc(DAT_08be85fc,param_1);
  FUN_089836e8(psVar1);
  return;
}
