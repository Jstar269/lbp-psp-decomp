/* LBPMATCH module=EBOOT.BIN start=0x088d9260 end=0x088d935c symbol=FUN_088d9260 lang=c99 */
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

extern void FUN_088ce2a8();
extern undefined4 FUN_08adb810();

undefined4 * FUN_088d9260(int param_1,undefined4 *param_2,int param_3)
{
  int iVar1;
  undefined4 *puVar2;
  int iVar3;
  
  if (param_3 != 0) {
    iVar3 = *(int *)(param_1 + 0x19c);
    iVar1 = *(int *)(iVar3 + 0xc);
    if (iVar1 < *(int *)(iVar3 + 8)) {
      *(int *)(iVar3 + 0xc) = iVar1 + 1;
      puVar2 = *(undefined4 **)(iVar1 * 4 + *(int *)(iVar3 + 4));
    }
    else {
      *(int *)(iVar3 + 0x10) = *(int *)(iVar3 + 0x10) + 1;
      puVar2 = (undefined4 *)FUN_08adb810(0x13d8,0x10,0,0);
    }
    if (*(uint *)(param_1 + 0x1ac) < *(uint *)(param_1 + 0x1a4)) {
      iVar1 = *(int *)(param_1 + 0x1a8);
      iVar3 = *(int *)(param_1 + 0x1a0);
      *(uint *)(param_1 + 0x1ac) = *(uint *)(param_1 + 0x1ac) + 1;
      *(int *)(param_1 + 0x1a8) = iVar1 + 1;
      *(undefined4 **)(iVar1 * 4 + iVar3) = puVar2;
      if (puVar2 != (undefined4 *)0x0) {
        FUN_088ce2a8(puVar2,param_2,param_3,iVar3,(uint)puVar2);
        return puVar2;
      }
    }
  }
  return (undefined4 *)0x0;
}

// Initial primary-profile candidate: 39 differing words; see lane-work diff for details.
// near miss from lane lbp7b (unreviewed)
