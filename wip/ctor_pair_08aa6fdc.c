/* LBPMATCH module=EBOOT.BIN start=0x08aa6fdc end=0x08aa7054 symbol=FUN_08aa6fdc lang=c99 */
/* Hand-written reconstruction from the disassembly (lane lbp8a, Claude Sonnet 5.5); exact match verified; names and types await human review. */
extern char DAT_08bab530[];
extern char DAT_08bcb37c[];
extern char DAT_08bcb330[];
extern int DAT_08bcb430;
extern void FUN_08aa6c00(void *self, int a, int b, int c, int d);

struct Inner {
  void *vptr;
  int f4;
  int f8;
  int fc;
  int f10;
  int e;
};

struct Obj {
  void *vptr;
  int a;
  int b;
  struct Inner in;
};

void FUN_08aa6fdc(struct Obj *self, int a, int b, int c, int e)
{
  self->vptr = DAT_08bab530;
  self->a = a;
  self->b = b;
  struct Inner *in = &self->in;
  FUN_08aa6c00(in, a, b, c, DAT_08bcb430);
  in->vptr = DAT_08bcb37c;
  in->e = e;
  self->vptr = DAT_08bcb330;
}
// NEAR: 15 words differ, all prologue/epilogue scheduling (retail saves ra after s0, loads the global into t0 before the s1 save; ours saves ra first). Tried: statement orders, local pointer for the member, global in a local, gcc404xs-O2/gcc402x-Os/gcc410-Os/gcc171-Os.
// near miss from lane lbp8a (unreviewed)
