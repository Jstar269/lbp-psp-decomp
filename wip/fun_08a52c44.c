/* LBPMATCH module=EBOOT.BIN start=0x08a52c44 end=0x08a52d30 symbol=FUN_08a52c44 lang=c99 */
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

extern undefined4 * FUN_0880fb50();
extern undefined4 FUN_08a52414();
extern undefined4 FUN_08a52bb8();

void FUN_08a52c44(int param_1,undefined4 *param_2,int *param_3)
{
  int iVar1;
  int iVar2;
  int *piVar3;
  int iVar4;
  int iVar5;
  uint local_30 [4];
  
  FUN_0880fb50(param_3,param_2);
  piVar3 = (int *)*param_3;
  while (piVar3 != param_3) {
    iVar2 = piVar3[2];
    if (*(int *)(iVar2 + 0x44) == 0x23) {
      iVar5 = *(int *)(iVar2 + 0x9c);
      if (iVar5 == 0) {
        piVar3 = (int *)*piVar3;
      }
      else {
        iVar4 = 0;
        iVar1 = *(int *)(iVar2 + 0xa0);
        while( true ) {
          local_30[0] = *(uint *)(iVar4 * 4 + iVar1);
          iVar4 = iVar4 + 1;
          iVar1 = FUN_08a52bb8(param_1,local_30,local_30[0]);
          iVar1 = FUN_08a52414(param_1,iVar1,param_3);
          if (iVar1 != 0) {
            piVar3 = (int *)*param_3;
          }
          if (iVar5 == iVar4) break;
          iVar1 = *(int *)(iVar2 + 0xa0);
        }
        piVar3 = (int *)*piVar3;
      }
    }
    else {
      piVar3 = (int *)*piVar3;
    }
  }
  return;
}


// Restored third argument to FUN_08a52bb8; nested loop and call allocation require reconstruction.
// near miss from lane lbp8e (unreviewed)
