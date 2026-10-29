/* LBPMATCH module=EBOOT.BIN start=0x08aa6ebc end=0x08aa6f38 symbol=FUN_08aa6ebc lang=c99 */
/* Hand-written reconstruction from the disassembly (lane lbp11d, Claude Sonnet 5.5); exact match verified; names and types await human review. */
extern char DAT_08bcb2c8[];
extern char DAT_08bcb314[];
struct Obj { void *vt; int w, h; void *vt2; int pad[4]; short *data; };
extern void FUN_08aa6e60(struct Obj *, int, int, int);
extern short *FUN_08a9e824(int);
void FUN_08aa6ebc(struct Obj *self, int w, int h)
{
  int n = w * h;
  short *p;
  int i;
  FUN_08aa6e60(self, w, h, w);
  self->vt = DAT_08bcb2c8;
  self->vt2 = DAT_08bcb314;
  short *base = FUN_08a9e824(n * 2);
  p = base;
  for (i = 0; i != n; i++)
    *p++ = 0;
  self->data = base;
}
// NEAR ~19 words: zero-fill loop shape (retail: i from 0, bound n+1 in the reused n register, 'addiu a0,1; bnel a0,s0' with the sh in the delay slot; self in s1, n in s0). Tried != / < / <= forms, signed/unsigned, indexed/pointer store.
// near miss from lane lbp11d (unreviewed)
