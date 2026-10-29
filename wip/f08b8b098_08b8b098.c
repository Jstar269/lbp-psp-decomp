/* LBPMATCH module=EBOOT.BIN start=0x08b8b098 end=0x08b8b0d8 symbol=FUN_08b8b098 lang=c99 cc=gcc410-Os */
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

extern int * FUN_08b8af8c();
extern int FUN_08ba0e8c();

void FUN_08b8b098(int *param_1,undefined1 *param_2)
{
  uint uVar1;
  
  uVar1 = FUN_08ba0e8c(param_2);
  FUN_08b8af8c(param_1,param_2,uVar1);
  return;
}



// Six words differ in prologue scheduling; primary Os and O2 produce the same mismatch.
// near miss from lane lbp13b (unreviewed)
