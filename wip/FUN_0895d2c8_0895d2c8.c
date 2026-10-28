/* LBPMATCH module=EBOOT.BIN start=0x0895d2c8 end=0x0895d380 symbol=FUN_0895d2c8 lang=c99 cc=gcc402x-O1 */
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

extern undefined4 FUN_0891d6e4();

void FUN_0895d2c8(int param_1,undefined4 *param_2)
{
  int iVar1;
  int iVar2;
  undefined4 *puVar3;
  undefined4 uVar4;
  int *piVar5;
  
  iVar1 = FUN_0891d6e4(*(undefined4 **)(*(int *)(param_1 + 0x54) + 0xa8));
  iVar2 = FUN_0891d6e4(*(undefined4 **)(*(int *)(param_1 + 0x54) + 0xa8));
  piVar5 = (int *)(*(int *)(param_1 + 0x28) * 4 + iVar1 + 4);
  if ((*(int *)(param_1 + 0x28) == 0) || (*(int *)(iVar2 + *(int *)(iVar1 + 4)) != *piVar5)) {
    iVar1 = *piVar5;
    *(undefined1 *)(param_1 + 0x32) = 0;
    puVar3 = (undefined4 *)(iVar2 + iVar1);
    uVar4 = *puVar3;
    param_2[2] = puVar3 + 2;
    *param_2 = uVar4;
    param_2[1] = puVar3[1];
  }
  else {
    *(undefined1 *)(param_1 + 0x32) = 1;
    param_2[2] = 0;
    *param_2 = 0;
    param_2[1] = 0;
  }
  return;
}

// profile sweep: 24 differing words left; kept the generator key (normalising was worse or equal).
// near miss from lane lbp2d (unreviewed)
