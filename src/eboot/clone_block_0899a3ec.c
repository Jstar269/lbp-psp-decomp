/* LBPMATCH module=EBOOT.BIN start=0x0899a3ec end=0x0899a494 symbol=FUN_0899a3ec lang=c99 */
/* Hand-written reconstruction from the disassembly (lane lbp6c, Claude Sonnet 5.5); exact match verified (matching idiom: the size is accumulated step by step in one unsigned local); names and types await human review. */
struct Ent { char pad0[8]; int size; char pad1[6]; unsigned short bits; };
struct Hdr { int pad0; int count; int offset; };
extern void *FUN_08a9e4a4(unsigned size, int a, int b);
extern void *FUN_08b9e7a8(void *dst, const void *src, unsigned n);

void *FUN_0899a3ec(struct Hdr *h)
{
  struct Ent *last = (struct Ent *)((char *)h + h->offset + h->count * 20 - 20);
  unsigned total = (unsigned short)((last->bits - 1) / 8 + 1);
  total += last->size;
  total += (unsigned)last;
  total -= (unsigned)h;
  void *copy = FUN_08a9e4a4(total, 0, 0);
  FUN_08b9e7a8(copy, h, total);
  return copy;
}
