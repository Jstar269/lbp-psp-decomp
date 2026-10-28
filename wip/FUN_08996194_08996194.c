/* LBPMATCH module=EBOOT.BIN start=0x08996194 end=0x08996268 symbol=FUN_08996194 lang=c99 cc=gcc410-Os */
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

extern undefined4 * FUN_0880f20c();
extern void FUN_08970b6c();
extern undefined4 FUN_08974660();

undefined4 FUN_08996194(int param_1,int param_2)
{
  int iVar1;
  undefined4 uVar2;
  code *pcVar3;
  int *piVar4;
  undefined4 *local_18 [2];
  undefined4 *local_1c;
  
  if (((*(uint *)(param_2 + 4) & 0x2000) == 0) && ((*(uint *)(param_2 + 4) & 0x1000) == 0)) {
    uVar2 = FUN_08974660(param_1,param_2);
  }
  else {
    FUN_0880f20c(local_18,4000);
    for (piVar4 = *(int **)(param_1 + 8); piVar4 != (int *)0x0; piVar4 = (int *)piVar4[2]) {
      local_1c = local_18[0];
      pcVar3 = *(code **)(*piVar4 + 8);
      if (local_18[0] != (undefined4 *)0x0) {
        *(short *)((int)local_18[0] + 6) = *(short *)((int)local_18[0] + 6) + 1;
      }
      iVar1 = (*pcVar3)(piVar4,&local_1c);
      if (local_1c != (undefined4 *)0x0) {
        FUN_08970b6c(local_1c);
      }
      if (iVar1 == 0) break;
    }
    uVar2 = 0;
    if (local_18[0] != (undefined4 *)0x0) {
      FUN_08970b6c(local_18[0]);
      uVar2 = 0;
    }
  }
  return uVar2;
}

// best of the profile sweep: cc=gcc410-Os, 25 differing words left of 53.
// near miss from lane lbp2c (unreviewed)
