/* LBPMATCH module=EBOOT.BIN start=0x0888a58c end=0x0888a5c4 symbol=FUN_0888a58c lang=c99 */
/* Hand-written reconstruction from the disassembly (lane lbp6b, Claude Sonnet 5.5); exact match verified; names and types await human review. */
int FUN_0888a58c(int *p)
{
  int r = 0;
  if (p[1] == 0 && p[0] > 1) {
    p[1] = 3;
    p[0] = 1;
    r = 1;
  }
  return r;
}
// statement order: stores written p[1] then p[0] because the scheduler swaps them.
