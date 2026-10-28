/* LBPMATCH module=EBOOT.BIN start=0x08b8bf24 end=0x08b8bff4 symbol=FUN_08b8bf24 lang=c99 */
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

extern unsigned char DAT_08bd8b88;
extern void FUN_08b8b9d4();
extern undefined4 * FUN_08b9e7a8();

int * FUN_08b8bf24(int *param_1,undefined4 *param_2)
{
  int iVar1;
  int iVar2;
  undefined4 *puVar3;
  uint uVar4;
  uint uVar5;
  
  puVar3 = (undefined4 *)*param_2;
  uVar4 = puVar3[-3];
  if (uVar4 != 0) {
    iVar2 = *param_1;
    uVar5 = uVar4 + *(int *)(iVar2 + -0xc);
    if ((*(uint *)(iVar2 + -8) < uVar5) || (0 < *(int *)(iVar2 + -4))) {
      FUN_08b8b9d4(param_1,uVar5);
      puVar3 = (undefined4 *)*param_2;
      iVar2 = *param_1;
    }
    iVar1 = *(int *)(iVar2 + -0xc);
    if (uVar4 != 1) {
      FUN_08b9e7a8((undefined4 *)(iVar2 + iVar1),puVar3,uVar4);
    }
    else {
      *(undefined1 *)(iVar2 + iVar1) = *(undefined1 *)puVar3;
    }
    iVar2 = *param_1;
    *(undefined4 *)(iVar2 + -4) = 0;
    *(uint *)(iVar2 + -0xc) = uVar5;
    *(undefined1 *)(iVar2 + uVar5) = DAT_08bd8b88;
  }
  return param_1;
}

// Generated starting point; primary compiler comparison remains unmatched.


// 21 differing words: global terminator and reversed copy branch improved baseline; block placement still differs.
// near miss from lane lbp1c (unreviewed)
