/* LBPMATCH module=EBOOT.BIN start=0x08965a2c end=0x08965a68 symbol=FUN_08965a2c lang=c99 */
/* Hand-written reconstruction from the disassembly (lane lbp4d, Claude Sonnet 5.5); NEAR MISS, not exact. */
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

extern undefined * DAT_08be8480;

undefined4 FUN_08965a2c(int param_1)
{
  uchar cVar1;
  undefined4 uVar2;
  
  uVar2 = 0x97;
  if (DAT_08be8480 != 0) {
    cVar1 = *(uchar *)(DAT_08be8480 + 4);
    if (*(uchar *)(DAT_08be8480 + 0x18) == '\0') {
      uVar2 = 0x87;
    }
    *(undefined4 *)(param_1 + 4) = uVar2;
    if (cVar1 != '\0') {
      return 1;
    }
  }
  return 0;
}

// 3 words off: retail li a1,0x97/li v1,0x87/movz a1,v1,v0; ours 0x87/0x97/movn (ifcvt picks inverse arm).
// tried: if/else, ternary, !c, struct form, early return, O2 (worse)
// near miss from lane lbp4d (unreviewed)
