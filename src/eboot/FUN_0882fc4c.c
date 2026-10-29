/* LBPMATCH module=EBOOT.BIN start=0x0882fc4c end=0x0882fc9c symbol=FUN_0882fc4c lang=c99 */
/* Ghidra pseudocode (lbpgen.py tag g3) corrected by hand (lane lbp3b, Claude Sonnet 5.5): grouped the two key words into a struct passed by pointer; exact match verified; names and types await human review. */
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

struct Key { int a; undefined4 b; };
extern int FUN_0882dab8(int, struct Key *);

undefined4 FUN_0882fc4c(int param_1,int param_2,undefined4 param_3)
{
  int iVar1;
  undefined4 uVar2;
  struct Key key;

  key.a = param_2;
  key.b = param_3;
  iVar1 = FUN_0882dab8(param_1,&key);
  *(int *)(param_1 + 0x18) = iVar1;
  uVar2 = 0;
  if (iVar1 != param_1 + 4) {
    uVar2 = **(undefined4 **)(iVar1 + 0x18);
  }
  return uVar2;
}
