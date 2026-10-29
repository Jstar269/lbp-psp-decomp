/* LBPMATCH module=EBOOT.BIN start=0x0885c424 end=0x0885c4ec symbol=FUN_0885c424 lang=c99 rodata=0x08baf6a8 */
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

extern void FUN_0885c00c();
extern void FUN_0885c33c();

undefined4 FUN_0885c424(int param_1)
{
  undefined4 uVar1;
  int iVar2;
  undefined4 uVar3;
  
  switch(*(undefined4 *)(param_1 + 200)) {
  case 0:
    (**(code **)(**(int **)(param_1 + 0xcc) + 0xc))();
    uVar1 = 1;
    goto LAB_0885c4b8;
  case 1:
    FUN_0885c00c(param_1);
    uVar3 = 0;
    break;
  case 2:
    iVar2 = *(int *)(*(int *)(param_1 + 0x1a0) + 0x10);
    if (iVar2 == 4) {
      *(undefined4 *)(param_1 + 200) = 4;
      return 0;
    }
    if (iVar2 != 6) {
      return 0;
    }
    uVar1 = 3;
LAB_0885c4b8:
    uVar3 = 0;
    *(undefined4 *)(param_1 + 200) = uVar1;
    break;
  case 3:
    FUN_0885c33c(param_1);
  default:
    uVar3 = 0;
    break;
  case 4:
  case 5:
    uVar3 = 1;
  }
  return uVar3;
}

// Os 35 words differ; jump table ordering and missing virtual-call receiver require reconstruction.
// near miss from lane lbp8e (unreviewed)
