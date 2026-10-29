/* LBPMATCH module=EBOOT.BIN start=0x088db88c end=0x088db95c symbol=FUN_088db88c lang=c99 */
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

extern uint FUN_088db550();

undefined4 FUN_088db88c(int param_1,int param_2,int param_3)
{
  uint uVar1;
  uint uVar2;
  undefined4 uVar3;
  int iVar4;
  
  iVar4 = param_2 * 4 + param_1;
  uVar2 = (uint)*(ushort *)(param_3 + 0x7c);
  if (((uVar2 == 0xffff) || (uVar1 = (uint)*(ushort *)(iVar4 + 0x178), uVar2 < uVar1)) ||
     (((uVar1 + *(int *)(iVar4 + 0x168)) - 1 & 0xffff) < uVar2)) {
    uVar2 = FUN_088db550(param_1,param_2,'\0');
    if (uVar2 == 0xffff) {
      return 0;
    }
    uVar2 = uVar2 & 0xffff;
  }
  uVar3 = 0;
  if ((uVar2 != 0xffff) && ((int)uVar2 < *(int *)(param_1 + 0x154))) {
    iVar4 = *(int *)(param_1 + 0x150);
    uVar3 = 1;
    *(short *)(param_3 + 0x7c) = (short)uVar2;
    *(int *)(uVar2 * 0x28 + iVar4 + 8) = param_3;
  }
  return uVar3;
}



// Os 48 words differ; O2 62, branch and register layout unresolved.
// near miss from lane lbp8e (unreviewed)
