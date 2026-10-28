/* LBPMATCH module=EBOOT.BIN start=0x08906124 end=0x089061bc symbol=FUN_08906124 lang=c99  cc=gcc404xs-Os */
/* Ghidra pseudocode (lbpgen.py tag g14) corrected by hand (lane lbp2c, DeepSeek through Freebuff): the tail loop walks a separate pointer from the base (the translation incremented the parameter itself, which put the counter in v0 and the base in s0), and its store is the 101st word of the base; exact match verified; names and types await human review. */
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

extern void FUN_089056d4();
extern void FUN_08908434();
extern void FUN_08a9c014();

void FUN_08906124(int param_1)
{
  int iVar1;
  int iVar2;
  int *p;
  
  iVar2 = 0xc;
  iVar1 = param_1;
  do {
    iVar2 = iVar2 + -1;
    FUN_089056d4(iVar1);
    iVar1 = iVar1 + 0x1c;
  } while (iVar2 != 0);
  FUN_08908434((undefined4 *)(param_1 + 0x150));
  FUN_08a9c014((int *)(param_1 + 0x158));
  FUN_08a9c014((int *)(param_1 + 0x170));
  *(undefined4 *)(param_1 + 0x188) = 0;
  *(undefined4 *)(param_1 + 0x18c) = 0;
  *(undefined4 *)(param_1 + 400) = 0;
  *(undefined4 *)(param_1 + 0x1dc) = 0;
  *(undefined1 *)(param_1 + 0x1e0) = 0;
  p = (int *)param_1;
  iVar1 = 0;
  do {
    iVar1 = iVar1 + 1;
    p[0x65] = -1;
    p = p + 1;
  } while (iVar1 != 0x12);
  return;
}
