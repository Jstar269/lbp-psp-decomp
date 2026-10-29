/* LBPMATCH module=EBOOT.BIN start=0x0883c870 end=0x0883c95c symbol=FUN_0883c870 lang=c99 */
/* Hand-written reconstruction from the disassembly (lane lbp10a, Claude Sonnet 5.5); exact match verified; names and types await human review. Unaligned word stores from __builtin_memcpy of by-value parameters (swl/swr). */
typedef struct Cursor {
  char pad0[4];
  char *ptr;
  char pad8[12];
  int count;
  char pad18[0x18];
  struct Mode *mode;
} Cursor;

typedef struct Stream { Cursor *cur; } Stream;

typedef struct Owner { char pad8[8]; char data[20]; int tail; } Owner;

extern unsigned char FUN_08954cc4(struct Mode *m);
extern void FUN_08954ca4(Cursor *c, int tag);
extern void FUN_08954e28(Cursor *c, int align);
extern void FUN_08954e6c(Cursor *c, void *data, int size, int n);

static inline void WriteInt(Stream *s, int v)
{
  Cursor *c = s->cur;
  if (!FUN_08954cc4(c->mode))
    __builtin_memcpy(c->ptr, &v, 4);
  c->ptr += 4;
  c->count += 4;
}

void FUN_0883c870(void *self, Stream *s, int tag, Owner *o, int arg)
{
  FUN_08954ca4(s->cur, tag);
  FUN_08954e28(s->cur, 4);
  WriteInt(s, arg);
  FUN_08954e6c(s->cur, o->data, 1, 20);
  WriteInt(s, o->tail);
}
