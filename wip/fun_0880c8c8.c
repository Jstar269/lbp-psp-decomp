/* LBPMATCH module=EBOOT.BIN start=0x0880c8c8 end=0x0880c990 symbol=FUN_0880c8c8 lang=c99 */
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

extern undefined4 DAT_08be85f8;
extern void FUN_08968924();

void FUN_0880c8c8(int param_1)
{
  int iVar1;
  int iVar2;
  
  if ((((*(int *)(param_1 + 0xc) == 0) || (*(uchar *)(*(int *)(param_1 + 0xc) + 0x70) == '\0')) ||
      (*(uchar *)(param_1 + 0x1e1) == '\0')) || (*(uchar *)(param_1 + 0x470) != '\0')) {
    return;
  }
  iVar1 = *(int *)(param_1 + 0x1a0);
  iVar2 = 0xb;
  if (iVar1 != 5) {
    if (*(int *)(param_1 + 0xa4) == 0) {
      if (*(int *)(param_1 + 0x6c) == 0) {
        if (*(int *)(param_1 + 0x2c) == 0) {
          if (*(int *)(param_1 + 0x2e4) == 0) {
            iVar2 = 9;
            if (((iVar1 != 1) && (iVar1 != 3)) &&
               ((iVar2 = 9, iVar1 != 9 && (iVar2 = 8, iVar1 == 2)))) {
              iVar2 = 9;
            }
            goto LAB_0880c964;
          }
          iVar1 = *(int *)(param_1 + 0x1b4);
        }
        else {
          iVar1 = *(int *)(param_1 + 0x1b4);
        }
      }
      else {
        iVar1 = *(int *)(param_1 + 0x1b4);
      }
    }
    else {
      iVar1 = *(int *)(param_1 + 0x1b4);
    }
    iVar2 = 0xc;
    if (iVar1 == 0) {
      iVar2 = 10;
    }
  }
LAB_0880c964:
  FUN_08968924(DAT_08be85f8,iVar2);
  return;
}

// Baseline generated candidate; 34 differing words. Tested primary and O2 profiles; control flow and types need reconstruction.
// near miss from lane lbp8f (unreviewed)
