/* LBPMATCH module=EBOOT.BIN start=0x088bc630 end=0x088bc6d8 symbol=FUN_088bc630 lang=c99 */
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

extern void FUN_088bbab8();
extern void FUN_088bbf6c();
extern void FUN_088bc478();

void FUN_088bc630(int param_1)
{
  byte bVar1;
  int iVar2;
  
  bVar1 = *(byte *)(param_1 + 0x58);
  if ((bVar1 & 1) != 0) {
    if ((bVar1 & 2) != 0) {
      if (*(int *)(param_1 + 0x5c) == 1) {
        FUN_088bbab8(param_1);
        iVar2 = 0xc;
      }
      else {
        if (*(int *)(param_1 + 0x5c) != 2) goto LAB_088bc6b8;
        FUN_088bbab8();
        iVar2 = 0xe;
      }
      FUN_088bc478(param_1,iVar2);
      return;
    }
    if (((bVar1 & 4) != 0) || ((bVar1 & 8) != 0)) {
LAB_088bc6b8:
      FUN_088bbf6c(param_1);
      return;
    }
  }
  return;
}

// Baseline generated candidate; 32 differing words. Tested primary and O2 profiles; control flow and types need reconstruction.
// near miss from lane lbp8f (unreviewed)
