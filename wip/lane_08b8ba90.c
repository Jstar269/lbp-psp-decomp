/* LBPMATCH module=EBOOT.BIN start=0x08b8ba90 end=0x08b8bb20 symbol=FUN_08b8ba90 lang=c99 */
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

extern void FUN_08b8b9d4();
extern char DAT_08bd8b88;

void FUN_08b8ba90(int *param_1,signed char param_2)
{
  int iVar1;
  int iVar2;
  uint uVar3;
  
  iVar2 = *param_1;
  uVar3 = *(int *)(iVar2 + -0xc) + 1;
  if ((*(uint *)(iVar2 + -8) < uVar3) || (0 < *(int *)(iVar2 + -4))) {
    FUN_08b8b9d4(param_1,uVar3);
    iVar2 = *param_1;
  }
  iVar1 = *(int *)(iVar2 + -0xc);
  *(undefined1 *)(iVar2 + iVar1) = param_2;
  iVar2 = *param_1;
  *(undefined4 *)(iVar2 + -4) = 0;
  *(uint *)(iVar2 + -0xc) = uVar3;
  *(undefined1 *)(iVar2 + uVar3) = DAT_08bd8b88;
  return;
}

// Generated starting point; primary compiler comparison remains unmatched.

// Signed byte argument and address-named terminator global reduce mismatch to 15 words; prologue and final scheduling differ.
// near miss from lane lbp1c (unreviewed)
