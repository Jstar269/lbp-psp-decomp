/* LBPMATCH module=EBOOT.BIN start=0x088cf260 end=0x088cf2a8 symbol=FUN_088cf260 lang=c99 cc=gcc402x-Os */
/* Mechanical translation of Ghidra pseudocode (lbpgen.py tag g6); exact match verified; names and types await human review. */
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

extern undefined4 DAT_08bf03b8;
extern undefined4 FUN_088d7f9c();
extern void FUN_088f71f0();
extern undefined4 FUN_0896f7d0();
extern void FUN_089702b4();

void FUN_088cf260(void)
{
  int iVar1;
  
  iVar1 = FUN_0896f7d0(DAT_08bf03b8);
  if (iVar1 != 0) {
    FUN_089702b4(DAT_08bf03b8,1);
  }
  iVar1 = FUN_088d7f9c();
  FUN_088f71f0(iVar1,'\0');
  return;
}
