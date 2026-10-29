/* LBPMATCH module=EBOOT.BIN start=0x08839be8 end=0x08839cf0 symbol=FUN_08839be8 lang=c99 */
/* Ghidra pseudocode (lbpgen.py tag g14) corrected by hand (lane lbp3b, Claude Sonnet 5.5): virtual calls pass the object as first argument; exact match verified; names and types await human review. */
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

extern void FUN_08921858();
extern void FUN_0894a8d8();
extern void FUN_08956130();
extern void FUN_0895945c();
extern undefined4 * FUN_0895a96c();
extern void FUN_08a9e0cc();

void FUN_08839be8(int param_1,int param_2)
{
  undefined4 *puVar1;
  int *piVar2;
  uint uVar3;
  
  FUN_08921858(param_2);
  FUN_08921858(param_2 + 0x1c);
  FUN_08921858(param_2 + 0x38);
  *(undefined4 *)(param_2 + 0x68) = 0;
  if (*(int *)(param_2 + 0x74) != 0) {
    puVar1 = FUN_0895a96c();
    FUN_0895945c(puVar1[0x15],*(undefined4 *)(param_2 + 0x74));
    *(undefined4 *)(param_2 + 0x74) = 0;
  }
  if (*(int **)(param_1 + 0x90) != (int *)0x0) {
    (**(void (**)(int *))(**(int **)(param_1 + 0x90) + 4))(*(int **)(param_1 + 0x90));
    *(undefined4 *)(param_1 + 0x90) = 0;
  }
  uVar3 = *(uint *)(param_1 + 0x9c);
  if (uVar3 != 0) {
    FUN_0894a8d8(uVar3);
    FUN_08a9e0cc(uVar3);
    *(undefined4 *)(param_1 + 0x9c) = 0;
  }
  puVar1 = *(undefined4 **)(param_1 + 0x94);
  if (puVar1 != (undefined4 *)0x0) {
    FUN_08956130(puVar1);
    FUN_08a9e0cc((uint)puVar1);
    *(undefined4 *)(param_1 + 0x94) = 0;
  }
  piVar2 = *(int **)(param_1 + 0x98);
  if (piVar2 != (int *)0x0) {
    (**(void (**)(int *))(*piVar2 + 4))(piVar2);
    *(undefined4 *)(param_1 + 0x98) = 0;
  }
  uVar3 = *(uint *)(param_1 + 0xa0);
  if (uVar3 != 0) {
    FUN_0894a8d8(uVar3);
    FUN_08a9e0cc(uVar3);
    *(undefined4 *)(param_1 + 0xa0) = 0;
  }
  return;
}
