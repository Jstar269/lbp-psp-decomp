/* LBPMATCH module=EBOOT.BIN start=0x08a2d110 end=0x08a2d13c symbol=FUN_08a2d110 lang=c99 cc=gcc171-Os */
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

extern undefined4 DAT_08bee648;
extern undefined DAT_08bf6a70;

bool FUN_08a2d110(int param_1)
{
  bool bVar1;
  
  bVar1 = false;
  if (DAT_08bee648 != 0) {
    bVar1 = (&DAT_08bf6a70)[param_1] != '\0';
  }
  return bVar1;
}
