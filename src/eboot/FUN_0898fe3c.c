/* LBPMATCH module=EBOOT.BIN start=0x0898fe3c end=0x0898fe74 symbol=FUN_0898fe3c lang=c99 */
/* Ghidra pseudocode (lbpgen.py tag gen) corrected by hand (lane lbp3d, Claude Sonnet 5.5): stores written in ascending field order (0x40 last); exact match verified; names and types await human review. */
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


void FUN_0898fe3c(undefined4 *param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)
{
  *param_1 = 0xffffffff;
  param_1[1] = param_3;
  param_1[2] = 0;
  param_1[3] = 0;
  param_1[4] = param_2;
  param_1[5] = 0;
  param_1[6] = 0;
  param_1[7] = 0;
  param_1[8] = 0;
  param_1[0xb] = 0;
  param_1[0xc] = 0;
  param_1[0x10] = param_4;
}
