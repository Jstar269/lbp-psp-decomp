/* LBPMATCH module=EBOOT.BIN start=0x088cd05c end=0x088cd084 symbol=FUN_088cd05c lang=c99 */
/* Ghidra pseudocode (lbpgen.py tag g14) corrected by hand (lane lbp4c, Claude Sonnet 5.5): parameter and field typed unsigned short (andi/lhu instead of seh/lh); exact match verified; names and types await human review. */
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


void FUN_088cd05c(int param_1,unsigned short param_2)
{
  if (*(unsigned short *)(param_1 + 0x3a) != param_2) {
    *(unsigned short *)(param_1 + 0x3a) = param_2;
    *(uint *)(param_1 + 0x40) = *(uint *)(param_1 + 0x40) | 6;
  }
}
