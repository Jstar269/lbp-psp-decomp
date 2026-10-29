/* LBPMATCH module=EBOOT.BIN start=0x08976bfc end=0x08976c60 symbol=FUN_08976bfc lang=c99 */
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

extern void FUN_08976288();

void FUN_08976bfc(undefined4 *param_1,undefined4 param_2,undefined1 param_3,undefined1 param_4)
{
  FUN_08976288(param_1);
  param_1[4] = param_2;
  *(undefined1 *)(param_1 + 6) = param_3;
  *(undefined1 *)((int)param_1 + 0x1a) = param_4;
  *(undefined2 *)((int)param_1 + 0x1e) = 0;
  param_1[5] = 0;
  *(undefined1 *)((int)param_1 + 0x19) = 0;
  *(undefined2 *)(param_1 + 7) = 0;
  return;
}

// NEAR: 6 differing words; primary and O2 profiles tested.
// near miss from lane lbp5b (unreviewed)
