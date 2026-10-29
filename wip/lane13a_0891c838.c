/* LBPMATCH module=EBOOT.BIN start=0x0891c838 end=0x0891c8d0 symbol=FUN_0891c838 lang=c99 */
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

extern undefined4 DAT_08bef654;
extern undefined4 DAT_08bef658;
extern int FUN_08aad2f0();
extern void FUN_08aadba4();
extern void FUN_08ab0674();

undefined4 FUN_0891c838(undefined4 param_1,int param_2,uchar param_3)
{
  int iVar1;
  int aiStack_20 [4];
  
  if ((param_2 != 0) && (param_3 == '\x01')) {
    if (*(undefined1 **)(param_2 + 0x24) != (undefined1 *)0x0) {
      **(undefined1 **)(param_2 + 0x24) = 1;
    }
    aiStack_20[0] = param_2;
    iVar1 = FUN_08aad2f0(1,aiStack_20,0,0);
    if (iVar1 == 0) {
      DAT_08bef658 = 0;
    }
    else {
      DAT_08bef658 = 4;
    }
    DAT_08bef654 = 3;
    FUN_08aadba4((undefined4 *)(param_2 + 0x34),(byte *)0x0);
    FUN_08ab0674(*(int *)(param_2 + 0x94),(int *)param_2);
  }
  return 0;
}
// 26 words differ at Os; O2 differs by 36.
// near miss from lane lbp13a (unreviewed)
