/* LBPMATCH module=EBOOT.BIN start=0x08a5fd30 end=0x08a5fdc4 symbol=FUN_08a5fd30 lang=c99 cc=gcc404xs-O2 */
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

extern undefined DAT_08bc4d78;
extern int FUN_08a1d1bc();
extern void FUN_08a6b5c4();
extern void FUN_08a718dc();
extern void FUN_08a9bff8();
extern void FUN_08a9c164();
extern uint FUN_08a9d790();

void FUN_08a5fd30(int *param_1)
{
  int iVar1;
  uint uVar2;
  int iStack_30;
  undefined4 uStack_2c;
  int iStack_28;
  undefined4 uStack_24;
  
  FUN_08a6b5c4(param_1);
  iVar1 = (**(code **)(*param_1 + 100))(param_1);
  FUN_08a9c164(&iStack_28,(uint *)&DAT_08bc4d78);
  uStack_2c = uStack_24;
  iStack_30 = iStack_28;
  uVar2 = FUN_08a9d790(&iStack_30);
  iVar1 = FUN_08a1d1bc(iVar1,uVar2);
  param_1[0xbd] = iVar1;
  FUN_08a9bff8((int)&iStack_28);
  FUN_08a718dc(param_1);
  return;
}
// O2 26 words differ; Os 28. Stack aggregate and virtual call scheduling remain.
// near miss from lane lbp13a (unreviewed)
