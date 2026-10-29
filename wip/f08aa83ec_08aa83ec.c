/* LBPMATCH module=EBOOT.BIN start=0x08aa83ec end=0x08aa841c symbol=FUN_08aa83ec lang=c99 */
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

extern void FUN_08aa8374();

void FUN_08aa83ec(undefined4 *param_1)
{
  if (param_1 != (undefined4 *)0x0) {
    FUN_08aa8374(param_1,param_1[4],param_1[5],param_1[6],param_1[8]);
    return;
  }
  return;
}

// 12 words differ: compiler moves null test before argument loads, as in 0x08aa7954.
// near miss from lane lbp14b (unreviewed)
