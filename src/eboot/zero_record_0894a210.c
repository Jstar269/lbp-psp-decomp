/* LBPMATCH module=EBOOT.BIN start=0x0894a210 end=0x0894a250 symbol=FUN_0894a210 lang=c99 */
/* Hand-written reconstruction from the disassembly (lane lbp6c, Claude Sonnet 5.5); exact match verified; names and types await human review. */
extern void *memset(void *p, int v, unsigned n);
struct Rec { int a; int b; int c; int d; char kind; char pad[0x94 - 17]; };
void FUN_0894a210(struct Rec *r)
{
  memset(r, 0, sizeof(struct Rec));
  r->a = -2;
  r->b = 2;
  r->kind = 2;
}
