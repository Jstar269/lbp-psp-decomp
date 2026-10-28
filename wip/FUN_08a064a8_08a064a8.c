/* LBPMATCH module=EBOOT.BIN start=0x08a064a8 end=0x08a064e4 symbol=FUN_08a064a8 lang=c99 cc=gcc402x-O2 */
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

extern int FUN_08a0644c();

void FUN_08a064a8(int param_1,int param_2)
{
  int *piVar1;
  
  piVar1 = *(int **)(param_1 + 0xa0);
  while( true ) {
    if (piVar1 == *(int **)(param_1 + 0xa4)) {
      return;
    }
    if (param_2 == *piVar1) break;
    piVar1 = piVar1 + 1;
  }
  FUN_08a0644c(param_1 + 0xa0,(int)piVar1);
  return;
}

// residual: 1 word - retail `bnel v0,a1` (loaded *p first) vs ours `bnel a1,v0`; registers are otherwise identical.
// tried: == and != with both operand orders, call moved inside the hit arm, while/for/do forms, continue vs break.
// conclusion: GCC canonicalises the operands of the commutative branch (both registers already correct, so this is
//   not a colour tie) - no source spelling reaches the encoding, parked.
// near miss from lane lbp2b (unreviewed)
