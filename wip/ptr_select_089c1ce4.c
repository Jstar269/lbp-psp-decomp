/* LBPMATCH module=EBOOT.BIN start=0x089c1ce4 end=0x089c1d44 symbol=FUN_089c1ce4 lang=c99 */
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

extern undefined DAT_08bbeef8;
extern undefined DAT_08bc0fc8;
extern undefined * DAT_08bedb54;
extern undefined4 FUN_0891d6e4();
extern void FUN_089dcfac();
extern uint FUN_08adbd60();

void FUN_089c1ce4(int param_1)
{
  int iVar1;
  uint uVar2;
  byte *pbVar3;
  
  iVar1 = FUN_0891d6e4(*(undefined4 **)(*(int *)(DAT_08bedb54 + 8) + 0xa8));
  pbVar3 = (byte *)&DAT_08bbeef8;
  if ((*(byte *)(iVar1 + 0xc) & 1) != 0) {
    pbVar3 = &DAT_08bc0fc8;
  }
  uVar2 = FUN_08adbd60(pbVar3);
  FUN_089dcfac(param_1,~uVar2);
  return;
}

// 5 words off: branch polarity/delay-slot arm: retail beqz with the pointer DAT_08bbeef8 in the delay slot and DAT_08bc0fc8 on the fallthrough; ours bnez with fc8 in the delay slot.
// tried if/else, init-then-override, inverted init, ternary-free forms
// near miss from lane lbp4d (unreviewed)
