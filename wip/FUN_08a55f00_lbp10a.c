/* LBPMATCH module=EBOOT.BIN start=0x08a55f00 end=0x08a55fbc symbol=FUN_08a55f00 lang=c99 cc=gcc404xs-O2 */
/* Hand-written reconstruction from the disassembly (lane lbp10a, Claude Sonnet 5.5); exact match verified; names and types await human review. */
typedef struct Cursor {
  char pad0[4];
  char *ptr;
  char pad8[12];
  int count;
  char pad18[0x18];
  struct Mode *mode;
} Cursor;

typedef struct Stream { Cursor *cur; } Stream;

extern unsigned char FUN_08954cc4(struct Mode *m);

static inline void WriteInt(Stream *s, int v)
{
  Cursor *c = s->cur;
  if (!FUN_08954cc4(c->mode))
    __builtin_memcpy(c->ptr, &v, 4);
  c->ptr += 4;
  c->count += 4;
}

void FUN_08a55f00(Stream *s, int *p)
{
  WriteInt(s, p[0]);
  WriteInt(s, p[1]);
}
// NEAR: 7 words differ (O2 profile). Block layout and both swl/swr stores match; in the first inlined write retail loads
// count, ptr, then the reloaded cursor, ours count, cursor, ptr, and retail stores count/ptr before the next lw.
// Tried: ptr/count update order in either write, float/pointer typed first value (separate stack slot: worse).
// near miss from lane lbp10a (unreviewed)
