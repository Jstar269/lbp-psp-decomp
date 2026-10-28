/* LBPMATCH module=EBOOT.BIN start=0x088e660c end=0x088e6648 symbol=FUN_088e660c lang=c99 cc=gcc171-Os */
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

extern undefined4 DAT_08beed14;
extern void FUN_088d94e0();

void FUN_088e660c(undefined4 param_1,uint *param_2)
{
  if (*param_2 != 0) {
    FUN_088d94e0(DAT_08beed14,*param_2);
    *param_2 = 0;
  }
  return;
}
