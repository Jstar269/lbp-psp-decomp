/* LBPMATCH module=EBOOT.BIN start=0x089e17dc end=0x089e190c symbol=FUN_089e17dc lang=c99 */
/* Hand-written reconstruction from the disassembly (lane lbp3a, Claude Sonnet 5.5); near miss, 7 word(s) differ; names and types await human review. */
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

extern undefined4 DAT_08be84a0;
extern void FUN_088050b8();
extern void FUN_08a1b424();
extern void FUN_08a9e0c4();
extern void FUN_08a9e0cc();
extern void FUN_08adbc24();

void FUN_089e17dc(int param_1)
{
  uint *puVar1;
  undefined4 *puVar2;
  undefined4 *puVar3;
  uint uVar4;
  undefined4 *puVar5;
  uint uVar6;
  
  puVar5 = (undefined4 *)(param_1 + 4);
  for (puVar2 = *(undefined4 **)(param_1 + 4); puVar2 != puVar5; puVar2 = (undefined4 *)*puVar2) {
    puVar1 = (uint *)puVar2[2];
    if (puVar1 != (uint *)0x0) {
      FUN_08a1b424(puVar1);
      FUN_08a9e0cc((uint)puVar1);
    }
  }
  puVar2 = (undefined4 *)*puVar5;
  while (puVar2 != puVar5) {
    puVar3 = (undefined4 *)*puVar2;
    FUN_08adbc24(DAT_08be84a0,(uint)puVar2,0xc);
    puVar2 = puVar3;
  }
  puVar5[1] = puVar5;
  *puVar5 = puVar5;
  puVar3 = (undefined4 *)(param_1 + 0xc);
  puVar2 = *(undefined4 **)(param_1 + 0xc);
  for (; puVar2 != puVar3; puVar2 = (undefined4 *)*puVar2) {
    if (puVar2[2] != 0) {
      FUN_08a9e0c4(puVar2[2]);
    }
  }
  puVar2 = (undefined4 *)*puVar3;
  while (puVar2 != puVar3) {
    puVar5 = (undefined4 *)*puVar2;
    FUN_08adbc24(DAT_08be84a0,(uint)puVar2,0xc);
    puVar2 = puVar5;
  }
  *puVar3 = puVar3;
  uVar6 = param_1 + 0x14;
  puVar3[1] = puVar3;
  puVar1 = (uint *)*(uint *)(param_1 + 0x14);
  while (puVar1 != (uint *)uVar6) {
    uVar4 = *puVar1;
    if ((int *)puVar1[2] != (int *)0x0) {
      FUN_088050b8((int *)puVar1[2]);
    }
    FUN_08adbc24(DAT_08be84a0,(uint)puVar1,0xc);
    puVar1 = (uint *)uVar4;
  }
  ((uint *)uVar6)[1] = uVar6;
  *(uint *)uVar6 = uVar6;
  return;
}
// differs: order of the sentinel-reset stores vs the next list's load (sched), last list stores via s0 (ours) vs head reg s2/s1 (retail)
// tried: store order permutations for list 1, struct/Node rewrite (worse: 59 words), pointer-form stores
// near miss from lane lbp3a (unreviewed)
