/* LBPMATCH module=EBOOT.BIN start=0x0897a550 end=0x0897a57c symbol=FUN_0897a550 lang=c99 */
/* Ghidra pseudocode (lbpgen.py tag g14) corrected by hand (lane lbp4c, Claude Sonnet 5.5): comparison written as fVar1 <= 0.0f so the clear/call is in the taken arm (c.le.s + bc1f); exact match verified; names and types await human review. */
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

extern void FUN_0897a4a4();

void FUN_0897a550(float param_1,int param_2)
{
  float fVar1;

  fVar1 = *(float *)(param_2 + 0x18) - param_1;
  *(float *)(param_2 + 0x18) = fVar1;
  if (fVar1 <= 0.0f) {
    *(undefined1 *)(param_2 + 0x14) = 0;
    FUN_0897a4a4(param_2);
  }
}
