/* LBPMATCH module=EBOOT.BIN start=0x088e83e4 end=0x088e8494 symbol=FUN_088e83e4 lang=c99 */
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
extern undefined * DAT_08beed14;
extern void FUN_088cd038();
extern void FUN_088cd31c();
extern void FUN_08adbc24();

void FUN_088e83e4(int param_1)
{
  int iVar1;
  undefined4 *puVar2;
  undefined4 *puVar3;
  undefined4 *puVar4;
  
  iVar1 = *(int *)(DAT_08beed14 + 0x1c4);
  if ((*(uint *)(iVar1 + 0x40) & 0xc) != 0) {
    FUN_088cd038(iVar1,2,'\x01');
  }
  FUN_088cd038(iVar1,0xc,'\0');
  puVar4 = (undefined4 *)(param_1 + 0xc4);
  FUN_088cd31c(*(int *)(DAT_08beed14 + 0x1c4));
  puVar3 = *(undefined4 **)(param_1 + 0xc4);
  while (puVar3 != puVar4) {
    puVar2 = (undefined4 *)*puVar3;
    FUN_08adbc24(DAT_08be84a0,(uint)puVar3,0xc);
    puVar3 = puVar2;
  }
  *(undefined4 **)(param_1 + 200) = puVar4;
  *puVar4 = puVar4;
  *(uint *)(param_1 + 0xd0) = *(uint *)(param_1 + 0xd0) & 0xfffffeff;
  return;
}

// NEAR: 3 differing words; primary and O2 profiles tested.
// near miss from lane lbp5b (unreviewed)
