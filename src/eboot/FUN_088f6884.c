/* LBPMATCH module=EBOOT.BIN start=0x088f6884 end=0x088f68d8 symbol=FUN_088f6884 lang=c99 cc=gcc402x-Os */
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
extern void FUN_088b2a30();
extern void FUN_0896ee90();

void FUN_088f6884(int param_1)
{
  if ((*(uchar *)(param_1 + 0x20) != '\0') || (**(int **)(param_1 + 0x18) == 1)) {
    FUN_0896ee90(DAT_08bf03b8,1,0);
  }
  FUN_088b2a30(param_1);
  return;
}
