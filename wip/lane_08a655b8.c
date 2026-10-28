/* LBPMATCH module=EBOOT.BIN start=0x08a655b8 end=0x08a65658 symbol=FUN_08a655b8 lang=c99 */
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

extern undefined * DAT_08bf6c5c;
extern undefined4 DAT_08bf7304;
extern undefined4 FUN_08a50fbc();
extern void FUN_08a5d294();
extern void FUN_08a7e614();

void FUN_08a655b8(int param_1)
{
  if (*(uchar *)(param_1 + 0x24f) != '\0') {
    *(undefined1 *)(param_1 + 0x268) = 1;
  }
  if (((*(uint *)(param_1 + 0x2b0) & 1) != 0) && (*(uchar *)(param_1 + 0x24d) != '\0')) {
    if (*(int *)(DAT_08bf6c5c + 0x98) == 2) {
      FUN_08a5d294(DAT_08bf6c5c,'\0');
    }
    FUN_08a50fbc();
    if (DAT_08bf7304 != 0) {
      FUN_08a7e614(DAT_08bf7304,'\x01','\0');
    }
    *(undefined1 *)(param_1 + 0x24d) = 0;
  }
  return;
}

// Generated starting point; primary compiler comparison remains unmatched.
// Revisited: explicit pointer and zero arguments to the second call increased mismatch to 39; 26 remains best. Retail branches the special case out of line.
// near miss from lane lbp1c (unreviewed)
