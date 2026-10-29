/* LBPMATCH module=EBOOT.BIN start=0x0889fad8 end=0x0889fbc8 symbol=FUN_0889fad8 lang=c99 */
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

extern undefined DAT_08bb1e24;
extern undefined DAT_08bb1e40;
extern undefined DAT_08bee308;
extern undefined DAT_08bee32c;
extern undefined4 DAT_08bee338;
extern undefined2 DAT_08bee342;
extern undefined DAT_08bee343;
extern undefined4 DAT_08bee34c;
extern void FUN_0889a8d0();
extern void FUN_0889ebc4();
extern undefined4 FUN_08b8dfd8();
extern void FUN_08b8e050();
extern undefined4 FUN_08b9ca80();
extern void FUN_0889e088();

void FUN_0889fad8(int *param_1,int param_2)
{
  int iVar1;
  
  if ((DAT_08bee308 == '\0') && (iVar1 = FUN_08b8dfd8(&DAT_08bee308), iVar1 != 0)) {
    FUN_0889ebc4(&DAT_08bee32c);
    FUN_08b8e050(&DAT_08bee308);
    FUN_08b9ca80(FUN_0889e088);
  }
  if (*(int *)(*param_1 + 0x10) == 0) {
    FUN_0889a8d0(&DAT_08bb1e24,(int)param_2 + 12);
    FUN_0889a8d0(&DAT_08bb1e40,*(int *)((int)param_2 + 8));
    DAT_08bee338 = *(undefined4 *)(param_2 + 8);
  }
  else if (*(int *)(*param_1 + 0x10) == -0x7ffeffed) {
    DAT_08bee343 = 1;
  }
  else {
    DAT_08bee343 = 0;
  }
  DAT_08bee342 = 1;
  DAT_08bee34c = 0;
  return;
}

// 58 differing words; guarded local static requires C++ reconstruction.
// near miss from lane lbp7a (unreviewed)
