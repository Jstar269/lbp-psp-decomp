/* LBPMATCH module=EBOOT.BIN start=0x08878d74 end=0x08878dbc symbol=FUN_08878d74 lang=c99 */
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

extern void FUN_08882614();
extern undefined4 FUN_08891788();

void FUN_08878d74(int param_1)
{
  *(undefined1 *)(param_1 + 0x15) = 0;
  if (*(int *)(param_1 + 0xc4) != 3) {
    FUN_08882614(1,*(int *)(param_1 + 0xc4));
  }
  FUN_08891788(param_1 + 0xc);
  return;
}
// 8 words differ: retail calls 0x08891788 with jal and returns normally (no tail call, sb zero,21(s0) before li a0,1); ours emits the call as a sibling call 'j' (at -Os, -O2, -O3 alike).
// tried: gcc404xs-O1/O2/O3/O0, callee returning a value, void caller: sibcall stays unless -O1 (which changes other things)
// near miss from lane lbp3c (unreviewed)
