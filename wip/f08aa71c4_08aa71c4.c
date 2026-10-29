/* LBPMATCH module=EBOOT.BIN start=0x08aa71c4 end=0x08aa723c symbol=FUN_08aa71c4 lang=c99 */
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

extern void FUN_08aa53c4();
extern void FUN_08aa716c();

void FUN_08aa71c4(undefined4 *param_1,uint param_2)
{
  uint uVar1;
  
  if (param_2 == (param_1[7] & 0x38)) {
    return;
  }
  if (param_2 != 0x10) {
    if (param_2 < 0x11) {
      uVar1 = 8;
    }
    else {
      uVar1 = 0x20;
      if (param_2 == 0x18) goto LAB_08aa720c;
    }
    if (param_2 != uVar1) {
      return;
    }
  }
LAB_08aa720c:
  FUN_08aa53c4((int)param_1,0);
  FUN_08aa716c(param_1);
  return;
}

// 21 words differ; natural switch creates bit-test layout, generated conditional form is closer.
// near miss from lane lbp13b (unreviewed)
