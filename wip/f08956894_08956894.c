/* LBPMATCH module=EBOOT.BIN start=0x08956894 end=0x089568d0 symbol=FUN_08956894 lang=c99 */
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

extern undefined4 FUN_0894fd30();

void FUN_08956894(int *param_1,undefined4 *param_2)
{
  undefined4 uStack_1c;
  undefined4 uStack_20;
  
  uStack_1c = param_2[1];
  uStack_20 = *param_2;
  FUN_0894fd30(param_1,&uStack_20);
  return;
}
// Generated g13 candidate lacks the adjusting thunk and shared body; 15 words differ.
// near miss from lane lbp14d (unreviewed)
