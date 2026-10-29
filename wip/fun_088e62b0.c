/* LBPMATCH module=EBOOT.BIN start=0x088e62b0 end=0x088e6358 symbol=FUN_088e62b0 lang=c99 */
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


undefined4 FUN_088e62b0(int param_1)
{
  int iVar1;
  undefined4 uVar2;
  
  if (*(int *)(param_1 + 0x44) == 0) {
    iVar1 = *(int *)(param_1 + 0x4c);
  }
  else {
    if (*(int *)(param_1 + 0x44) != 9) {
      return 0;
    }
    iVar1 = *(int *)(param_1 + 0x4c);
  }
  if (iVar1 == 0) {
    iVar1 = *(int *)(param_1 + 0xa0);
  }
  else if (iVar1 == 4) {
    iVar1 = *(int *)(param_1 + 0xa0);
  }
  else {
    if (iVar1 != 5) {
      return 0;
    }
    iVar1 = *(int *)(param_1 + 0xa0);
  }
  uVar2 = 0;
  if ((((iVar1 == 0) && (uVar2 = 0, *(int *)(param_1 + 0xa4) == 0)) &&
      (*(int *)(param_1 + 0xa8) == 0)) &&
     (((*(int *)(param_1 + 0xac) == 0 && (*(int *)(param_1 + 0xb0) == 0)) &&
      ((*(int *)(param_1 + 0xb4) == 0 && (uVar2 = 1, *(int *)(param_1 + 0xb8) != 0)))))) {
    uVar2 = 0;
  }
  return uVar2;
}

// Baseline generated candidate; 32 differing words. Tested primary and O2 profiles; control flow and types need reconstruction.
// near miss from lane lbp8f (unreviewed)
