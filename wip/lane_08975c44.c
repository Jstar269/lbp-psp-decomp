/* LBPMATCH module=EBOOT.BIN start=0x08975c44 end=0x08975d3c symbol=FUN_08975c44 lang=c99 */
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


uint FUN_08975c44(int param_1,ushort param_2)
{
  ushort uVar1;
  uint uVar2;
  uint uVar3;
  uint uVar4;
  uint uVar5;
  int iVar6;
  
  uVar5 = *(uint *)(*(int *)(param_1 + 4) + 8);
  iVar6 = *(int *)(*(int *)(param_1 + 4) + 0x18);
  uVar3 = 0;
  uVar2 = uVar5;
  while( true ) {
    uVar4 = uVar2;
    uVar2 = (int)(uVar3 + uVar4) / 2;
    uVar1 = *(ushort *)(uVar2 * 2 + iVar6);
    if (uVar1 == param_2) {
      return uVar2 & 0xffff;
    }
    if (uVar2 == uVar3) break;
    if (uVar1 <= param_2) {
      uVar3 = uVar2;
      uVar2 = uVar4;
    }
  }
  if ((((param_2 != 0x5f) && (0x1f < param_2)) && (param_2 != 0xa0)) && (param_2 != 10)) {
    uVar3 = 0;
    if (param_2 == 0xad) {
      return 0;
    }
    while( true ) {
      uVar2 = uVar5;
      uVar5 = (int)(uVar3 + uVar2) / 2;
      uVar1 = *(ushort *)(uVar5 * 2 + iVar6);
      if (uVar1 == 0x5f) {
        return uVar5 & 0xffff;
      }
      if (uVar5 == uVar3) break;
      if (uVar1 < 0x60) {
        uVar3 = uVar5;
        uVar5 = uVar2;
      }
    }
    return 0;
  }
  return 0;
}

// Initial primary-profile candidate: 38 differing words; see lane-work diff for details.
// near miss from lane lbp7b (unreviewed)
