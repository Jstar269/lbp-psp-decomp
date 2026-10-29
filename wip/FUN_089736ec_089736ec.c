/* LBPMATCH module=EBOOT.BIN start=0x089736ec end=0x08973714 symbol=FUN_089736ec lang=c99 cc=gcc404xs-O2 */
/* Ghidra pseudocode (lbpgen.py tag gen) corrected by hand (lane lbp3b, Claude Sonnet 5.5): see trailing notes; NOT exact. */
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


void FUN_089736ec(int param_1)
{
  (**(code **)(**(int **)(param_1 + 0x18) + 0xc))();
  return;
}
// NEAR 10 words: retail has a frame and calls the virtual (jalr v0, nop) instead of the tail jump (lw t9 / jr t9) ours emits: same sibcall evidence as 0x08a34688. Only the sibcall decision differs.
// near miss from lane lbp3b (unreviewed)
