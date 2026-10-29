/* LBPMATCH module=EBOOT.BIN start=0x08918e8c end=0x08918ebc symbol=FUN_08918e8c lang=c99 */
extern void FUN_08918074(unsigned, int);
void FUN_08918e8c(int p, int ms)
{
  FUN_08918074((unsigned)(ms * 1000) / 30, 0);
}
// NEAR 2 words: retail sll v1,a1,2 / subu a0,a0,v1 (v1) where ours uses v0 for the shift temp; tried int/unsigned param types, temp, 1000u/30u, O2, xi-Os, 402x-Os
// near miss from lane lbp4b (unreviewed)
