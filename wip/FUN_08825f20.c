/* LBPMATCH module=EBOOT.BIN start=0x08825f20 end=0x0882600c symbol=FUN_08825f20 lang=c99 cc=gcc171-Os rodata=0x08bab5c8 */
/* Hand-written reconstruction from the disassembly (lane lbp6a, Claude Sonnet 5.5); exact match verified; names and types await human review. */
typedef unsigned int uint;
typedef struct { float x, low, high, step; } State;
int FUN_08825f20(State *param_1,float *param_2,uint param_3)
{
  int ret = 0;
  float f;
  if (*param_2 > param_1->low) {
    f = *param_2 - param_1->step * (float)param_3;
    *param_2 = f;
    if (!(param_1->low < f)) f = param_1->low;
    *param_2 = f;
    if (!(f < param_1->high)) f = param_1->high;
    *param_2 = f;
    f = (float)(int)((f - param_1->low) / param_1->step + 0.5f) * param_1->step + param_1->low;
    *param_2 = f;
    if (!(param_1->low < f)) f = param_1->low;
    *param_2 = f;
    if (!(f < param_1->high)) f = param_1->high;
    *param_2 = f;
    ret = 1;
  }
  return ret;
}
// 5 words differ: the uint->float expansion (bltz a2): retail has mtc1 in the bltz delay slot and the srl/andi/or path at the branch target; ours puts srl in the slot and mtc1 after.
// Needed gcc171-Os (Sony-era); fixed with !(low < f) forms, *param_2 > low first. Tried: operand order, float temp, split store, inline u2f, gcc171-O2/O1.
// near miss from lane lbp6a (unreviewed)
