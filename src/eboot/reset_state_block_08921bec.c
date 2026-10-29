/* LBPMATCH module=EBOOT.BIN start=0x08921bec end=0x08921c3c symbol=FUN_08921bec lang=c99 */
/* Ghidra pseudocode (lbpgen.py tag g14) corrected by hand (lane lbp4c, Claude Sonnet 5.5): two independent stores swapped to match retail's scheduled order; exact match verified; names and types await human review. */
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

extern void FUN_08922fe0();
extern uint * FUN_08b9eb88();

void FUN_08921bec(int *param_1)
{
  int iVar1;
  
  FUN_08b9eb88((uint *)(*param_1 + 0xc),0,0x2c4);
  FUN_08922fe0(*param_1);
  iVar1 = *param_1;
  *(undefined4 *)(iVar1 + 0x40) = 1;
  *(undefined4 *)(iVar1 + 0x248) = 0x90;
  return;
}
