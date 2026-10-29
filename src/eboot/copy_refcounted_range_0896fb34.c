/* LBPMATCH module=EBOOT.BIN start=0x0896fb34 end=0x0896fb74 symbol=FUN_0896fb34 lang=c99 */
/* Ghidra pseudocode (lbpgen.py tag g14) corrected by hand (lane lbp4c, Claude Sonnet 5.5): for loop rewritten as while with source pointer incremented before the destination; exact match verified; names and types await human review. */
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


int * FUN_0896fb34(int *param_1,int *param_2,int *param_3)
{
  int iVar1;

  while (param_1 != param_2) {
    if (param_3 != (int *)0x0) {
      iVar1 = *param_1;
      *param_3 = iVar1;
      if (iVar1 != 0) {
        *(unsigned short *)(iVar1 + 6) = *(unsigned short *)(iVar1 + 6) + 1;
      }
    }
    param_1++;
    param_3++;
  }
  return param_3;
}
