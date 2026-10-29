/* LBPMATCH module=EBOOT.BIN start=0x088c25c8 end=0x088c26b0 symbol=FUN_088c25c8 lang=c99 */
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

extern undefined4 DAT_08bee634;
extern undefined4 FUN_088b603c();
extern void FUN_088c2524();
extern undefined4 FUN_088e6190();
extern void FUN_08a2d090();
extern uint FUN_08ad16f0();

void FUN_088c25c8(int *param_1)
{
  bool bVar1;
  bool bVar2;
  uint uVar3;
  int iVar4;
  int *piVar5;
  int iVar6;
  
  FUN_08a2d090(DAT_08bee634);
  if (*(int *)(param_1[5] + 4) == 5) {
    FUN_088e6190(*(int *)((int)param_1 + 20));
  }
  else if (*(int *)(param_1[5] + 4) == 1) {
    FUN_088b603c();
  }
  param_1[7] = 0;
  uVar3 = FUN_08ad16f0();
  bVar2 = false;
  iVar6 = 0;
  param_1[8] = uVar3;
  piVar5 = param_1 + 0x1b;
  while (bVar1 = iVar6 < param_1[0x23], iVar6 = iVar6 + 1, bVar1) {
    iVar4 = *piVar5;
    piVar5 = piVar5 + 1;
    bVar2 = (bool)(bVar2 | iVar4 == 0);
  }
  bVar1 = false;
  if ((((bVar2) && (param_1[0x14] == 0)) && (param_1[0xe] == 0)) &&
     (bVar1 = true, param_1[0x1a] != 0)) {
    bVar1 = false;
  }
  *(bool *)(param_1 + 6) = bVar1;
  if (!bVar1) {
    FUN_088c2524(param_1);
    return;
  }
  return;
}
// NEAR 6 words: gcc404xs-Os: retail hoists the lui of DAT_08bee634 above 'sw s0' in the prologue, puts 'move a1/a0 zero' before 'addiu v1,s0,108' and has 'or a1,a1,v0' (accumulator first); source variants (operand order, statement order, for-loop) did not move them; O2 is far off.
// near miss from lane lbp3b (unreviewed)
