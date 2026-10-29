/* LBPMATCH module=EBOOT.BIN start=0x08825e34 end=0x08825f20 symbol=FUN_08825e34 lang=c99 rodata=0x08bab5c8 */
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


typedef struct { float x, low, high, step; } State;
undefined4 FUN_08825e34(State *param_1,float *param_2,uint param_3)
{
  undefined4 uVar1;
  float fVar2;
  
  uVar1 = 0;
  if (*param_2 < param_1->high) {
    fVar2 = *param_2 + param_1->step * (float)param_3;
    *param_2 = fVar2;
    if (param_1->low > fVar2) {
      fVar2 = param_1->low;
    }
    *param_2 = fVar2;
    if (fVar2 > param_1->high) {
      fVar2 = param_1->high;
    }
    *param_2 = fVar2;
    fVar2 = (float)(int)((fVar2 - param_1->low) / param_1->step + 0.5f) *
            param_1->step + param_1->low;
    *param_2 = fVar2;
    if (param_1->low > fVar2) {
      fVar2 = param_1->low;
    }
    *param_2 = fVar2;
    if (fVar2 > param_1->high) {
      fVar2 = param_1->high;
    }
    *param_2 = fVar2;
    uVar1 = 1;
  }
  return uVar1;
}

// 52 words differ: FP compare and scheduling; struct fields and strict comparisons tried.
// near miss from lane lbp5a (unreviewed)
