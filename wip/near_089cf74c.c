/* LBPMATCH module=EBOOT.BIN start=0x089cf74c end=0x089cf7a0 symbol=FUN_089cf74c lang=c99 */
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

extern void FUN_089cd9f8(float param_1,float param_2,float param_3,float param_4,int param_5);

void FUN_089cf74c(int param_1,uint param_2)
{
  if ((param_2 & 0x20) != 0) {
    FUN_089cd9f8(0.0f,0.0f,(float)(int)*(short *)(param_1 + 0x10) /
                         (float)(int)*(short *)(param_1 + 0x34),
                 (float)(int)*(short *)(param_1 + 0x12) / (float)(int)*(short *)(param_1 + 0x36),
                 param_1);
    return;
  }
  return;
}
// NEAR: float order only: retail does mtc1 f1(52) before cvt f0(18) and cvt f14 before div f15; ours differs in four words of cvt/div interleave. Tried locals in all 24 load orders x 2 division orders (48 compiles), no change.
// near miss from lane lbp4c (unreviewed)
