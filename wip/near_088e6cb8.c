/* LBPMATCH module=EBOOT.BIN start=0x088e6cb8 end=0x088e6de4 symbol=FUN_088e6cb8 lang=c99 */
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

extern undefined4 DAT_08bf03b8;
extern undefined4 FUN_0896f06c();
extern undefined4 FUN_08974aa4();

void FUN_088e6cb8(int param_1)
{
  int iVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  
  if ((*(int *)(param_1 + 0xd0) << 0xf < 0) || (*(int *)(param_1 + 0xd0) << 0xc < 0)) {
    if (*(uint *)(param_1 + 0x60) < 0x100) {
      iVar1 = FUN_0896f06c(DAT_08bf03b8);
      iVar1 = FUN_08974aa4(iVar1,2);
      iVar5 = *(int *)(iVar1 + 0x14);
      iVar1 = FUN_0896f06c(DAT_08bf03b8);
      iVar1 = FUN_08974aa4(iVar1,4);
      iVar4 = *(int *)(param_1 + 0x60);
      iVar3 = *(int *)((0xb - *(short *)(*(int *)(iVar1 + 0x14) + 0x5c)) * 4 +
                      *(int *)(*(int *)(iVar1 + 0x14) + 0x58));
      iVar2 = iVar4 * 0x1000000 + 0xffffff;
      iVar1 = *(int *)((10 - *(short *)(iVar5 + 0x5c)) * 4 + *(int *)(iVar5 + 0x58));
      if (iVar3 != 0) {
        *(int *)(iVar3 + 0x68) = iVar2;
      }
      if (iVar1 != 0) {
        *(int *)(iVar1 + 0x68) = iVar2;
      }
      *(int *)(param_1 + 0x60) = iVar4 + 5;
    }
  }
  else {
    iVar1 = FUN_0896f06c(DAT_08bf03b8);
    iVar1 = FUN_08974aa4(iVar1,2);
    iVar1 = *(int *)((10 - *(short *)(*(int *)(iVar1 + 0x14) + 0x5c)) * 4 +
                    *(int *)(*(int *)(iVar1 + 0x14) + 0x58));
    if (iVar1 != 0) {
      *(undefined4 *)(iVar1 + 0x68) = 0xffffffff;
    }
  }
  return;
}

// Four differences are bit-test instruction selection; unsigned masks increased code size.
// near miss from lane lbp2a (unreviewed)
