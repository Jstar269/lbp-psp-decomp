/* LBPMATCH module=EBOOT.BIN start=0x08a70bb8 end=0x08a70c6c symbol=FUN_08a70bb8 lang=c99 */
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

extern void FUN_08a372bc();
extern void FUN_08a9bff8();
extern undefined4 * FUN_08a9d390();

void FUN_08a70bb8(int param_1,int param_2,undefined4 *param_3)
{
  undefined1 byteValue;
  undefined4 uVar1;
  undefined4 uVar2;
  undefined4 uVar3;
  undefined4 uVar4;
  undefined4 auStack_60 [6];
  undefined4 auStack_48 [6];
  undefined4 auStack_30 [8];
  
  FUN_08a372bc(param_1,param_2,param_3);
  FUN_08a9d390(auStack_30,*(uint *)(param_2 + 0xd4));
  FUN_08a9bff8((int)auStack_30);
  *(undefined4 *)(param_1 + 0xd4) = *(undefined4 *)(param_2 + 0xd4);
  FUN_08a9d390(auStack_48,*(uint *)(param_2 + 0xd8));
  FUN_08a9bff8((int)auStack_48);
  *(undefined4 *)(param_1 + 0xd8) = *(undefined4 *)(param_2 + 0xd8);
  FUN_08a9d390(auStack_60,*(uint *)(param_2 + 0xdc));
  FUN_08a9bff8((int)auStack_60);
  byteValue = *(undefined1 *)(param_2 + 0xd0);
  uVar1 = *(undefined4 *)(param_2 + 0xdc);
  uVar2 = *(undefined4 *)(param_2 + 0xe0);
  uVar3 = *(undefined4 *)(param_2 + 0xe4);
  uVar4 = *(undefined4 *)(param_2 + 0xe8);
  *(undefined1 *)(param_1 + 0xd0) = byteValue;
  *(undefined4 *)(param_1 + 0xdc) = uVar1;
  *(undefined4 *)(param_1 + 0xe0) = uVar2;
  *(undefined4 *)(param_1 + 0xe4) = uVar3;
  *(undefined4 *)(param_1 + 0xe8) = uVar4;
  return;
}

// 10 words differ: final field-copy register allocation and order; named byte local unchanged.
// near miss from lane lbp5a (unreviewed)
