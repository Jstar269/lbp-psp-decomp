/* LBPMATCH module=EBOOT.BIN start=0x08a4432c end=0x08a44368 symbol=FUN_08a4432c lang=c99 cc=gcc402x-O2 */
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

extern int FUN_08a442d0();

void FUN_08a4432c(int param_1,int param_2)
{
  int *piVar1;
  
  piVar1 = *(int **)(param_1 + 0x18);
  while( true ) {
    if (piVar1 == *(int **)(param_1 + 0x1c)) {
      return;
    }
    if (param_2 == *piVar1) break;
    piVar1 = piVar1 + 1;
  }
  FUN_08a442d0(param_1 + 0x18,(int)piVar1);
  return;
}

// residual: retail `beq a2,v1` vs ours `beq v1,a2`; same registers, commutative operand order of the branch.
// tried: both source orders of the comparison, if/while forms. conclusion: GCC canonicalises it; parked (1 word).
// near miss from lane lbp2b (unreviewed)
