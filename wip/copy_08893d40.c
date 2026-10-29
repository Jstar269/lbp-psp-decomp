/* LBPMATCH module=EBOOT.BIN start=0x08893d40 end=0x08893e38 symbol=FUN_08893d40 lang=c99 */
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
typedef float undefined4;

extern void FUN_0888b8c4();
extern void FUN_0888b8cc();
extern int * FUN_08893c68();

int * FUN_08893d40(int *param_1,int param_2,undefined4 *param_3)
{
  undefined4 uVar1;
  undefined4 uVar2;
  undefined4 uVar3;
  undefined4 *puVar4;
  undefined4 *puVar5;
  undefined4 *puVar6;
  undefined4 *puVar7;
  undefined4 local_50 [12];
  
  FUN_0888b8c4(param_2 + 0x30);
  puVar7 = param_3 + 8;
  puVar5 = local_50;
  puVar4 = local_50;
  if (((uint)param_3 & 3) == 0) {
    do {
      uVar1 = param_3[1];
      uVar2 = param_3[2];
      uVar3 = param_3[3];
      *puVar5 = *param_3;
      param_3 = param_3 + 4;
      puVar6 = puVar5 + 4;
      puVar5[1] = uVar1;
      puVar5[2] = uVar2;
      puVar5[3] = uVar3;
      puVar5 = puVar6;
    } while (param_3 != puVar7);
    uVar1 = *param_3;
  }
  else {
    do {
      uVar1 = param_3[1];
      uVar2 = param_3[2];
      uVar3 = param_3[3];
      *puVar4 = *param_3;
      param_3 = param_3 + 4;
      puVar4[1] = uVar1;
      puVar6 = puVar4 + 4;
      puVar4[2] = uVar2;
      puVar4[3] = uVar3;
      puVar4 = puVar6;
    } while (param_3 != puVar7);
    uVar1 = *param_3;
  }
  *puVar6 = uVar1;
  FUN_08893c68(param_1,param_2,local_50,'\x01');
  FUN_0888b8cc(param_2 + 0x30);
  return param_1;
}

// 36 words differ; builtin memcpy produces retail unaligned instructions but assembler rejects lwl/lwr for allegrex.
// near miss from lane lbp7a (unreviewed)
