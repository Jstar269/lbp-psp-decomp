/* LBPMATCH module=EBOOT.BIN start=0x0897473c end=0x08974824 symbol=FUN_0897473c lang=c99 */
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

extern int * DAT_08be85f8;
extern void FUN_08967568();
extern void FUN_08968924();
extern void FUN_08970b6c();

void FUN_0897473c(int param_1,int *param_2)
{
  int iVar1;
  undefined4 *puVar2;
  int *piVar3;
  
  iVar1 = *param_2;
  if (iVar1 != 0) {
    *(short *)(iVar1 + 6) = *(short *)(iVar1 + 6) + 1;
  }
  puVar2 = *(undefined4 **)(param_1 + 0x20);
  *(int *)(param_1 + 0x20) = iVar1;
  if (puVar2 != (undefined4 *)0x0) {
    FUN_08970b6c(puVar2);
  }
  puVar2 = (undefined4 *)*param_2;
  if (puVar2 != (undefined4 *)0x0) {
    *(short *)((int)puVar2 + 6) = *(short *)((int)puVar2 + 6) + 1;
  }
  piVar3 = *(int **)(param_1 + 0x14);
  if ((piVar3 != (int *)0x0) && ((piVar3[1] & 4U) != 0)) {
    (**(code **)(*piVar3 + 0x20))();
  }
  if (DAT_08be85f8 != (int *)0x0) {
    if (*(int *)(param_1 + 0x10) != 0) {
      FUN_08968924(DAT_08be85f8,*(int *)(param_1 + 0x10));
    }
    FUN_08967568((int)DAT_08be85f8);
  }
  if (puVar2 == (undefined4 *)0x0) {
    return;
  }
  FUN_08970b6c(puVar2);
  return;
}

// NEAR: 14 differing words; primary and O2 profiles tested.
// near miss from lane lbp5b (unreviewed)
