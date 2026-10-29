/* LBPMATCH module=EBOOT.BIN start=0x08a443c4 end=0x08a44444 symbol=FUN_08a443c4 lang=c99 cc=gcc404xs-O2 */
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

extern int FUN_08a44368();
extern void FUN_08a49e54();

void FUN_08a443c4(int param_1,int param_2)
{
  int *piVar1;
  int *piVar2;

  if (*(int *)(param_1 + 0x14) == param_2) {
    FUN_08a49e54((int *)param_2);
    piVar1 = *(int **)(param_1 + 0x28);
  }
  else {
    piVar1 = *(int **)(param_1 + 0x28);
  }
  piVar2 = *(int **)(param_1 + 0x24);
  while( true ) {
    if (piVar1 == piVar2) {
      return;
    }
    if (*piVar2 == param_2) break;
    piVar2 = piVar2 + 1;
  }
  FUN_08a44368(param_1 + 0x24,(int)piVar2);
  return;
}
// NEAR 3 words: gcc404xs-O2 matches the layout; remaining: 'lw v1,40(a0)' vs retail 'lw v1,40(s1)' in the non-call path and the operand order of two compares (bne a1,v1 / bnel s0,v0). Tried: operand swaps, single load after the if, loading piVar2 first.
// near miss from lane lbp3b (unreviewed)
