/* LBPMATCH module=EBOOT.BIN start=0x0880b0f4 end=0x0880b130 symbol=FUN_0880b0f4 lang=c99 */
/* Hand-written reconstruction from the disassembly (lane lbp6d, Claude Sonnet 5.5); exact match verified; names and types await human review. Matching idiom: the last callee is declared to return long long (suppresses the sibling call retail does not have). */
extern int FUN_089ecaa8(void);
extern long long FUN_08829e00(int, int);
struct A { int pad; int p; };
int FUN_0880b0f4(struct A *a)
{
  int p = a->p;
  int r = 0;
  if (p != 0) {
    r = FUN_08829e00(p, FUN_089ecaa8());
  }
  return r;
}
