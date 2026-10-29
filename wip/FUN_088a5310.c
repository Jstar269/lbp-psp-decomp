/* LBPMATCH module=EBOOT.BIN start=0x088a5310 end=0x088a53b8 symbol=FUN_088a5310 lang=c99 */
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

extern signed char DAT_08bee308;
extern undefined DAT_08bee32c;
extern undefined4 DAT_08bee34c;
extern unsigned char DAT_08bee3ac;
extern void FUN_0889ebc4();
extern void FUN_088a3314();
extern void FUN_088a4e20();
extern undefined4 FUN_08b8dfd8();
extern void FUN_08b8e050();
extern undefined4 FUN_08b9ca80();
extern void FUN_088a1164();

void FUN_088a5310(int param_1)
{
  int iVar1;
  
  DAT_08bee3ac = 1;
  if ((DAT_08bee308 == '\0') && (iVar1 = FUN_08b8dfd8(&DAT_08bee308), iVar1 != 0)) {
    FUN_0889ebc4(&DAT_08bee32c);
    FUN_08b8e050(&DAT_08bee308);
    FUN_08b9ca80(FUN_088a1164);
  }
  if (DAT_08bee34c == 1) {
    *(undefined1 *)(param_1 + 0x148) = 1;
  }
  else {
    FUN_088a4e20(param_1);
  }
  *(undefined4 *)(param_1 + 0x138) = 8;
  FUN_088a3314(param_1);
  return;
}


// 36 words differ: signed guard and byte flag corrected; likely needs genuine C++ local static guard.
// near miss from lane lbp5a (unreviewed)
