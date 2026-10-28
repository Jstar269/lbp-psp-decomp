/* LBPMATCH module=EBOOT.BIN start=0x08a9b288 end=0x08a9b394 symbol=FUN_08a9b288 lang=c99 */
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

extern void FUN_08a9e0cc();

void FUN_08a9b288(undefined4 *param_1)
{
  int *piVar1;
  undefined4 *puVar2;
  undefined4 *puVar3;
  undefined4 *puVar4;
  uint uVar5;
  undefined4 *puVar6;
  
  for (puVar6 = (undefined4 *)*param_1; puVar6 != param_1; puVar6 = (undefined4 *)*puVar6) {
    for (puVar4 = (undefined4 *)**(undefined4 **)(puVar6[2] + 8);
        puVar4 != *(undefined4 **)(puVar6[2] + 8); puVar4 = (undefined4 *)*puVar4) {
      piVar1 = (int *)puVar4[2];
      if (piVar1 != (int *)0x0) {
        (**(code **)(*piVar1 + 0xc))(piVar1);
      }
    }
    puVar3 = (undefined4 *)*puVar4;
    while (puVar3 != puVar4) {
      puVar2 = (undefined4 *)*puVar3;
      FUN_08a9e0cc((uint)puVar3);
      puVar3 = puVar2;
    }
    uVar5 = puVar6[2];
    *puVar4 = (undefined4)puVar4;
    puVar4[1] = (undefined4)puVar4;
    if (uVar5 != 0) {
      puVar4 = *(undefined4 **)(uVar5 + 8);
      if (puVar4 != (undefined4 *)0x0) {
        puVar3 = (undefined4 *)*puVar4;
        while (puVar3 != puVar4) {
          puVar2 = (undefined4 *)*puVar3;
          FUN_08a9e0cc((uint)puVar3);
          puVar3 = puVar2;
        }
        FUN_08a9e0cc((uint)puVar4);
      }
      FUN_08a9e0cc(uVar5);
    }
  }
  puVar6 = (undefined4 *)*param_1;
  while (puVar6 != param_1) {
    puVar4 = (undefined4 *)*puVar6;
    FUN_08a9e0cc((uint)puVar6);
    puVar6 = puVar4;
  }
  *param_1 = (undefined4)param_1;
  param_1[1] = (undefined4)param_1;
  return;
}


// Two remaining differences use the terminating cursor rather than the equivalent list head for reset stores; source ordering fixes the other two.
// near miss from lane lbp2a (unreviewed)
