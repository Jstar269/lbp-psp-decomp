/* LBPMATCH module=EBOOT.BIN start=0x0899c290 end=0x0899c2d8 symbol=FUN_0899c290 lang=c99 */
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

extern undefined DAT_08bf0d50;
extern undefined DAT_08bf0d54;

undefined4 * FUN_0899c290(int param_1)
{
  int iVar1;
  int iVar2;
  
  iVar1 = 0;
  iVar2 = 0;
  do {
    iVar1 = iVar1 + 1;
    if (param_1 == *(int *)((int)&DAT_08bf0d54 + iVar2)) {
      return (undefined4 *)((int)&DAT_08bf0d50 + iVar2);
    }
    iVar2 = iVar1 * 0x10;
  } while (iVar1 != 9);
  return &DAT_08bf0d50;
}
// NEAR (11 words): retail does NOT strength-reduce the loop (sll a1,i,4 each iteration, a3 = base+4 kept); ours always reduces (pointer bump). Tried struct array, byte-offset form, do/while, O2, unsigned i.
// near miss from lane lbp6b (unreviewed)
