/* LBPMATCH module=EBOOT.BIN start=0x0889f514 end=0x0889f5f8 symbol=FUN_0889f514 lang=c99 */
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

extern undefined DAT_08bb1cd0;
extern void FUN_0889a8d0();
extern void FUN_0889f290();
extern int FUN_08a9e4a4();
extern uint * FUN_08b9eb88();

void FUN_0889f514(int *param_1)
{
  bool bVar1;
  uint *puVar2;
  int *piVar3;
  int *piVar4;
  int iVar5;
  int iVar6;
  uint uVar7;
  int iVar8;
  
  param_1[8] = 1;
  iVar8 = param_1[7] * 8 + 4;
  uVar7 = iVar8 + param_1[1] + 0x10;
  puVar2 = (uint *)FUN_08a9e4a4(uVar7,0,0);
  *param_1 = (int)puVar2;
  param_1[2] = uVar7;
  FUN_08b9eb88(puVar2,0,uVar7);
  FUN_0889a8d0(&DAT_08bb1cd0,*(int *)((int)param_1 + 8));
  iVar6 = 0;
  piVar4 = (int *)*param_1 + 1;
  iVar5 = 0;
  param_1[4] = iVar8;
  param_1[6] = 0;
  *(int *)*param_1 = param_1[7];
  while (bVar1 = iVar6 < param_1[7], iVar6 = iVar6 + 1, bVar1) {
    piVar3 = (int *)(param_1[0xf] + iVar5);
    iVar8 = *(int *)(param_1[0xc] + iVar5);
    iVar5 = iVar5 + 4;
    *piVar4 = *piVar3;
    piVar4[1] = iVar8;
    piVar4 = piVar4 + 2;
  }
  FUN_0889f290(piVar4);
  return;
}


// Restored tail-call argument; loop counter, pointer schedule need reconstruction.
// near miss from lane lbp8e (unreviewed)
