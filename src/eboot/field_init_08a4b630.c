/* LBPMATCH module=EBOOT.BIN start=0x08a4b630 end=0x08a4b684 symbol=FUN_08a4b630 lang=c99 */
/* Ghidra pseudocode (lbpgen.py tag g14) corrected by hand (lane lbp4a, Claude Sonnet 5.5): reordered the three trailing zero stores; exact match verified; names and types await human review. */
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

extern void FUN_08921788();

void FUN_08a4b630(int param_1)
{
  *(undefined4 *)(param_1 + 0x1e0) = 0xffffffff;
  *(undefined4 *)(param_1 + 0x1e4) = 0;
  *(undefined1 *)(param_1 + 0x1e8) = 0;
  *(undefined4 *)(param_1 + 0x1ec) = 0;
  *(undefined4 *)(param_1 + 0x1f0) = 0;
  FUN_08921788((undefined4 *)(param_1 + 500));
  *(undefined1 *)(param_1 + 0x21c) = 1;
  *(undefined4 *)(param_1 + 0x214) = 0;
  *(undefined4 *)(param_1 + 0x218) = 0;
  *(undefined4 *)(param_1 + 0x210) = 0;
  return;
}
