/* LBPMATCH module=EBOOT.BIN start=0x08a7835c end=0x08a783ec symbol=FUN_08a7835c lang=c99 */
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

extern undefined4 DAT_08bf7304;
extern void FUN_0890adc4();
extern void FUN_08911e0c();
extern undefined4 FUN_08a50fbc();

void FUN_08a7835c(int param_1,int param_2)
{
  FUN_08a50fbc();
  if (DAT_08bf7304 != 0) {
    if (*(int *)(param_1 + 0x38c) == param_2) {
      *(undefined4 *)(param_1 + 0x38c) = 0;
      FUN_08911e0c((char *)(param_1 + 0x380));
      return;
    }
    if ((param_2 == *(int *)(param_1 + 0x620)) && (*(char *)(param_1 + 0x641) != '\0')) {
      *(undefined4 *)(param_1 + 0x620) = 0;
      FUN_0890adc4((undefined4 *)(param_1 + 0x400),'\0');
      return;
    }
  }
  return;
}

// Generated starting point; primary compiler comparison remains unmatched.
// Unsigned byte at 0x641 leaves 29 words under Os; O2 experiment is 16 words off and remains in try/lane-work.
// near miss from lane lbp1c (unreviewed)
