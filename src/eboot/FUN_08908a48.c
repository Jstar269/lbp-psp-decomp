/* LBPMATCH module=EBOOT.BIN start=0x08908a48 end=0x08908a98 symbol=FUN_08908a48 lang=c99 */
/* Ghidra pseudocode (lbpgen.py tag g14) corrected by hand (lane lbp3b, Claude Sonnet 5.5): swapped the final two stores; exact match verified; names and types await human review. */
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

extern void FUN_08921858();
extern void FUN_08a9c6b0();

void FUN_08908a48(undefined4 *param_1)
{
  FUN_08921858((int)(param_1 + 0x10));
  FUN_08921858((int)(param_1 + 0x17));
  FUN_08a9c6b0(param_1 + 4,1);
  FUN_08a9c6b0(param_1 + 10,1);
  param_1[0x1e] = 0;
  *param_1 = 0;
  return;
}
