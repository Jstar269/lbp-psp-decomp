/* LBPMATCH module=EBOOT.BIN start=0x08859664 end=0x0885968c symbol=FUN_08859664 lang=c99 */
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

extern void FUN_08878d74();

void FUN_08859664(int param_1)
{
  FUN_08878d74(param_1 + -0xc);
  return;
}
// Generated g1 candidate omits adjusting thunk and shared body; 10 words differ.
// near miss from lane lbp14d (unreviewed)
