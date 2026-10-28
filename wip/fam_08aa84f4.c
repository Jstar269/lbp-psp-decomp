/* LBPMATCH module=EBOOT.BIN start=0x08aa84f4 end=0x08aa8640 symbol=FUN_08aa84f4 lang=c99 */
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

extern void FUN_08aa5974();
extern void FUN_08aa5cc4();
extern void FUN_08aa83ec();
extern void FUN_08aa84c4();

void FUN_08aa84f4(undefined4 *param_1,uint param_2)
{
  if (param_2 == (param_1[7] & 0x38)) {
    return;
  }
  if (param_2 != 0x10) {
    if (param_2 < 0x11) {
      if (param_2 != 8) {
        return;
      }
      FUN_08aa5cc4((int)param_1);
    }
    else {
      if (param_2 != 0x18) {
        if (param_2 != 0x20) {
          return;
        }
        FUN_08aa5974((int)param_1);
        goto LAB_08aa8620;
      }
      FUN_08aa5cc4((int)param_1);
    }
    FUN_08aa84c4(param_1);
    return;
  }
  FUN_08aa5974((int)param_1);
LAB_08aa8620:
  FUN_08aa83ec(param_1);
  return;
}

// Primary-profile generated baseline; function structure and call arguments need reconstruction.
// near miss from lane lbp1a (unreviewed)
