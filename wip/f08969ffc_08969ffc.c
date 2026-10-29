/* LBPMATCH module=EBOOT.BIN start=0x08969ffc end=0x0896a070 symbol=FUN_08969ffc lang=c99 */
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

extern void FUN_08969dac();

void FUN_08969ffc(int param_1)
{
  int iVar1;
  uint uVar2;
  undefined4 *puVar3;
  
  FUN_08969dac(param_1);
  iVar1 = *(int *)(param_1 + 0x2c);
  *(undefined4 *)(param_1 + 0x3c) = 0;
  puVar3 = *(undefined4 **)(iVar1 + 4);
  *(undefined4 **)(iVar1 + 4) = puVar3 + 1;
  *puVar3 = 0x12000102;
  uVar2 = *(uint *)(param_1 + 0x38);
  *(undefined4 **)(iVar1 + 4) = puVar3 + 3;
  puVar3[1] = ((uVar2 >> 0x18) & 0xf) << 0x10 | 0x10000000;
  puVar3[2] = uVar2 & 0xffffff | 0x1000000;
  return;
}

// 23 words differ; compiler eliminates intermediate pointer store and reschedules output writes.
// near miss from lane lbp13b (unreviewed)
