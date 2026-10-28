/* LBPMATCH module=EBOOT.BIN start=0x0889ec90 end=0x0889ecf8 symbol=FUN_0889ec90 lang=c99 cc=gcc171-Os */
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

extern undefined DAT_08bee308;
extern undefined DAT_08bee32c;
extern void FUN_0889ebc4();
extern undefined4 FUN_08b8dfd8();
extern void FUN_08b8e050();
extern undefined4 FUN_08b9ca80();
extern void FUN_0889e088();

undefined4 * FUN_0889ec90(void)
{
  int iVar1;
  
  if ((DAT_08bee308 == '\0') && (iVar1 = FUN_08b8dfd8(&DAT_08bee308), iVar1 != 0)) {
    FUN_0889ebc4(&DAT_08bee32c);
    FUN_08b8e050(&DAT_08bee308);
    FUN_08b9ca80(FUN_0889e088);
  }
  return &DAT_08bee32c;
}
// lane lbpt0: 1 word left at gcc171-Os from lbpgen g10: retail tests the guard byte with lb (signed char), ours lbu.
// This is a C++ function-local static (guard __cxa_guard_acquire 0x08b8dfd8 / release 0x08b8e050, atexit 0x08b9ca80 with
// the destructor wrapper 0x0889e088); the faithful source is 'static T obj; return &obj;' at gcc404xs-Os, untried.
// near miss from lane lbpt0 (unreviewed)
