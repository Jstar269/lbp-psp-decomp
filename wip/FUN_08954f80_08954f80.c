/* LBPMATCH module=EBOOT.BIN start=0x08954f80 end=0x08954fbc symbol=FUN_08954f80 lang=c99 cc=gcc404xs-O2 */
/* Ghidra pseudocode (lbpgen.py tag gen) corrected by hand (lane lbp3b, Claude Sonnet 5.5): see trailing notes; NOT exact. */
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

extern undefined4 DAT_08befa14;
extern undefined4 FUN_0894fccc();

undefined4 FUN_08954f80(int *param_1,int param_2)
{
  undefined4 uVar1;
  
  uVar1 = 0;
  if (*param_1 == 0x30313056) {
    DAT_08befa14 = *param_1;
    uVar1 = FUN_0894fccc((int)param_1,param_2);
  }
  return uVar1;
}
// NEAR 11 words: retail does not tail-call the direct jal 0x894fccc either (result kept in a3, 'move v0,a3' after the epilogue loads); ours emits j. O1 gets 17 words off (re-materialises the 0x30313056 constant). Tried O1, O2.
// near miss from lane lbp3b (unreviewed)
