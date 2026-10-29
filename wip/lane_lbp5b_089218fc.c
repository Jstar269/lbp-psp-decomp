/* LBPMATCH module=EBOOT.BIN start=0x089218fc end=0x0892194c symbol=FUN_089218fc lang=c99 */
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


void FUN_089218fc(int *param_1,int param_2,int param_3)
{
  (**(code **)(*param_1 + 0xc))();
  param_1[3] = param_3;
  param_1[2] = param_2;
  param_1[1] = param_2;
  return;
}

// NEAR: 5 differing words; primary and O2 profiles tested.
// near miss from lane lbp5b (unreviewed)
