/* LBPMATCH module=EBOOT.BIN start=0x08aa0568 end=0x08aa05b8 symbol=FUN_08aa0568 lang=c99 cc=gcc410-Os rodata=0x08bcad70 */
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

extern undefined DAT_08bf9338;
extern void FUN_08a9bff8();
extern void FUN_08a9c164();

void FUN_08aa0568(int param_1,int param_2)
{
  if (param_1 == 1) {
    if (param_2 == 0xffff) {
      FUN_08a9c164((int *)&DAT_08bf9338,(uint *)"PSPPad");
      return;
    }
  }
  else if ((param_1 == 0) && (param_2 == 0xffff)) {
    FUN_08a9bff8((int)&DAT_08bf9338);
    return;
  }
  return;
}
