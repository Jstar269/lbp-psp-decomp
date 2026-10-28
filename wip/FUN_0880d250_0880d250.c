/* LBPMATCH module=EBOOT.BIN start=0x0880d250 end=0x0880d314 symbol=FUN_0880d250 lang=c99 cc=gcc404xs-Os */
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
extern undefined4 FUN_08adbb84();
extern void FUN_08b899e4();

int FUN_0880d250(int param_1,int param_2,int param_3,short *param_4)
{
  int *piVar1;
  int iVar2;
  char cVar3;
  
  if ((param_2 != 0) ||
     ((cVar3 = '\x01', param_3 != param_1 + 4 &&
      (cVar3 = '\0', *param_4 < *(short *)(param_3 + 0x10))))) {
    cVar3 = '\x01';
  }
  piVar1 = (int *)FUN_08adbb84(DAT_08be84a0,0x18);
  if ((char *)piVar1 + 0x10 != (char *)0) {
    iVar2 = *(int *)(param_4 + 2);
    piVar1[4] = *(int *)param_4;
    piVar1[5] = iVar2;
  }
  FUN_08b899e4(cVar3,piVar1,param_3,param_1 + 4);
  *(int *)(param_1 + 0x14) = *(int *)(param_1 + 0x14) + 1;
  return (int)piVar1;
}

// best of the profile sweep: cc=gcc404xs-Os, 22 differing words left of 49.
// near miss from lane lbp2c (unreviewed)
