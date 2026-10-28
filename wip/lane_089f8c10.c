/* LBPMATCH module=EBOOT.BIN start=0x089f8c10 end=0x089f8cc4 symbol=FUN_089f8c10 lang=c99 */
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
typedef float undefined4;

extern int FUN_089ed768();
extern void FUN_08a05de8();

void FUN_089f8c10(int param_1,int param_2,int param_3,uint *param_4,int param_5,int param_6)
{
  int uVar1;
  float fVar2;
  
  *(undefined4 *)(param_3 + 0xd4) = 0;
  *(float *)(param_3 + 0xd0) = -*(float *)(param_5 + 0x18);
  if (param_6 == 0) {
    param_6 = FUN_089ed768(*(int *)(param_5 + 0x14));
  }
  uVar1 = *(int *)(param_5 + 0x14);
  *(undefined4 *)(param_3 + 0xbc) = *(undefined4 *)(param_6 + 4);
  fVar2 = *(float *)(param_6 + 0x10);
  *(int *)(param_3 + 0xd8) = uVar1;
  *(float *)(param_3 + 0xc0) = fVar2;
  if ((0.0f < fVar2) && ((*param_4 & 0x40) == 0)) {
    param_4[0x2d] = param_4[0x2d] | 1;
  }
  FUN_08a05de8(param_2,param_3);
  return;
}

// Generated starting point; primary compiler comparison remains unmatched.
// 31 differing words: corrected integer argument ABI and callee return type; remaining block layout puts null fallback inline.
// near miss from lane lbp1c (unreviewed)
