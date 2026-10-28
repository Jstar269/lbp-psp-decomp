/* LBPMATCH module=EBOOT.BIN start=0x08a6dc08 end=0x08a6dc58 symbol=FUN_08a6dc08 lang=c99 cc=gcc402x-O2 */
/* Mechanical translation of Ghidra pseudocode (lbpgen.py tag g8); exact match verified; names and types await human review. */
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

extern undefined DAT_08bf71f0;
extern undefined DAT_08bf71f8;
extern int FUN_08a6f0e0();

void FUN_08a6dc08(undefined4 param_1)
{
  int iVar1;
  
  iVar1 = FUN_08a6f0e0((int *)&DAT_08bf71f8,param_1);
  if (iVar1 != 0) {
    return;
  }
  FUN_08a6f0e0((int *)&DAT_08bf71f0,param_1);
  return;
}
