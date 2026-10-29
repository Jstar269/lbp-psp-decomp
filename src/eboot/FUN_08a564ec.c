/* LBPMATCH module=EBOOT.BIN start=0x08a564ec end=0x08a565a8 symbol=FUN_08a564ec lang=c99 cc=gcc404xs-O2 */
/* Hand-written reconstruction from the disassembly (lane lbp10a, Claude Sonnet 5.5); exact match verified; names and types await human review. Unaligned word store from __builtin_memcpy of a by-value parameter (swl/swr). */
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

static inline void WriteFloat(Stream *s, float v)
{
  Cursor *c = s->cur;
  if (!FUN_08954cc4(c->mode))
    __builtin_memcpy(c->ptr, &v, 4);
  c->ptr += 4;
  c->count += 4;
}

typedef struct FI { float a; int b; } FI;

void FUN_08a564ec(Stream *s, FI *p)
{
  WriteFloat(s, p->a);
  WriteInt(s, p->b);
}
