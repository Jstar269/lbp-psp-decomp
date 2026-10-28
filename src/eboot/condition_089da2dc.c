/* LBPMATCH module=EBOOT.BIN start=0x089da2dc end=0x089da398 symbol=FUN_089da2dc lang=c99 */
/* Ghidra pseudocode (lbpgen.py tag g14) corrected by hand (lane lbp1c, Codex GPT-6): restored indirect-call argument and branch structure; exact match verified; names and types await human review. */
typedef unsigned char undefined;
typedef unsigned char byte;
typedef unsigned short ushort;
typedef unsigned int uint;
typedef unsigned long long ulonglong;
typedef long long longlong;
typedef unsigned char uchar;
typedef unsigned char bool;
typedef unsigned long long undefined8;
typedef int code(void *);
#define true 1
#define false 0
#define ABS(x) ((x) < 0 ? -(x) : (x))
typedef unsigned char undefined1;
typedef unsigned short undefined2;
typedef unsigned int undefined4;

extern void FUN_089da244();

undefined4 FUN_089da2dc(int param_1,int param_2)
{
  int iVar1;
  uint uVar2;
  
  if (*(int *)(param_1 + 0x20) == param_1 + 0x18) {
    return 1;
  }
  iVar1 = (**(code **)(**(int **)(*(int *)(param_1 + 0x20) + 8) + 0xc))(*(void **)(*(int *)(param_1 + 0x20) + 8));
  if (iVar1 == 0) {
    return 0;
  }
  uVar2 = *(uint *)(param_2 + 4);
  if (uVar2 & 0x200) {
    FUN_089da244(param_1, 0);
    return 0;
  }
  if (uVar2 & 0x400) {
    FUN_089da244(param_1, 1);
    return 0;
  }
  if (*(float *)(param_2 + 0x14) > *(float *)(param_2 + 0x1c)) return 1;
  if (uVar2 & 4) {
    FUN_089da244(param_1, 0);
    return 0;
  }
  if (uVar2 & 2) {
    FUN_089da244(param_1, 1);
    return 0;
  }
  return 1;
}


