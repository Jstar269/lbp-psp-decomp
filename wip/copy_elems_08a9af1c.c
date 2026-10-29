/* LBPMATCH module=EBOOT.BIN start=0x08a9af1c end=0x08a9afac symbol=FUN_08a9af1c lang=c99 */
/* Hand-written reconstruction from the disassembly (lane lbp6c, Claude Sonnet 5.5); exact match verified; names and types await human review. */
struct Elem { int a; int b; int c; };
struct Tmp { int w[8]; };
extern void FUN_08a9d390(struct Tmp *t, int v);
extern void FUN_08a9bff8(struct Tmp *t);

struct Elem *FUN_08a9af1c(struct Elem *first, struct Elem *last, struct Elem *out)
{
  struct Tmp tmp;
  int n;
  for (n = ((int)((char *)last - (char *)first) >> 2) * -0x55555555; n > 0; n--) {
    FUN_08a9d390(&tmp, first->a);
    FUN_08a9bff8(&tmp);
    int a = first->a, b = first->b, c = first->c;
    out->a = a; out->b = b; out->c = c;
    first++;
    out++;
  }
  return out;
}
// NEAR (41 words vs 36): retail multiplies the exact-division inverse 0xaaaaaaab with mult/mflo (lui/ori+mult), ours expands it into 9 shift/add words (-Os mult cost); the 3-word element copy also schedules loads 4,8,0 instead of 0,4,8. Compiler-cost evidence; not worked around.
// near miss from lane lbp6c (unreviewed)
