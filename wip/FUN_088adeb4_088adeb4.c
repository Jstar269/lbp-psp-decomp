/* LBPMATCH module=EBOOT.BIN start=0x088adeb4 end=0x088adf30 symbol=FUN_088adeb4 lang=c99 */
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

extern undefined4 DAT_08be84a0;
extern void FUN_08adbc24();
extern void FUN_08b88fc8();

void FUN_088adeb4(undefined4 *param_1,ushort *param_2)
{
  int *piVar1;
  int *piVar2;
  
  piVar2 = (int *)*param_1;
  while (piVar1 = piVar2, piVar1 != param_1) {
    piVar2 = (int *)*piVar1;
    ushort uVar3 = (ushort)piVar1[2];
    if (uVar3 == *param_2) {
      FUN_08b88fc8(piVar1);
      FUN_08adbc24(DAT_08be84a0,(uint)piVar1,0xc);
    }
  }
  return;
}
// NEAR 1 words: only the operand order of 'bne v1,v0' (retail: node field first, key second) differs; source order, ushort temp and parameter types did not change it. ushort (lhu) already applied.
// near miss from lane lbp3b (unreviewed)
