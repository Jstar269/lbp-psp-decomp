/* LBPMATCH module=EBOOT.BIN start=0x088413dc end=0x08841428 symbol=FUN_088413dc lang=c99 */
/* Ghidra pseudocode (lbpgen.py tag g14) corrected by hand (lane lbp3b, Claude Sonnet 5.5): swapped the two independent stores; exact match verified; names and types await human review. */
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

extern void FUN_08908628();
extern void FUN_08a9e0cc();

void FUN_088413dc(undefined4 *param_1)
{
  uint uVar1;
  
  uVar1 = param_1[7];
  if (uVar1 != 0) {
    FUN_08908628(uVar1);
    FUN_08a9e0cc(uVar1);
  }
  param_1[7] = 0;
  *param_1 = 0;
  return;
}
