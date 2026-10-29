/* LBPMATCH module=EBOOT.BIN start=0x08a50c98 end=0x08a50ce0 symbol=FUN_08a50c98 lang=c99 */
/* Hand-written reconstruction from the disassembly (lane lbp6b, Claude Sonnet 5.5); exact match verified; names and types await human review. */
extern void *FUN_08adbdb4(void *, int, unsigned);
void FUN_08a50c98(unsigned int *p)
{
  FUN_08adbdb4(p + 1, 0, 0x50);
  p[0x1c] = 0;
  p[0x1b] = 0;
  p[0x18] = 0;
  p[0x19] = 0;
  p[0x1a] = 0;
  *p = 0;
}
// statement order: the scheduler emits the last zero store first, so the retail first store (*p) is written last.
