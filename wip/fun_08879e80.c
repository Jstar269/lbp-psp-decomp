/* LBPMATCH module=EBOOT.BIN start=0x08879e80 end=0x0887a024 symbol=FUN_08879e80 lang=c99 */
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

extern int FUN_0887977c();

undefined4 FUN_08879e80(uint *param_1,undefined4 *param_2,undefined4 param_3,uint param_4,uint param_5)
{
  uint uVar1;
  uint uVar2;
  uint uVar3;
  int iVar4;
  int iVar5;
  int iVar6;
  int iVar7;
  uint uVar8;
  uint uVar9;
  uint uVar10;
  uint uVar11;
  uint uVar12;
  uint uVar13;
  uint uVar14;
  uint uVar15;
  uint uVar16;
  int iVar17;
  undefined4 *puVar18;
  int iVar19;
  uint *puVar20;
  uint uVar21;
  uint uVar22;
  uint uVar23;
  undefined4 local_30;
  uint local_34;
  uint local_38;
  uint local_3c;
  undefined4 local_40;
  
  puVar20 = param_1 + 4;
  iVar17 = FUN_0887977c((int)puVar20,param_2);
  puVar18 = (undefined4 *)(param_1[1] * 0x14 + param_1[10]);
  uVar1 = (int)puVar18 + 0xbU & 3;
  uVar2 = (int)puVar18 + 0xfU & 3;
  local_40 = *puVar18;
  uVar21 = puVar18[1];
  local_30 = puVar18[4];
  uVar8 = (uint)(puVar18 + 2) & 3;
  uVar22 = (*(int *)(((int)puVar18 + 0xbU) - uVar1) << (3 - uVar1) * 8 |
           param_4 & 0xffffffffU >> (uVar1 + 1) * 8) & -1 << (4 - uVar8) * 8 |
           *(uint *)((int)(puVar18 + 2) - uVar8) >> uVar8 * 8;
  uVar1 = (uint)(puVar18 + 3) & 3;
  uVar23 = (*(int *)(((int)puVar18 + 0xfU) - uVar2) << (3 - uVar2) * 8 |
           param_5 & 0xffffffffU >> (uVar2 + 1) * 8) & -1 << (4 - uVar1) * 8 |
           *(uint *)((int)(puVar18 + 3) - uVar1) >> uVar1 * 8;
  local_3c = uVar21;
  local_38 = uVar22;
  local_34 = uVar23;
  iVar19 = FUN_0887977c((int)puVar20,&local_40);
  uVar1 = (int)param_2 + 7U & 3;
  iVar4 = *(int *)(((int)param_2 + 7U) - uVar1);
  uVar2 = (int)param_2 + 0xbU & 3;
  iVar5 = *(int *)(((int)param_2 + 0xbU) - uVar2);
  uVar8 = (int)param_2 + 0xfU & 3;
  iVar6 = *(int *)(((int)param_2 + 0xfU) - uVar8);
  uVar3 = (int)param_2 + 0x13U & 3;
  iVar7 = *(int *)(((int)param_2 + 0x13U) - uVar3);
  puVar18 = (undefined4 *)(*param_1 * 0x14 + param_1[10]);
  uVar9 = (uint)(param_2 + 1) & 3;
  uVar13 = *(uint *)((int)(param_2 + 1) - uVar9);
  uVar10 = (uint)(param_2 + 4) & 3;
  uVar14 = *(uint *)((int)(param_2 + 4) - uVar10);
  uVar11 = (uint)(param_2 + 3) & 3;
  uVar15 = *(uint *)((int)(param_2 + 3) - uVar11);
  uVar12 = (uint)(param_2 + 2) & 3;
  uVar16 = *(uint *)((int)(param_2 + 2) - uVar12);
  *puVar18 = *param_2;
  puVar18[1] = (iVar4 << (3 - uVar1) * 8 | uVar21 & 0xffffffffU >> (uVar1 + 1) * 8) &
               -1 << (4 - uVar9) * 8 | uVar13 >> uVar9 * 8;
  puVar18[2] = (iVar5 << (3 - uVar2) * 8 | (uint)puVar20 & 0xffffffffU >> (uVar2 + 1) * 8) &
               -1 << (4 - uVar12) * 8 | uVar16 >> uVar12 * 8;
  puVar18[3] = (iVar6 << (3 - uVar8) * 8 | uVar22 & 0xffffffffU >> (uVar8 + 1) * 8) &
               -1 << (4 - uVar11) * 8 | uVar15 >> uVar11 * 8;
  puVar18[4] = (iVar7 << (3 - uVar3) * 8 | uVar23 & 0xffffffffU >> (uVar3 + 1) * 8) &
               -1 << (4 - uVar10) * 8 | uVar14 >> uVar10 * 8;
  puVar18 = (undefined4 *)(*(int *)(iVar17 + 0x24) * 0x14 + param_1[10]);
  *puVar18 = local_40;
  puVar18[1] = local_3c;
  puVar18[2] = local_38;
  puVar18[3] = local_34;
  puVar18[4] = local_30;
  *(undefined4 *)(iVar19 + 0x24) = *(undefined4 *)(iVar17 + 0x24);
  *(uint *)(iVar17 + 0x24) = *param_1;
  param_1[1] = param_1[1] + 1 & param_1[2] - 1;
  *param_1 = *param_1 + 1 & param_1[2] - 1;
  return 1;
}
// g14 baseline: 227 words differ; unaligned copies need restructuring.
// near miss from lane lbp13d (unreviewed)
