/* LBPMATCH module=EBOOT.BIN start=0x08aa6e60 end=0x08aa6ebc symbol=FUN_08aa6e60 lang=c++ */
/* Hand-written reconstruction from the disassembly (lane lbp9c, Claude Sonnet 5.5); exact match verified; names and types await human review. */
extern char DAT_08bab530[];
extern char DAT_08bcb37c[];
extern char DAT_08bcb330[];
extern int DAT_08bcb430;
struct Sub { const void *vt; int a; int b; int c; int d; };
struct Obj { const void *vt; int a; int b; Sub s; };
extern "C" void FUN_08aa6c00(Sub *, int, int, int, int);

extern "C" void FUN_08aa6e60(Obj *self, int a, int b, int c)
{
  self->vt = DAT_08bab530;
  self->a = a;
  self->b = b;
  FUN_08aa6c00(&self->s, a, b, c, DAT_08bcb430);
  self->vt = DAT_08bcb330;
  self->s.vt = DAT_08bcb37c;
}
// NEAR 8 words: only the prologue schedule differs (retail: lui v0; addiu sp; lw t0 ; ... sw s0; ... move s0,a0; sw ra last; ours sw ra first, lw t0 after move).
// Tried: C and C++ struct form, store permutations, cc=gcc404xs-O2 (worse), early local for the global.
// near miss from lane lbp9c (unreviewed)
