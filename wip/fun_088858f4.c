/* LBPMATCH module=EBOOT.BIN start=0x088858f4 end=0x088859e4 symbol=FUN_088858f4 lang=c99 */
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

extern int FUN_0888542c();

undefined4 FUN_088858f4(uint *param_1,int *param_2)
{
  int iVar1;
  int *piVar2;
  int iVar3;
  int iVar4;
  uint uVar5;
  int local_2c;
  int local_30;
  
  iVar1 = FUN_0888542c((int)(param_1 + 4),param_2);
  piVar2 = (int *)(param_1[1] * 8 + param_1[10]);
  local_2c = piVar2[1];
  local_30 = *piVar2;
  iVar3 = FUN_0888542c((int)(param_1 + 4),&local_30);
  uVar5 = param_1[10];
  iVar4 = *param_2;
  piVar2 = (int *)(*param_1 * 8 + uVar5);
  piVar2[1] = param_2[1];
  *piVar2 = iVar4;
  piVar2 = (int *)(*(int *)(iVar1 + 0x18) * 8 + uVar5);
  piVar2[1] = local_2c;
  *piVar2 = local_30;
  *(undefined4 *)(iVar3 + 0x18) = *(undefined4 *)(iVar1 + 0x18);
  *(uint *)(iVar1 + 0x18) = *param_1;
  param_1[1] = param_1[1] + 1 & param_1[2] - 1;
  *param_1 = *param_1 + 1 & param_1[2] - 1;
  return 1;
}

// Baseline generated candidate; 43 differing words. Tested primary and O2 profiles; control flow and types need reconstruction.
// near miss from lane lbp8f (unreviewed)
