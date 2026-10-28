/* LBPMATCH module=EBOOT.BIN start=0x088f87ec end=0x088f8960 symbol=FUN_088f87ec lang=c99 cc=gcc404xs-Os */
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
extern void FUN_08a9e0c4();
extern void FUN_08adbc24();

void FUN_088f87ec(undefined4 *param_1)
{
  int *piVar1;
  uint uVar2;
  undefined4 *puVar3;
  undefined4 *puVar4;
  undefined4 *puVar5;
  
  if (param_1[10] != 0) {
    FUN_08a9e0c4(param_1[10]);
    param_1[10] = 0;
  }
  uVar2 = param_1[8];
  if (uVar2 != 0) {
    FUN_08a9e0c4(uVar2);
    param_1[8] = 0;
  }
  uVar2 = param_1[9];
  if (uVar2 != 0) {
    FUN_08a9e0c4(uVar2);
    param_1[9] = 0;
  }
  puVar3 = (undefined4 *)param_1[2];
  puVar4 = param_1 + 2;
  for (; puVar3 != puVar4; puVar3 = (undefined4 *)*puVar3) {
    piVar1 = *(int **)(puVar3[2] + 0x68);
    *(undefined4 *)(puVar3[2] + 0x68) = 0;
    if (piVar1 != (int *)0x0) {
      FUN_088050b8(piVar1);
    }
  }
  puVar3 = (undefined4 *)*param_1;
  while (puVar3 != param_1) {
    puVar5 = (undefined4 *)*puVar3;
    FUN_08adbc24(DAT_08be84a0,(uint)puVar3,0xc);
    puVar3 = puVar5;
  }
  *param_1 = param_1;
  param_1[1] = param_1;
  puVar3 = (undefined4 *)*puVar4;
  while (puVar3 != puVar4) {
    puVar5 = (undefined4 *)*puVar3;
    FUN_08adbc24(DAT_08be84a0,(uint)puVar3,0xc);
    puVar3 = puVar5;
  }
  *puVar4 = puVar4;
  puVar5 = param_1 + 4;
  param_1[3] = puVar4;
  puVar3 = (undefined4 *)param_1[4];
  while (puVar3 != puVar5) {
    puVar4 = (undefined4 *)*puVar3;
    FUN_08adbc24(DAT_08be84a0,(uint)puVar3,0xc);
    puVar3 = puVar4;
  }
  *puVar5 = puVar5;
  puVar4 = param_1 + 6;
  param_1[5] = puVar5;
  puVar3 = (undefined4 *)param_1[6];
  while (puVar3 != puVar4) {
    puVar5 = (undefined4 *)*puVar3;
    FUN_08adbc24(DAT_08be84a0,(uint)puVar3,0xc);
    puVar3 = puVar5;
  }
  param_1[7] = puVar4;
  param_1[0xb] = 0;
  *puVar4 = puVar4;
  *(undefined1 *)(param_1 + 0xd) = 0;
  param_1[0xc] = 0;
  return;
}

// residual: store pairs swapped (s1+4 / s1+0xc), one store uses a different base (s1+0xc vs s2+4) and one zero store is
// sw where retail has sb (48(s1) vs 52(s1)). more than one cause at once; parked.
// near miss from lane lbp2b (unreviewed)
