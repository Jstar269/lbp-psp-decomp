/* LBPMATCH module=EBOOT.BIN start=0x089d84bc end=0x089d856c symbol=FUN_089d84bc lang=c99 cc=gcc171-Os */
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

extern void FUN_08970b6c();

void FUN_089d84bc(int param_1)
{
  int iVar1;
  code *pcVar2;
  undefined4 *puVar3;
  int *piVar4;
  undefined4 *apuStack_20 [4];
  
  puVar3 = *(undefined4 **)(param_1 + 0x30);
  if (puVar3 != (undefined4 *)0x0) {
    piVar4 = *(int **)(param_1 + 8);
    *(short *)((int)puVar3 + 6) = *(short *)((int)puVar3 + 6) + 1;
    for (; piVar4 != (int *)0x0; piVar4 = (int *)piVar4[2]) {
      pcVar2 = *(code **)(*piVar4 + 8);
      if (puVar3 != (undefined4 *)0x0) {
        *(short *)((int)puVar3 + 6) = *(short *)((int)puVar3 + 6) + 1;
      }
      apuStack_20[0] = puVar3;
      iVar1 = (*pcVar2)(piVar4,apuStack_20);
      if (apuStack_20[0] != (undefined4 *)0x0) {
        FUN_08970b6c(apuStack_20[0]);
      }
      if (iVar1 == 0) break;
    }
    if (puVar3 != (undefined4 *)0x0) {
      FUN_08970b6c(puVar3);
    }
  }
  return;
}

// best of the profile sweep: cc=gcc171-Os, 22 differing words left of 44.
// near miss from lane lbp2c (unreviewed)
