/* LBPMATCH module=EBOOT.BIN start=0x08918530 end=0x08918550 symbol=FUN_08918530 lang=c99 cc=gcc171-Os */
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

extern uint FUN_08b9fb64();

undefined2 FUN_08918530(void)
{
  uint uVar1;
  
  uVar1 = FUN_08b9fb64();
  return (short)uVar1;
}
