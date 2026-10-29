/* LBPMATCH module=EBOOT.BIN start=0x088ce44c end=0x088ce524 symbol=FUN_088ce44c lang=c99 */
/* Hand-written reconstruction from the disassembly (lane lbp10b, Sonnet 5.5); NEAR, not verified; names and types await human review. */
struct Blk { int w[5]; };
struct PBlk { char b[20]; };
struct T { struct Blk blk; char pad0[34]; short s54, s56, s58; unsigned char c60, c61; char pad1[2]; int w64, w68, w72, w76; };
struct O { char pad0[0x3c]; struct Blk blk; char pad1[0x7e - 0x50]; unsigned short s126; };
extern char *FUN_08882764(void);
extern void FUN_088ce110();

void FUN_088ce44c(struct T *t, struct O *o)
{
  struct Blk tmp;
  t->c60 = 0; t->c61 = 0;
  t->w64 = 0; t->w68 = 0; t->w72 = 0; t->w76 = 0;
  t->s58 = 0; t->s54 = 0; t->s56 = 0;
  if (o) {
    t->s58 = o->s126;
    t->blk = tmp = o->blk;
  } else {
    __builtin_memcpy(&t->blk, FUN_08882764(), 20);
  }
  FUN_088ce110(t);
}
// NEAR (55 vs 54 words, ~20 differ after the first shift): the else path (__builtin_memcpy(&t->blk, ptr, 20) from the char* result: lwl/lwr loads, plain sw stores) and the stack copy in the
// then path (t->blk = tmp = o->blk) match retail. Left: retail stores the three halfwords (58,54,56) FIRST, then bytes 60,61 and words 64..76, and loads o->s126 before the block (so
// `o` stays in a1); ours always schedules the halfword zero stores after the words and needs `move v0,a1`. Source order of the nine zero stores made no difference (6 orders tried),
// nor did O2/gcc402x/gcc410 or splitting the chained copy.
// near miss from lane lbp10b (unreviewed)
