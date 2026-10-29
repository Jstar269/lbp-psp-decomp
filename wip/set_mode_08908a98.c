/* LBPMATCH module=EBOOT.BIN start=0x08908a98 end=0x08908ae4 symbol=FUN_08908a98 lang=c99 */
/* Hand-written reconstruction from the disassembly (lane lbp6d, Claude Sonnet 5.5); exact match verified; names and types await human review. */
extern void FUN_089757c0(int);
extern void FUN_0899e554(int, int);
void FUN_08908a98(int o, int m){ int v = 2; if (m != 2) v = 1; if (m == 0) { FUN_089757c0(19); v = 0; } FUN_0899e554(o, v); }
// NEAR 15 words: same length (19) but ours jump-threads m==2 past the m==0 test (beq/bnez); retail first computes v=(m!=2)?1:2 with movn, then bnez a1 for the call path.
// Tried: ?: forms, unsigned, O2, !m. FUN_0899e554(a0,a1) is a setter (sw a1,8(a0)).
// near miss from lane lbp6d (unreviewed)
