/* LBPMATCH module=EBOOT.BIN start=0x089dee88 end=0x089def60 symbol=FUN_089dee88 lang=c99 */
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

extern void FUN_0896aeec();
extern void FUN_0896c1b0();

void FUN_089dee88(int param_1,int param_2)
{
  int *piVar1;
  int *piVar2;
  undefined4 *puVar3;
  
  FUN_0896c1b0(param_2,*(short *)(param_1 + 0xc),*(short *)(param_1 + 0xe));
  (**(code **)(**(int **)(param_1 + 0x34) + 0x38))(*(int **)(param_1 + 0x34),param_2);
  for (puVar3 = *(undefined4 **)(param_1 + 0x18); piVar2 = *(int **)(param_1 + 0x34),
      puVar3 != (undefined4 *)(param_1 + 0x18); puVar3 = (undefined4 *)*puVar3) {
    piVar1 = (int *)puVar3[2];
    if ((piVar1 != (int *)piVar2[3]) && (piVar1 != (int *)piVar2[4])) {
      FUN_0896aeec(piVar1,param_2);
    }
  }
  (**(code **)(*piVar2 + 0x30))(piVar2,param_2);
  (**(code **)(**(int **)(param_1 + 0x34) + 0x34))(*(int **)(param_1 + 0x34),param_2);
  *(undefined1 *)(param_2 + 0x48) = 1;
  *(short *)(param_2 + 0x44) = *(short *)(param_2 + 0x44) + -1;
  return;
}

// Baseline generated candidate; 37 differing words. Tested primary and O2 profiles; control flow and types need reconstruction.
// near miss from lane lbp8f (unreviewed)
