/* LBPMATCH module=EBOOT.BIN start=0x0882dca4 end=0x0882dd9c symbol=FUN_0882dca4 lang=c99 */
/* Ghidra pseudocode (lbpgen.py tag g14) corrected by hand (lane lbp1c, Codex GPT-6): reconstructed pair comparison and structure copy; exact match verified; names and types await human review. */
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

extern undefined4 DAT_08be84a0;
extern undefined4 FUN_08adbb84();
extern void FUN_08b899e4();

typedef struct { int a,b,c,d; } Four;
int FUN_0882dca4(int param_1,int param_2,int param_3,int *param_4)
{
  int *piVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  char cVar5;
  
  cVar5 = 1;
  if (param_2 == 0 && param_3 != param_1 + 4) {
    Four *key = (Four *)(param_3 + 16);
    Four *value = (Four *)param_4;
    if (value->a >= key->a) {
      if (key->a < value->a || !(value->b < key->b)) cVar5 = 0;
    }
  }
  piVar1 = (int *)FUN_08adbb84(DAT_08be84a0,0x20);
  { Four *out = (Four *)(piVar1 + 4);
    if (out) *out = *(Four *)param_4;
  }
  FUN_08b899e4(cVar5,piVar1,param_3,param_1 + 4);
  *(int *)(param_1 + 0x14) = *(int *)(param_1 + 0x14) + 1;
  return (int)piVar1;
}


