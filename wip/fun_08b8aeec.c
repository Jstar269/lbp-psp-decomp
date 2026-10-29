/* LBPMATCH module=EBOOT.BIN start=0x08b8aeec end=0x08b8af8c symbol=FUN_08b8aeec lang=c99 cc=gcc404xs-O2 */
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

extern void FUN_08b8ad1c();
extern undefined4 * FUN_08b9e7a8();

int * FUN_08b8aeec(int *param_1,int param_2,int param_3,undefined1 *param_4,int param_5)
{
  FUN_08b8ad1c(param_1,param_2,param_3,param_5);
  if (param_5 != 0) {
    if (param_5 == 1) {
      *(undefined1 *)(*param_1 + param_2) = *param_4;
      return param_1;
    }
    FUN_08b9e7a8((undefined4 *)(*param_1 + param_2),(undefined4 *)param_4,param_5);
  }
  return param_1;
}


// O2 26 differing words: register allocation and conditional copy scheduling; Os 31.
// near miss from lane lbp8e (unreviewed)
