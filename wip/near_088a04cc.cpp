/* LBPMATCH module=EBOOT.BIN start=0x088a04cc end=0x088a0560 symbol=FUN_088a04cc lang=c++ */
typedef unsigned char undefined;
typedef unsigned char byte;
typedef unsigned short ushort;
typedef unsigned int uint;
typedef unsigned long long ulonglong;
typedef long long longlong;
typedef unsigned char uchar;
typedef unsigned long long undefined8;
typedef int code(...);
#define ABS(x) ((x) < 0 ? -(x) : (x))
typedef unsigned char undefined1;
typedef unsigned short undefined2;
typedef unsigned int undefined4;

extern "C" {
extern char DAT_08bee308;
extern undefined DAT_08bee32c;
extern undefined4 DAT_08bee374;
extern void FUN_0889ebc4(...);
extern undefined4 FUN_08b8dfd8(...);
extern void FUN_08b8e050(...);
extern undefined4 FUN_08b9ca80(...);
extern void FUN_0889e088(...);
}
struct VC_0 { virtual void d0(); virtual void d1(); virtual void d2(); virtual void m(); };

extern "C" void FUN_088a04cc(undefined4 param_1,int *param_2)
{
  int iVar1;
  
  if ((DAT_08bee308 == '\0') && (iVar1 = FUN_08b8dfd8(&DAT_08bee308), iVar1 != 0)) {
    FUN_0889ebc4(&DAT_08bee32c);
    FUN_08b8e050(&DAT_08bee308);
    FUN_08b9ca80(FUN_0889e088);
  }
  if (*param_2 != 0) {
    ((VC_0 *)(DAT_08bee374))->m();
    *param_2 = 0;
  }
  return;
}
// NEAR: guard byte char (lb) and vtable slot 3 (offset 12) fixed; remaining: retail hi-part v0 feeds 'lb v1' and 'addiu s0,v0' with 'move s1,a1' after the lui (a real C++ function-local static: guard loaded from the symbol, &guard CSE'd into s0); ours loads the guard through s0. Faithful form is 'static T obj;' but __tcf (atexit wrapper 0x0889e088) is not reproducible in this TU. Tried local pointer to guard, nested if.
// near miss from lane lbp4c (unreviewed)
