/* LBPMATCH module=EBOOT.BIN start=0x088f7ec8 end=0x088f7f90 symbol=FUN_088f7ec8 lang=c99 */
/* Hand-written reconstruction from the disassembly (lane lbp11d, Claude Sonnet 5.5); exact match verified; names and types await human review. */
struct Lock { int x; };
struct Res { char pad[8]; int refs; char pad1[8]; struct Lock lock; char pad2[144]; void *table; };
struct Self { const void *vt; int first; unsigned count; };
extern char DAT_08bb4ef8[];
extern char DAT_08bb4f00[];
extern void *DAT_08be84a8;
extern struct Res *FUN_08aaab30(void *, const char *);
extern void FUN_08ad3088(struct Lock *);
extern void FUN_08ad2810(struct Lock *);
extern int FUN_0891d6e4(void *);
extern unsigned FUN_0891d6dc(void *);
extern void FUN_088050b8(struct Res *);
void FUN_088f7ec8(struct Self *self)
{
  struct Res *r;
  self->vt = DAT_08bb4ef8;
  r = FUN_08aaab30(DAT_08be84a8, DAT_08bb4f00);
  if (r != 0) {
    FUN_08ad3088(&r->lock);
    r->refs++;
    FUN_08ad2810(&r->lock);
  }
  self->first = FUN_0891d6e4(r->table);
  self->count = FUN_0891d6dc(r->table) / 0x58;
  if (r != 0)
    FUN_088050b8(r);
}
// NEAR ~14 words: retail keeps the final 'if (r)' null test after dereferencing r->table (own epilogue copy); ours deletes it (null-pointer-check elimination). Tried Os/O2/gcc402x/gcc410.
// near miss from lane lbp11d (unreviewed)
