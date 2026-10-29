/* LBPMATCH module=EBOOT.BIN start=0x08812274 end=0x0881232c symbol=FUN_08812274 lang=c99 */
/* Ghidra pseudocode (lbpgen.py tag g14) corrected by hand (lane lbp7b, Codex GPT-6): typed fields, simplified state transition, and corrected call arguments; exact match verified; names and types await human review. */
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

extern void FUN_0880504c();
extern void FUN_08805080();
extern void FUN_088121cc();
extern void FUN_08a73710();

typedef struct Obj { int vtable; int pad1[46]; unsigned int *sub; int pad2[44]; int mode; } Obj;
void FUN_08812274(Obj *param_1,int param_2)
{
  int iVar1; int is3 = param_2 == 3;
  
  if (param_1->mode != 3 && is3)
    param_1->sub[3] = param_1->sub[2];
  param_1->mode = param_2;
  if (is3) {
    iVar1 = (**(code **)(param_1->vtable + 0x5c))(param_1);
    FUN_0880504c(iVar1,0x200);
  }
  else {
    iVar1 = (**(code **)(param_1->vtable + 0x5c))(param_1);
    FUN_08805080(iVar1,0x200);
    **(uint **)(iVar1 + 0x40) = **(uint **)(iVar1 + 0x40) & 0xfffffdff;
  }
  FUN_088121cc(param_1);
  FUN_08a73710(param_1);
  return;
}






