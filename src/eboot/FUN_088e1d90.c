/* LBPMATCH module=EBOOT.BIN start=0x088e1d90 end=0x088e1dc4 symbol=FUN_088e1d90 lang=c99 cc=gcc171-Os */
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


undefined4 FUN_088e1d90(int *param_1)
{
  undefined4 uVar1;
  
  uVar1 = 0;
  if ((*param_1 - 6U < 2) || (param_1[0xe] - 6U < 2)) {
    uVar1 = 1;
  }
  return uVar1;
}
