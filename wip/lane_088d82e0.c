/* LBPMATCH module=EBOOT.BIN start=0x088d82e0 end=0x088d8388 symbol=FUN_088d82e0 lang=c99 */
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

extern void FUN_088d68c0();

void FUN_088d82e0(int param_1,int param_2)
{
  uint uVar1;
  int iVar2;
  int iVar3;
  uint *puVar4;
  uint uVar5;
  
  if (param_2 != 0) {
    uVar1 = (uint)*(ushort *)(param_1 + 0x17c);
    uVar5 = *(uint *)(param_2 + 0x38);
    iVar2 = uVar1 + *(int *)(param_1 + 0x16c);
    for (; uVar1 <= (iVar2 - 1U & 0xffff); uVar1 = uVar1 + 1 & 0xffff) {
      iVar3 = *(int *)(param_1 + 0x150) + uVar1 * 0x28;
      if (((iVar3 != 0) && (puVar4 = *(uint **)(iVar3 + 8), puVar4 != (uint *)0x0)) &&
         (puVar4[0xe] == uVar5)) {
        FUN_088d68c0(puVar4);
      }
    }
  }
  return;
}

// Initial primary-profile candidate: 33 differing words; see lane-work diff for details.
// near miss from lane lbp7b (unreviewed)
