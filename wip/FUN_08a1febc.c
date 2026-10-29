/* LBPMATCH module=EBOOT.BIN start=0x08a1febc end=0x08a1ff04 symbol=FUN_08a1febc lang=c99 */
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

extern undefined4 DAT_08bf5dec;
extern undefined4 DAT_08bf5df0;
extern undefined4 DAT_08bf5df4;
extern void FUN_08a9e0cc();

void FUN_08a1febc(void)
{
  if (DAT_08bf5df0 != 0) {
    FUN_08a9e0cc(DAT_08bf5df0);
    DAT_08bf5dec = 0;
    DAT_08bf5df4 = 0;
    DAT_08bf5df0 = 0;
  }
  return;
}

// 3 words differ: global stores and address loads after all six source orders.
// near miss from lane lbp5a (unreviewed)
