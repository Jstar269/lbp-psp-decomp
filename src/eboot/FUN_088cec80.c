/* LBPMATCH module=EBOOT.BIN start=0x088cec80 end=0x088cecac symbol=FUN_088cec80 lang=c99 cc=gcc410-Os */
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

extern void FUN_088cec0c();
extern undefined4 FUN_088d7f9c();
extern void FUN_088f71f0();

void FUN_088cec80(void)
{
  int iVar1;
  
  FUN_088cec0c();
  iVar1 = FUN_088d7f9c();
  FUN_088f71f0(iVar1,'\0');
  return;
}
