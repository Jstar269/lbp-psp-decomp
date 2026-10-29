/* LBPMATCH module=EBOOT.BIN start=0x08b8b620 end=0x08b8b670 symbol=FUN_08b8b620 lang=c99 cc=gcc404xs-O2 */
/* Hand-written reconstruction from the disassembly (lane lbp6c, Claude Sonnet 5.5); exact match verified; names and types await human review. */
extern unsigned FUN_08ba0e8c(const char *s);
extern int FUN_08b8b470(void *a, int b, const char *s, unsigned n);

int FUN_08b8b620(void *a, int b, const char *s)
{
  return FUN_08b8b470(a, b, s, FUN_08ba0e8c(s));
}
// NEAR 6: only the prologue store order differs (retail: sw ra, sw s2, move s2,a2, sw s1, ...; ours delays ra). Tried Os, O2, gcc402x/410, c++, void return.
// near miss from lane lbp6c (unreviewed)
