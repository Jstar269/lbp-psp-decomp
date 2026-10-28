/* LBPMATCH module=EBOOT.BIN start=0x0892195c end=0x08921a38 symbol=FUN_0892195c lang=c99 cc=gcc171-Os */
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

extern int FUN_08b9e714();

undefined4 FUN_0892195c(int param_1,byte *param_2,uint param_3,int *param_4)
{
  uint uVar1;
  int iVar2;
  uint uVar3;
  uint uVar4;
  byte *pbVar5;
  uint uVar6;
  
  if (*(int *)(param_1 + 4) != 0) {
    uVar3 = *(uint *)(param_1 + 0x10);
    uVar6 = *(uint *)(param_1 + 0xc);
    if (uVar3 < uVar6) {
      if (uVar6 - uVar3 < param_3) {
        return 0;
      }
      uVar1 = uVar3 + param_3;
      pbVar5 = (byte *)(*(int *)(param_1 + 4) + uVar3);
      uVar4 = uVar3;
      do {
        uVar1 = uVar1 + 1;
        iVar2 = FUN_08b9e714(pbVar5,param_2,param_3);
        if (iVar2 == 0) {
          *param_4 = uVar4 - uVar3;
          return 1;
        }
        uVar4 = uVar4 + 1;
        pbVar5 = pbVar5 + 1;
      } while (uVar1 <= uVar6);
    }
  }
  return 0;
}

// profile sweep: 28 differing words left; kept the generator key (normalising was worse or equal).
// near miss from lane lbp2d (unreviewed)
