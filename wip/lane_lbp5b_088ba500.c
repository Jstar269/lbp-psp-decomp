/* LBPMATCH module=EBOOT.BIN start=0x088ba500 end=0x088ba5c4 symbol=FUN_088ba500 lang=c99 */
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

extern undefined4 DAT_08be84a0;
extern void FUN_088b7a6c();
extern undefined4 FUN_08adbb84();
extern void FUN_08b899e4();

int FUN_088ba500(int param_1,int param_2,int param_3,uint *param_4)
{
  int *piVar1;
  char cVar2;
  
  if ((param_2 != 0) ||
     ((cVar2 = '\x01', param_3 != param_1 + 4 &&
      (cVar2 = '\0', *param_4 < *(uint *)(param_3 + 0x10))))) {
    cVar2 = '\x01';
  }
  piVar1 = (int *)FUN_08adbb84(DAT_08be84a0,0x20);
  if ((char *)piVar1 + 0x10 != (char *)0) {
    piVar1[4] = *param_4;
    FUN_088b7a6c(piVar1 + 5,(int *)(param_4 + 1));
  }
  FUN_08b899e4(cVar2,piVar1,param_3,param_1 + 4);
  *(int *)(param_1 + 0x14) = *(int *)(param_1 + 0x14) + 1;
  return (int)piVar1;
}

// NEAR: 21 differing words; primary and O2 profiles tested.
// near miss from lane lbp5b (unreviewed)
