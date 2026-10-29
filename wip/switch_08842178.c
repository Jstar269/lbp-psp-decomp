/* LBPMATCH module=EBOOT.BIN start=0x08842178 end=0x0884224c symbol=FUN_08842178 lang=c99 */
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

bool FUN_08842178(int param_1)
{
  int iVar1;
  uint uVar2;
  int iVar3;
  
  iVar3 = 0;
  uVar2 = 0;
switchD_088421c0_caseD_0:
  uVar2 = uVar2 + 1;
switchD_088421c0_default:
  iVar3 = iVar3 + 1;
  if ((iVar3 == 5) || (iVar3 == 4)) {
    iVar3 = FUN_0891d6e4(*(undefined4 **)(*(int *)(param_1 + 8) + 0xa8));
    return (1 << (uVar2 & 7) & (uint)*(byte *)(iVar3 + (uVar2 >> 3) + 0xc)) != 0;
  }
  switch(iVar3) {
  case 0:
  case 1:
    goto switchD_088421c0_caseD_0;
  case 2:
    iVar1 = FUN_0891d6e4(*(undefined4 **)(*(int *)(param_1 + 8) + 0xa8));
    iVar1 = *(int *)(iVar1 + 4);
    break;
  case 3:
    iVar1 = FUN_0891d6e4(*(undefined4 **)(*(int *)(param_1 + 8) + 0xa8));
    iVar1 = *(int *)(iVar1 + 8);
    break;
  default:
    goto switchD_088421c0_default;
  }
  uVar2 = uVar2 + iVar1;
  goto switchD_088421c0_default;
}

// 30 words differ; natural for/switch reconstruction changed jump table and layout.
// near miss from lane lbp7a (unreviewed)
