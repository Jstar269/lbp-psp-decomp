/* LBPMATCH module=EBOOT.BIN start=0x0883d5c4 end=0x0883d698 symbol=FUN_0883d5c4 lang=c99 */
/* Hand-written reconstruction from the disassembly (lane lbp10a, Claude Sonnet 5.5); exact match verified; names and types await human review. Unaligned 8 bytes copied by struct assignment of a char[8] struct member (lwl/lwr + swl/swr). */
typedef struct Ref { char pad0[8]; int count; char pad1[8]; char lock[1]; } Ref;
typedef struct T8 { char b[8]; } T8;
typedef struct Elem { int a, b, c, d; Ref *ref; T8 tail; } Elem;

extern void FUN_08ad3088(char *lock);
extern void FUN_08ad2810(char *lock);

Elem *FUN_0883d5c4(Elem *first, Elem *last, Elem *dest)
{
  for (; first != last; first++, dest++) {
    if (dest) {
      dest->a = first->a;
      dest->b = first->b;
      dest->c = first->c;
      dest->d = first->d;
      Ref *r = first->ref;
      dest->ref = r;
      if (r) {
        FUN_08ad3088(r->lock);
        r->count++;
        FUN_08ad2810(r->lock);
      }
      dest->tail = first->tail;
    }
  }
  return dest;
}
