/* LBPMATCH module=EBOOT.BIN start=0x0892ce98 end=0x0892cf3c symbol=FUN_0892ce98 lang=c99 */
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

extern int DAT_08bedb18;
extern void FUN_0892c970();
extern int FUN_08aad2f0();
extern void FUN_08aadba4();
extern void FUN_08ab0674();

undefined4 FUN_0892ce98(undefined4 param_1,int param_2,unsigned char param_3)
{
  int iVar1;
  int iVar2;
  uint uVar3;
  int iVar4;
  int local_30 [4];
  
  if (param_3 == 1) {
    iVar1 = DAT_08bedb18;
    uVar3 = *(uint *)(param_2 + 0x20);
    iVar4 = *(int *)(param_2 + 0x94);
    local_30[0] = param_2;
    iVar2 = FUN_08aad2f0(1,local_30,0,0);
    FUN_0892c970(iVar1,uVar3,iVar4,iVar2);
    if (param_2 != 0) {
      FUN_08aadba4((undefined4 *)(param_2 + 0x34),(byte *)0x0);
      FUN_08ab0674(*(int *)(param_2 + 0x94),(int *)param_2);
    }
  }
  return 0;
}

// Five words differ: argument-zero ordering and three independent loads; moving global load inside branch improved 24 to 5.
// near miss from lane lbp7a (unreviewed)
