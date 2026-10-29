/* LBPMATCH module=EBOOT.BIN start=0x08837568 end=0x088375fc symbol=FUN_08837568 lang=c99 */
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

extern undefined4 * FUN_08837360();
extern void FUN_088374f0();

int FUN_08837568(char *param_1,char *param_2)
{
  undefined4 *puVar1;
  undefined4 *puVar2;
  int iVar3;
  undefined4 uVar4;
  char *iVar5;
  
  if (param_1 != param_2) {
    FUN_088374f0(param_1);
    if (*(undefined4 **)(param_2 + 8) != (undefined4 *)0x0) {
      puVar1 = FUN_08837360(param_1,*(undefined4 **)(param_2 + 8),param_1 + 4);
      *(undefined4 **)(param_1 + 8) = puVar1;
      do {
        puVar2 = puVar1;
        puVar1 = (undefined4 *)puVar2[2];
      } while (puVar1 != (undefined4 *)0x0);
      *(undefined4 **)(param_1 + 0xc) = puVar2;
      iVar3 = *(int *)(param_1 + 8);
      do {
        iVar5 = iVar3;
        iVar3 = *(int *)(iVar5 + 0xc);
      } while (iVar3 != 0);
      uVar4 = *(undefined4 *)(param_2 + 0x14);
      *(int *)(param_1 + 0x10) = iVar5;
      *(undefined4 *)(param_1 + 0x14) = uVar4;
    }
  }
  return param_1;
}

// Initial primary-profile candidate: 23 differing words; see lane-work diff for details.
// near miss from lane lbp7b (unreviewed)
