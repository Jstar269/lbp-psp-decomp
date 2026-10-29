/* LBPMATCH module=EBOOT.BIN start=0x08a441f4 end=0x08a442d0 symbol=FUN_08a441f4 lang=c99 cc=gcc404xs-O2 */
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

extern undefined4 FUN_08a50fbc();
extern undefined4 FUN_08a52bb8();

int FUN_08a441f4(undefined4 *param_1,int param_2)
{
  int iVar1;
  int *piVar2;
  int iVar3;
  int iVar4;
  int *piVar5;
  int *piVar6;
  uint local_20 [4];
  
  piVar6 = param_1 + 1;
  piVar5 = (int *)*param_1;
  if (piVar5 != (int *)param_1[1]) {
    do {
      iVar1 = FUN_08a50fbc();
      local_20[0] = *(uint *)(*piVar5 + 0x10);
      iVar1 = FUN_08a52bb8(iVar1,local_20);
      if (iVar1 == 0) {
        piVar2 = (int *)*piVar6;
      }
      else {
        iVar4 = *piVar5;
        iVar1 = *(int *)(iVar4 + 0xc);
        if (*(int *)(iVar1 + 0xa4) == param_2) {
          return iVar4;
        }
        piVar2 = *(int **)(iVar1 + 0x9c);
        if (piVar2 == (int *)(iVar1 + 0x9c)) {
          piVar2 = (int *)*piVar6;
        }
        else {
          iVar3 = piVar2[2];
          while( true ) {
            if (param_2 == *(int *)(iVar3 + 0xa4)) {
              return iVar4;
            }
            piVar2 = (int *)*piVar2;
            if (piVar2 == (int *)(iVar1 + 0x9c)) break;
            iVar3 = piVar2[2];
          }
          piVar2 = (int *)*piVar6;
        }
      }
      piVar5 = piVar5 + 1;
    } while (piVar5 != piVar2);
  }
  return 0;
}

// Baseline generated candidate; 37 differing words. Tested primary and O2 profiles; control flow and types need reconstruction.
// near miss from lane lbp8f (unreviewed)
