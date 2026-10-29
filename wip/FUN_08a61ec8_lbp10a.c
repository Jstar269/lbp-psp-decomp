/* LBPMATCH module=EBOOT.BIN start=0x08a61ec8 end=0x08a61fa4 symbol=FUN_08a61ec8 lang=c99 cc=gcc404xs-O2 */
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

typedef struct Node { struct Node *next; struct Node *prev; void *item; } Node;
typedef struct Self { char pad[0xbc]; int sub[0x178 / 4 - 0x2f + 0x2f]; } SelfDummy;

extern unsigned char FUN_08954cc4(struct Mode *m);
extern void FUN_08a34774(void *self, Stream *s, int tag);
extern void FUN_08a56ec8(void *sub, Stream *s, void *owner);
extern void FUN_08a21900(void *item, Stream *s);
extern void FUN_0895541c(Stream *s);

typedef struct Obj {
  char pad[0xbc];
  char sub[0x234 - 0xbc];
  Node list;
} Obj;

static inline void WriteInt(Stream *s, int v)
{
  Cursor *c = s->cur;
  if (!FUN_08954cc4(c->mode))
    __builtin_memcpy(c->ptr, &v, 4);
  c->ptr += 4;
  c->count += 4;
}

void FUN_08a61ec8(Obj *self, Stream *s)
{
  Node *end = &self->list;
  Node *p;
  int n;
  FUN_08a34774(self, s, 0x444e414c);
  FUN_08a56ec8(self->sub, s, self);
  n = 0;
  for (p = self->list.next; p != end; p = p->next)
    n++;
  WriteInt(s, n);
  for (p = self->list.next; p != end; p = p->next)
    FUN_08a21900(p->item, s);
  FUN_0895541c(s);
}
// NEAR: 12 words differ (gcc404xs-O2). Retail computes the list sentinel s1=self+564 right after the prologue and keeps it across the two calls; ours recomputes it later
// and keeps the first node in s1. Second loop in retail starts from the sentinel (lw s0,0(s1)), the counting loop from self+564 (lw v0,564(s0)); using end->next in the second loop made it worse (16).
// near miss from lane lbp10a (unreviewed)
