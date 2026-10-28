/* LBPMATCH module=EBOOT.BIN start=0x08827b34 end=0x08827e6c symbol=FUN_08827b34 lang=c99 */
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

extern undefined4 DAT_08be83e0;
extern undefined4 DAT_08be83e4;
extern undefined4 DAT_08be83e8;
extern undefined4 DAT_08be83ec;
extern undefined4 DAT_08be83f0;
extern undefined4 DAT_08be83f4;
extern undefined4 DAT_08be8400;
extern undefined4 DAT_08be8404;
extern undefined4 DAT_08be8408;
extern undefined4 DAT_08be840c;
extern undefined4 DAT_08be8410;
extern undefined4 DAT_08be8414;
extern undefined4 DAT_08be8418;
extern undefined4 DAT_08be841c;
extern undefined4 DAT_08be8420;
extern undefined4 DAT_08be8424;
extern undefined4 DAT_08be8428;
extern undefined4 DAT_08be842c;
extern undefined4 DAT_08be8430;
extern undefined4 DAT_08be8434;
extern undefined4 DAT_08be8438;
extern undefined4 DAT_08be843c;
extern undefined4 DAT_08be8440;
extern undefined4 DAT_08be8444;
extern undefined DAT_08bec504;
extern undefined4 DAT_08bec528;
extern undefined4 DAT_08bec52c;
extern undefined4 DAT_08bec530;
extern undefined4 DAT_08bec534;
extern undefined4 DAT_08bec538;
extern undefined4 DAT_08bec53c;
extern undefined4 DAT_08bec540;
extern uint FUN_08a1bea4();
extern void FUN_08a1bed0();
extern void FUN_08a1befc();
extern void FUN_08adb8a4();

void FUN_08827b34(int param_1,int param_2)
{
  uint uVar1;
  uint uVar2;
  uint uVar3;
  
  if (param_1 == 1) {
    if (param_2 == 0xffff) {
      DAT_08bec540 = 0xff7fffff;
      DAT_08bec53c = 9;
      DAT_08bec538 = 0xd;
      DAT_08bec534 = 0x19;
      DAT_08bec530 = 6;
      DAT_08bec528 = 0xf;
      DAT_08bec52c = 0xf;
      uVar1 = FUN_08a1bea4(0,2,3,0,0);
      FUN_08a1bed0(0,(undefined4 *)&DAT_08bec504,uVar1,0,0,0,0xff000000,0xff000000,0xff000000,
                   0xff000000);
      uVar1 = DAT_08be83f0 + 1;
      DAT_08be83f4 = (uint)(uVar1 < DAT_08be83f0) + DAT_08be83f4;
      if ((uVar1 == 1) && (DAT_08be83f4 == 0)) {
        DAT_08be8430 = 0;
        DAT_08be8444 = 0;
        DAT_08be8438 = 0;
        DAT_08be843c = 0;
        DAT_08be8440 = 0;
        DAT_08be8434 = 0;
      }
      uVar2 = DAT_08be83e8 + 1;
      DAT_08be83ec = (uint)(uVar2 < DAT_08be83e8) + DAT_08be83ec;
      if ((uVar2 == 1) && (DAT_08be83ec == 0)) {
        DAT_08be8418 = 0;
        DAT_08be842c = 0;
        DAT_08be8420 = 0;
        DAT_08be8424 = 0;
        DAT_08be8428 = 0;
        DAT_08be841c = 0;
      }
      uVar3 = DAT_08be83e0 + 1;
      DAT_08be83e4 = (uint)(uVar3 < DAT_08be83e0) + DAT_08be83e4;
      DAT_08be83e0 = uVar3;
      DAT_08be83e8 = uVar2;
      DAT_08be83f0 = uVar1;
      if ((uVar3 == 1) && (DAT_08be83e4 == 0)) {
        DAT_08be8400 = 0;
        DAT_08be8414 = 0;
        DAT_08be8408 = 0;
        DAT_08be840c = 0;
        DAT_08be8410 = 0;
        DAT_08be8404 = 0;
      }
    }
  }
  else if ((param_1 == 0) && (param_2 == 0xffff)) {
    uVar1 = DAT_08be83e0 - 1;
    DAT_08be83e4 = (uint)(uVar1 < DAT_08be83e0) + DAT_08be83e4 + -1;
    DAT_08be83e0 = uVar1;
    if ((uVar1 == 0 && DAT_08be83e4 == 0) && (DAT_08be8400 != 0)) {
      FUN_08adb8a4(DAT_08be8400);
    }
    uVar1 = DAT_08be83e8 - 1;
    DAT_08be83ec = (uint)(uVar1 < DAT_08be83e8) + DAT_08be83ec + -1;
    DAT_08be83e8 = uVar1;
    if ((uVar1 == 0 && DAT_08be83ec == 0) && (DAT_08be8418 != 0)) {
      FUN_08adb8a4(DAT_08be8418);
    }
    uVar1 = DAT_08be83f0 - 1;
    DAT_08be83f4 = (uint)(uVar1 < DAT_08be83f0) + DAT_08be83f4 + -1;
    DAT_08be83f0 = uVar1;
    if ((uVar1 == 0 && DAT_08be83f4 == 0) && (DAT_08be8430 != 0)) {
      FUN_08adb8a4(DAT_08be8430);
    }
    FUN_08a1befc();
    return;
  }
  return;
}

// Primary-profile generated baseline; control flow and temporaries remain unresolved.
// near miss from lane lbp1a (unreviewed)
