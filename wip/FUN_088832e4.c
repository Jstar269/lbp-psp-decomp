/* LBPMATCH module=EBOOT.BIN start=0x088832e4 end=0x08883308 symbol=FUN_088832e4 lang=c99 */
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

extern undefined DAT_08bedfe0;
extern int FUN_08ba0d98();

bool FUN_088832e4(byte *param_1)
{
  int iVar1;
  
  iVar1 = FUN_08ba0d98(param_1,&DAT_08bedfe0);
  return iVar1 == 0;
}



// 4 words differ: instruction scheduling, O2 also differs.
// near miss from lane lbp5a (unreviewed)
