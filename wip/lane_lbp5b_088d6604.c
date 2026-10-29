/* LBPMATCH module=EBOOT.BIN start=0x088d6604 end=0x088d6674 symbol=FUN_088d6604 lang=c99 */
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

extern undefined2 DAT_08beecb2;

void FUN_088d6604(uint *param_1,byte param_2)
{
  byte bVar1;
  byte bVar2;
  uint uVar3;
  
  bVar1 = *(byte *)((int)param_1 + 0x8e);
  bVar2 = 5;
  if (param_2 < 5) {
    bVar2 = param_2;
  }
  if (param_2 != bVar1) {
    uVar3 = param_1[10];
    *(byte *)((int)param_1 + 0x8e) = bVar2;
    *(byte *)((int)param_1 + 0x8f) = bVar1;
    if (((uVar3 == 3) || (uVar3 == 5)) || (uVar3 == 4)) {
      DAT_08beecb2 = 1;
      return;
    }
    if (uVar3 != 2) {
      *param_1 = *param_1 | 0x8000;
      return;
    }
  }
  return;
}

// NEAR: 7 differing words; primary and O2 profiles tested.
// near miss from lane lbp5b (unreviewed)
