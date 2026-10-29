/* LBPMATCH module=EBOOT.BIN start=0x0880fb20 end=0x0880fb50 symbol=FUN_0880fb20 lang=c99 */
struct B { char pad[0x6c]; unsigned char f6c; char pad2[0x2b7-0x6d]; unsigned char f2b7; };
struct A { int x; struct B *b; };
void FUN_0880fb20(struct A *p)
{
  struct B *b = p->b;
  if (b != 0 && b->f6c == 0 && b->f2b7 == 0)
    b->f2b7 = 1;
}
// NEAR 2 words: first test loads into v0, retail uses a0 (dead param) for lbu 108(v1)/bnez; tried nested ifs, early returns, C++ inline members, O2, repeated p->b
// near miss from lane lbp4b (unreviewed)
