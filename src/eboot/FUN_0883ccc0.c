/* LBPMATCH module=EBOOT.BIN start=0x0883ccc0 end=0x0883cdb0 symbol=FUN_0883ccc0 lang=c99 */
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

typedef struct Blob { char pad[0x20]; int a; int b; char name[17]; } Blob;

extern unsigned char FUN_08954cc4(struct Mode *m);
extern void FUN_0883c870(void *self, Stream *s, int tag, Blob *owner, int arg);
extern void FUN_08954e6c(Cursor *c, void *data, int size, int n);
extern void FUN_0895541c(Stream *s);

static inline void WriteInt(Stream *s, int v)
{
  Cursor *c = s->cur;
  if (!FUN_08954cc4(c->mode))
    __builtin_memcpy(c->ptr, &v, 4);
  c->ptr += 4;
  c->count += 4;
}

void FUN_0883ccc0(void *self, Stream *s, Blob *b, int arg)
{
  FUN_0883c870(self, s, 0x4d4f4d45, b, arg);
  WriteInt(s, b->a);
  WriteInt(s, b->b);
  FUN_08954e6c(s->cur, b->name, 1, 17);
  FUN_0895541c(s);
}
