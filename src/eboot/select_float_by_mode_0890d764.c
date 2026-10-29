/* LBPMATCH module=EBOOT.BIN start=0x0890d764 end=0x0890d7a0 symbol=FUN_0890d764 lang=c99 */
/* Ghidra pseudocode (lbpgen.py tag g14) corrected by hand (lane lbp4c, Claude Sonnet 5.5): returns float (lwc1) and the two arms swapped: flag nonzero selects param_1[2]; exact match verified; names and types await human review. */
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

extern unsigned char * DAT_08bf7304;
extern undefined4 FUN_08a50fbc();

float FUN_0890d764(float *param_1)
{
  FUN_08a50fbc();
  if (DAT_08bf7304[0x6b1] != 0) {
    return param_1[2];
  }
  return param_1[1];
}
