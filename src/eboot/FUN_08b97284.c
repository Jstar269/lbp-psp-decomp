/* LBPMATCH module=EBOOT.BIN start=0x08b97284 end=0x08b9730c symbol=FUN_08b97284 lang=c99 */
/* Clone of src/eboot/FUN_08b9715c.c (lbpclone.py tag c17): addresses substituted; exact match verified; names and types await human review. */
/* Hand-written reconstruction from the disassembly (lane lbp9b, Claude Sonnet 5.5); exact match verified; names and types await human review. */
struct In {
  unsigned int a;
  int b;
};
struct Out {
  unsigned int n;
  unsigned int rest[5];
};
extern void FUN_08b978f8(struct In *in, struct Out *out);
extern int FUN_08b97a24(struct Out *x, struct Out *y);

int FUN_08b97284(unsigned int a, int b, unsigned int c, int d)
{
  struct In i1, i2;
  struct Out o1, o2;
  int r;
  i1.a = a;
  i1.b = b;
  i2.a = c;
  i2.b = d;
  FUN_08b978f8(&i1, &o1);
  FUN_08b978f8(&i2, &o2);
  r = 1;
  if (o1.n > 1 && o2.n > 1)
    r = FUN_08b97a24(&o1, &o2);
  return r;
}
