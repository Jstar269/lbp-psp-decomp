/* LBPMATCH module=EBOOT.BIN start=0x08910ca8 end=0x08910cd4 symbol=FUN_08910ca8 lang=c99 */
/* Hand-written reconstruction (external matching lane); exact match verified; names and types await human review. */
/* Ghidra pseudocode (lbpgen.py candidate) corrected by hand (lane lbp4b, Claude Sonnet 5.5): store order changed; exact match verified; names and types await human review. */
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

extern void FUN_0891076c();

void FUN_08910ca8(int param_1)
{
  FUN_0891076c();
  *(undefined4 *)(param_1 + 0x90) = 0;
  *(undefined1 *)(param_1 + 0x74) = 0;
  return;
}
