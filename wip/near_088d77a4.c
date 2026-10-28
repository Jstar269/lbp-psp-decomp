/* LBPMATCH module=EBOOT.BIN start=0x088d77a4 end=0x088d77fc symbol=FUN_088d77a4 lang=c99 */
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

extern undefined4 FUN_08a50fbc();
extern undefined4 FUN_08a52b38();

void FUN_088d77a4(int param_1,uint param_2)
{
  int iVar1;
  
  iVar1 = FUN_08a50fbc();
  FUN_08a52b38(iVar1,*(uint *)((param_2 & 0xffff) * 0x34 + *(int *)(param_1 + 0x160) + 8));
  return;
}

// Retail has a second 16-bit mask; changing the parameter to ushort did not reproduce it.
// near miss from lane lbp2a (unreviewed)
