/* LBPMATCH module=EBOOT.BIN start=0x08882724 end=0x08882758 symbol=FUN_08882724 lang=c99 cc=gcc171-Os */
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

extern undefined4 DAT_08bee028;
extern void FUN_08887c4c();

void FUN_08882724(void)
{
  int local_20 [4];
  
  local_20[0] = 2;
  local_20[1] = 0x1a2;
  FUN_08887c4c(DAT_08bee028,local_20);
  return;
}
