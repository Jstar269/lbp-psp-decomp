/* LBPMATCH module=EBOOT.BIN start=0x0889e504 end=0x0889e574 symbol=FUN_0889e504 lang=c99 */
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

extern void FUN_0889d408();
extern void FUN_0889d530();
extern void FUN_0889dd04();
extern void FUN_0889df18();
extern void FUN_0889e4c8();

void FUN_0889e504(int *param_1,uint param_2)
{
  undefined4 local_20 [4];
  
  FUN_0889df18(param_1);
  param_1[7] = param_2;
  FUN_0889dd04(param_1 + 9,param_2);
  FUN_0889d530(param_1 + 0xc,param_1[7]);
  FUN_0889d408(param_1 + 0xf,param_1[7]);
  local_20[0] = 0;
  FUN_0889e4c8(param_1 + 0xf,param_1[7],local_20);
  return;
}


// 12 differing words: register allocation; passing unused second argument matches bytes but is not supported by callee and was rejected.
// near miss from lane lbp5a (unreviewed)
