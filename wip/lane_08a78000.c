/* LBPMATCH module=EBOOT.BIN start=0x08a78000 end=0x08a780fc symbol=FUN_08a78000 lang=c99 */
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

extern int DAT_08be8510;
extern void FUN_0880f498();
extern undefined4 FUN_0890aa88();
extern void FUN_0890adc4();
extern void FUN_0890e2a0();
extern void FUN_0890e320();
extern void FUN_08911e0c();
extern undefined4 FUN_08a68fd4();
extern void FUN_08a69114();

void FUN_08a78000(int param_1,uchar param_2)
{
  int iVar1;
  int *piVar2;
  
  if (*(uchar *)(param_1 + 0x380) != '\0') {
    FUN_08911e0c((uchar *)(param_1 + 0x380));
  }
  if (param_2 == '\0') {
    iVar1 = FUN_0890aa88(param_1 + 0x2e0);
    if (iVar1 != 0) {
      *(undefined1 *)(param_1 + 0x6b1) = 0;
      FUN_0890e2a0(param_1 + 0x394);
      piVar2 = (int *)FUN_08a68fd4();
      FUN_08a69114(piVar2,'\0');
      iVar1 = DAT_08be8510;
      *(undefined4 *)(param_1 + 0x6b8) = 0x3e800000;
      FUN_0880f498(iVar1);
      return;
    }
  }
  else if (*(float *)(param_1 + 0x6b8) <= 0.0f) {
    *(undefined1 *)(param_1 + 0x6b1) = 1;
    FUN_0890e320(param_1 + 0x394,2);
    piVar2 = (int *)FUN_08a68fd4();
    FUN_08a69114(piVar2,'\x01');
    FUN_0890adc4((undefined4 *)(param_1 + 0x400),'\0');
    return;
  }
  return;
}

// Generated starting point; primary compiler comparison remains unmatched.
// gcc404xs-O2 plus DAT_08babd20 yields EXACT in try/lane-work/revisit_08a78000.c; batch hint is Os, so not installed pending review.
// near miss from lane lbp1c (unreviewed)
