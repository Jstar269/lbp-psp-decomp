/* LBPMATCH module=EBOOT.BIN start=0x08a5490c end=0x08a54968 symbol=FUN_08a5490c lang=c99 cc=gcc410-Os */
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

extern undefined4 DAT_08bf6e74;
extern void FUN_08a3b764();
extern void FUN_08a3f2f0();
extern void FUN_08a45bd4();
extern void FUN_08a546bc();
extern void FUN_08a694e4();
extern void FUN_08a81158();
extern void FUN_08a8dbac();

void FUN_08a5490c(int param_1)
{
  FUN_08a546bc(DAT_08bf6e74);
  FUN_08a694e4();
  FUN_08a45bd4();
  FUN_08a81158();
  FUN_08a3b764();
  FUN_08a3f2f0(param_1 + 0xc20);
  FUN_08a8dbac(param_1 + 0xb7c);
  return;
}
