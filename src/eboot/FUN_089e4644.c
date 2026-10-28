/* LBPMATCH module=EBOOT.BIN start=0x089e4644 end=0x089e4698 symbol=FUN_089e4644 lang=c99 cc=gcc171-Os */
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

extern undefined DAT_08bdbd28;
extern void FUN_089e2b68();
extern void FUN_089e45c0();

void FUN_089e4644(int *param_1)
{
  if (DAT_08bdbd28 == '\0') {
    FUN_089e45c0((int)param_1);
    FUN_089e2b68(param_1,0,0x80);
    DAT_08bdbd28 = '\x01';
  }
  return;
}
