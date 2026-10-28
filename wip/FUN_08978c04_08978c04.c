/* LBPMATCH module=EBOOT.BIN start=0x08978c04 end=0x08978cb8 symbol=FUN_08978c04 lang=c99 cc=gcc404xs-Os */
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
extern void FUN_089786f4();
extern void FUN_08adb8a4();

void FUN_08978c04(int param_1,int *param_2)
{
  undefined4 *puVar1;
  int iVar2;
  undefined4 *local_1c [3];
  undefined4 *local_20;
  
  local_1c[0] = (undefined4 *)*param_2;
  iVar2 = *(int *)(*(int *)(param_1 + 0x20) + 0xc);
  if (local_1c[0] != (undefined4 *)0x0) {
    *(short *)((int)local_1c[0] + 6) = *(short *)((int)local_1c[0] + 6) + 1;
  }
  local_20 = *(undefined4 **)(param_1 + 0x28);
  if (local_20 != (undefined4 *)0x0) {
    local_20[1] = local_20[1] + 1;
  }
  FUN_089786f4(param_1,iVar2,(int *)local_1c,&local_20);
  puVar1 = local_20;
  if ((local_20 != (undefined4 *)0x0) &&
     (iVar2 = local_20[1], local_20[1] = iVar2 + -1, iVar2 + -1 == 0)) {
    (**(code **)*local_20)(local_20);
    FUN_08adb8a4(puVar1);
  }
  if (local_1c[0] != (undefined4 *)0x0) {
    FUN_08970b6c(local_1c[0]);
  }
  return;
}

// best of the profile sweep: cc=gcc404xs-Os, 22 differing words left of 45.
// near miss from lane lbp2c (unreviewed)
