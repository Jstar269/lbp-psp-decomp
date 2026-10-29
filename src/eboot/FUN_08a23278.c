/* LBPMATCH module=EBOOT.BIN start=0x08a23278 end=0x08a23298 symbol=FUN_08a23278 lang=c99 cc=gcc404xs-O2 */
/* Ghidra pseudocode (lbpgen.py tag gen) corrected by hand (lane lbp3d, Claude Sonnet 5.5): built with cc=gcc404xs-O2 and the flag byte declared as undefined (sb); exact match verified; names and types await human review. */
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

extern undefined4 DAT_08bf5ed4;
extern undefined4 DAT_08bf5ed8;
extern undefined DAT_08bf5edc;

void FUN_08a23278(undefined4 param_1,undefined4 param_2,undefined4 param_3)
{
  DAT_08bf5edc = 1;
  DAT_08bf5ed8 = param_1;
  DAT_08bf5ed4 = param_2;
  return;
}
