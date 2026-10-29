/* LBPMATCH module=EBOOT.BIN start=0x08896944 end=0x088969e4 symbol=FUN_08896944 lang=c99 */
/* Hand-written reconstruction from the disassembly (lane lbp10a, Claude Sonnet 5.5); exact match verified; names and types await human review. */
typedef struct W5 { int w[5]; } W5;

extern void FUN_0888b8c4(char *lock);
extern void FUN_0888b8cc(char *lock);
extern void FUN_0889689c(char *self, W5 *arg, int flags);

void FUN_08896944(char *self, const void *src, int flags)
{
  W5 tmp;
  FUN_0888b8c4(self + 0x2c);
  __builtin_memcpy(&tmp, src, 20);
  FUN_0889689c(self, &tmp, flags);
  FUN_0888b8cc(self + 0x2c);
}
// NEAR: 9 words differ: same instructions, scheduling only. Retail loads lwr in order 4,8,16,12,0 and stores word 0 (sw v0,0(sp)) in the jal delay slot; ours lwr 0,4,16,8,12 with the sp+0 store first.
// Tried: -O2, struct assign from W5 pointer, copy before the lock call, union char[20]/W5 temp.
// near miss from lane lbp10a (unreviewed)
