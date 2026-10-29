/* LBPMATCH module=EBOOT.BIN start=0x0888cff0 end=0x0888d04c symbol=FUN_0888cff0 lang=c99 */
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

extern int FUN_08843570();
extern undefined4 FUN_0888cf30();

void FUN_0888cff0(int param_1,char *param_2,int param_3)
{
  char *pcVar1;
  int iVar2;
  
  iVar2 = *(int *)(param_1 + 0x4c);
  if (iVar2 == param_1 + 0x2c) {
    iVar2 = 0;
  }
  pcVar1 = (char *)FUN_08843570(param_1);
  FUN_0888cf30(pcVar1,iVar2,param_2,param_3);
  return;
}

// 12 words differ: register allocation, load base and tail call; callee returns int.
// near miss from lane lbp5a (unreviewed)
