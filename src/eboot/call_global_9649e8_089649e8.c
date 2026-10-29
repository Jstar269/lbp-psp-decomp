/* LBPMATCH module=EBOOT.BIN start=0x089649e8 end=0x08964a3c symbol=FUN_089649e8 lang=c99 */
/* Hand-written reconstruction from the disassembly (lane lbp6d, Claude Sonnet 5.5); exact match verified; names and types await human review. Matching idiom: the last callee is declared to return long long (suppresses the sibling call retail does not have). */
extern int *DAT_08be8510;
extern int FUN_08815fdc(int *);
extern long long FUN_0880b6b0(int *, int);
int FUN_089649e8(void)
{
  int *g = DAT_08be8510;
  int r = 0;
  if (g) {
    int v = FUN_08815fdc(g);
    if (v)
      r = FUN_0880b6b0(g, v);
  }
  return r;
}
