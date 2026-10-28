/* LBPMATCH module=EBOOT.BIN start=0x08950d5c end=0x08950d94 symbol=FUN_08950d5c lang=c99 */
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

extern undefined4 FUN_0894fccc();

undefined4 FUN_08950d5c(int *param_1,int param_2)
{
  undefined4 uVar1;
  
  uVar1 = 0;
  if (*param_1 == 0x30414d43) {
    uVar1 = FUN_0894fccc((int)param_1,param_2);
  }
  return uVar1;
}

// Primary profile initial candidate: 12 differing words; disassembly and diff retained in try/lane-work.
// near miss from lane lbp1b (unreviewed)
