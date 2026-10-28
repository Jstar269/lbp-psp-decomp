/* LBPMATCH module=EBOOT.BIN start=0x088fd784 end=0x088fd7dc symbol=FUN_088fd784 lang=c99 cc=gcc410-Os */
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

extern undefined * DAT_08bf7304;
extern void FUN_08910574();
extern void FUN_08910774();
extern undefined4 FUN_08a50fbc();

void FUN_088fd784(int param_1)
{
  FUN_08910774();
  if (*(uchar *)(param_1 + 0x18) != '\0') {
    *(undefined4 *)(param_1 + 0x1c) = 4;
    FUN_08a50fbc();
    FUN_08910574(DAT_08bf7304 + 0x87c,1);
    return;
  }
  return;
}
