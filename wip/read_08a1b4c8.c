/* LBPMATCH module=EBOOT.BIN start=0x08a1b4c8 end=0x08a1b57c symbol=FUN_08a1b4c8 lang=c99 */
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

extern void FUN_08a9df6c();
extern int FUN_08a9ecb8();
extern undefined4 * FUN_08b9e7a8();

void FUN_08a1b4c8(int *param_1,int param_2)
{
  undefined4 *puVar1;
  int iVar2;
  uint uVar3;
  undefined4 *puVar4;
  
  if (*param_1 != 0) {
    FUN_08a9df6c(*param_1);
  }
  param_1[2] = **(int **)(param_2 + 8);
  iVar2 = *(int *)(param_2 + 0x10) + 4;
  *(int *)(param_2 + 0x10) = iVar2;
  uVar3 = param_1[2];
  *(int *)(param_2 + 8) = *(int *)(param_2 + 4) + iVar2;
  puVar1 = (undefined4 *)FUN_08a9ecb8(uVar3,0x40,0,0);
  uVar3 = param_1[2];
  puVar4 = *(undefined4 **)(param_2 + 8);
  *param_1 = (int)puVar1;
  FUN_08b9e7a8(puVar1,puVar4,uVar3);
  iVar2 = uVar3 + *(int *)(param_2 + 0x10);
  *(int *)(param_2 + 8) = *(int *)(param_2 + 4) + iVar2;
  *(int *)(param_2 + 0x10) = iVar2;
  return;
}

// 29 words differ; retail reads the length with unaligned lwl/lwr, as in the separately tested unaligned-copy case where the assembler rejected lwl/lwr.
// near miss from lane lbp7a (unreviewed)
