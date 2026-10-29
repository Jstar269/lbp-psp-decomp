/* LBPMATCH module=EBOOT.BIN start=0x08b8bff4 end=0x08b8c088 symbol=FUN_08b8bff4 lang=c99 cc=gcc404xs-O2 */
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
typedef signed char undefined1;
typedef short undefined2;
typedef int undefined4;

extern char DAT_08be8b88;
extern void FUN_08b8b9d4();

int * FUN_08b8bff4(int *param_1,undefined1 param_2)
{
  int iVar1;
  int iVar2;
  uint uVar3;
  
  iVar2 = *param_1;
  iVar1 = *(int *)(iVar2 + -0xc);
  uVar3 = iVar1 + 1;
  if ((*(uint *)(iVar2 + -8) < uVar3) || (0 < *(int *)(iVar2 + -4))) {
    FUN_08b8b9d4(param_1,uVar3);
    iVar2 = *param_1;
    iVar1 = *(int *)(iVar2 + -0xc);
  }
  *(undefined1 *)(iVar2 + iVar1) = param_2;
  iVar1 = *param_1;
  *(undefined4 *)(iVar1 + -4) = 0;
  *(uint *)(iVar1 + -0xc) = uVar3;
  *(undefined1 *)(iVar1 + uVar3) = DAT_08be8b88;
  return param_1;
}


// O2 18 words differ from register allocation; restored global terminator source.
// near miss from lane lbp8e (unreviewed)
