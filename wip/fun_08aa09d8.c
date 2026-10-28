/* LBPMATCH module=EBOOT.BIN start=0x08aa09d8 end=0x08aa0a78 symbol=FUN_08aa09d8 lang=c99 cc=gcc404xs-O2 */
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

extern undefined * DAT_08bf9350;
extern void FUN_08a9b0c8();
extern void FUN_08a9b784();
extern void FUN_08a9b810();
extern void FUN_08a9bff8();
extern undefined4 * FUN_08a9d390();

undefined4 FUN_08aa09d8(uint param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)
{
  int iVar1;
  int iVar2;
  undefined4 auStack_38 [6];
  undefined4 auStack_44 [3];
  undefined4 uStack_48;
  undefined4 uStack_4c;
  undefined4 uStack_50;
  
  iVar1 = DAT_08bf9350;
  iVar2 = *(int *)(DAT_08bf9350 + 0x1c);
  uStack_50 = param_2;
  uStack_4c = param_3;
  uStack_48 = param_4;
  FUN_08a9d390(auStack_38,param_1);
  FUN_08a9bff8((int)auStack_38);
  FUN_08a9b810(auStack_44,param_1,0,&uStack_50);
  FUN_08a9b784(iVar2,auStack_44);
  FUN_08a9b0c8(*(undefined4 **)(iVar1 + 0x1c));
  return 0;
}


// 30 words differ; primary Os and O2 profiles tested.
// near miss from lane lbp1d (unreviewed)
