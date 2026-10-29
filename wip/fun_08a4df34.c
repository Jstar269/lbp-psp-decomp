/* LBPMATCH module=EBOOT.BIN start=0x08a4df34 end=0x08a4dfd8 symbol=FUN_08a4df34 lang=c99 cc=gcc404xs-O2 */
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

extern undefined4 DAT_08be84a0;
extern void FUN_08a34620();
extern void FUN_08adbc24();
extern void FUN_08b88fc8();

void FUN_08a4df34(int param_1,undefined4 param_2)
{
  int *piVar1;
  uint uVar2;
  int *piVar3;
  
  piVar3 = (int *)(param_1 + 0x30c);
  *(undefined4 *)(param_1 + 0x2e4) = param_2;
  piVar1 = *(int **)(param_1 + 0x30c);
  while( true ) {
    uVar2 = 0;
    if (piVar1 != piVar3) {
      uVar2 = 0;
      do {
        piVar1 = (int *)*piVar1;
        uVar2 = uVar2 + 1;
      } while (piVar1 != piVar3);
    }
    if (uVar2 <= *(uint *)(param_1 + 0x2e4)) break;
    FUN_08a34620(*(int **)(*piVar3 + 8));
    piVar1 = (int *)*piVar3;
    FUN_08b88fc8(piVar1);
    FUN_08adbc24(DAT_08be84a0,(uint)piVar1,0xc);
    piVar1 = *(int **)(param_1 + 0x30c);
  }
  return;
}

// Baseline generated candidate; 33 differing words. Tested primary and O2 profiles; control flow and types need reconstruction.
// near miss from lane lbp8f (unreviewed)
