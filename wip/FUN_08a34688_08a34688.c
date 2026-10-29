/* LBPMATCH module=EBOOT.BIN start=0x08a34688 end=0x08a346e0 symbol=FUN_08a34688 lang=c99 cc=gcc404xs-O2 */
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

extern undefined4 FUN_08a50fbc();
extern void FUN_08a51ca4();

undefined4 FUN_08a34688(int *param_1,uchar param_2)
{
  int iVar1;
  undefined4 uVar2;
  
  iVar1 = FUN_08a50fbc();
  FUN_08a51ca4(iVar1,(int)param_1);
  uVar2 = 1;
  if (param_2 != '\0') {
    uVar2 = (**(code **)(*param_1 + 0x78))(param_1);
  }
  return uVar2;
}
// NEAR 15 words: retail does NOT tail-call the virtual call (jalr v0 + nop, epilogue after), ours emits lw t9 / jr t9. Also the O1 profile gets within 14 words. Tried: typed vtable call, O2, O1. Looks like retail never sibcalls an indirect call.
// near miss from lane lbp3b (unreviewed)
