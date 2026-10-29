/* LBPMATCH module=EBOOT.BIN start=0x0880b604 end=0x0880b634 symbol=FUN_0880b604 lang=c99 */
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

extern undefined * FUN_089ecaa8();
extern void FUN_08a64018();

void FUN_0880b604(undefined4 param_1,int param_2)
{
  undefined *puVar1;
  undefined4 uVar2;
  
  uVar2 = *(undefined4 *)(param_2 + 8);
  puVar1 = FUN_089ecaa8();
  FUN_08a64018(uVar2,*(int **)(puVar1 + 0x1b4));
  return;
}

// NEAR: 3 differing words; primary and O2 profiles tested.
// near miss from lane lbp5b (unreviewed)
