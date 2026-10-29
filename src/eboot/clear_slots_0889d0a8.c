/* LBPMATCH module=EBOOT.BIN start=0x0889d0a8 end=0x0889d0dc symbol=FUN_0889d0a8 lang=c99 */
/* Hand-written reconstruction from the disassembly (lane lbp4a, Claude Sonnet 5.5); exact match verified; names and types await human review. */
struct S { int pad; int a[50]; int cc; int d0; int d4; };
void FUN_0889d0a8(struct S *p)
{
  int i;
  for (i = 0; i < 50; i++)
    p->a[i] = 0;
  p->d0 = -1;
  p->d4 = 4;
  p->cc = 0;
}
