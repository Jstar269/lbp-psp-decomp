/* LBPMATCH module=EBOOT.BIN start=0x08a54968 end=0x08a549cc symbol=FUN_08a54968 lang=c99 cc=gcc402x-Os */
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

extern uint DAT_08bf6e74;
extern void FUN_08a3b76c();
extern void FUN_08a45ca8();
extern void FUN_08a53a48();
extern void FUN_08a5490c();
extern void FUN_08a68ff4();
extern void FUN_08a81160();
extern void FUN_08a9e0cc();

void FUN_08a54968(void)
{
  uint uVar1;
  
  FUN_08a5490c(DAT_08bf6e74);
  uVar1 = DAT_08bf6e74;
  if (DAT_08bf6e74 != 0) {
    FUN_08a53a48(DAT_08bf6e74);
    FUN_08a9e0cc(uVar1);
  }
  DAT_08bf6e74 = 0;
  FUN_08a68ff4();
  FUN_08a45ca8();
  FUN_08a81160();
  FUN_08a3b76c();
  return;
}
