/* LBPMATCH module=EBOOT.BIN start=0x0894a7ec end=0x0894a860 symbol=FUN_0894a7ec lang=c99 */
/* Ghidra pseudocode (lbpgen.py tag gen) corrected by hand (lane lbp3d, Claude Sonnet 5.5): container typed as a begin/end struct at +0xc; sum accumulated before the offset; exact match verified; names and types await human review. */
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


struct V { int **begin; int **end; };
int FUN_0894a7ec(int param_1,int param_2)
{
  struct V *v = (struct V *)(param_1 + 0xc);
  int iVar1;
  int **puVar2;
  int iVar3 = 0;
  for (puVar2 = v->begin; puVar2 != v->end; puVar2 = puVar2 + 1) {
    iVar1 = (**(code **)(*(int *)*puVar2 + 0x10))((int *)*puVar2,param_2);
    iVar3 = iVar3 + iVar1;
    param_2 = param_2 + iVar1;
  }
  return iVar3;
}
