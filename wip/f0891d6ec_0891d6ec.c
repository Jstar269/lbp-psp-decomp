/* LBPMATCH module=EBOOT.BIN start=0x0891d6ec end=0x0891d730 symbol=FUN_0891d6ec lang=c99 cc=gcc404xs-Os */
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


undefined4 FUN_0891d6ec(int *param_1,undefined4 param_2,undefined4 *param_3,undefined4 param_4,uchar param_5)
{
  if (param_5 == '\0') {
    (**(code **)(*param_1 + 0x14))(param_1,param_3);
  }
  else {
    *(undefined1 *)(param_1 + 4) = 1;
    *param_3 = 0;
  }
  return 1;
}
// Generated candidate differs 14 words and is one word longer; virtual call and fifth argument need C++ reconstruction.
// near miss from lane lbp14d (unreviewed)
