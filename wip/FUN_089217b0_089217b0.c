/* LBPMATCH module=EBOOT.BIN start=0x089217b0 end=0x08921858 symbol=FUN_089217b0 lang=c99 cc=gcc171-Os */
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

extern int FUN_08a9e4a4();
extern uint * FUN_08b9eb88();

void FUN_089217b0(int *param_1,int param_2,uchar param_3)
{
  int iVar1;
  
  (**(code **)(*param_1 + 0xc))();
  param_1[3] = param_2;
  if (param_2 != 0) {
    if ((code *)param_1[5] == (code *)0x0) {
      iVar1 = FUN_08a9e4a4(param_2,0,0);
      param_1[2] = iVar1;
    }
    else {
      iVar1 = (*(code *)param_1[5])(param_2);
      param_1[2] = iVar1;
    }
    param_1[1] = iVar1;
    if (param_3 != '\0') {
      FUN_08b9eb88((uint *)param_1[1],0,param_1[3]);
      return;
    }
  }
  return;
}

// best of the profile sweep: cc=gcc171-Os, 21 differing words left of 42.
// near miss from lane lbp2c (unreviewed)
