/* LBPMATCH module=EBOOT.BIN start=0x0896a644 end=0x0896a728 symbol=FUN_0896a644 lang=c99 */
/* Clone of src/eboot/ctor_links_0896a560.c (lbpclone.py tag c17): addresses substituted; exact match verified; names and types await human review. */
/* Hand-written reconstruction from the disassembly (lane lbp9c, Claude Sonnet 5.5); exact match verified; names and types await human review. */
extern char DAT_08bb88b0[];
extern void FUN_0896b21c(void *);
struct Link { unsigned w0, flags; struct Obj *owner; };
struct Obj {
  const void *vt;
  unsigned flags;
  struct Obj *parent;
  int pad[3];
  struct Link *first;
  struct Link *second;
  unsigned short h20;
  char c22, c23, c24, c25, c26, c27;
};

void FUN_0896a644(struct Obj *self, struct Link *a, struct Link *b, int c, int d, int e, int f)
{
  struct Link *x, *y;
  unsigned v;

  FUN_0896b21c(self);
  self->c22 = c;
  self->c23 = d;
  self->vt = DAT_08bb88b0;
  self->h20 = e;
  self->c24 = 1;
  self->c27 = 0;
  self->c25 = 1;
  self->c26 = f;
  if (c == 0) {
    self->first = a;
    self->second = b;
  } else {
    self->first = b;
    self->second = a;
  }
  x = self->first;
  v = self->flags;
  y = self->second;
  x->owner = self;
  v = v | (x->flags & 3);
  self->flags = v;
  y->owner = self;
  self->flags = v | (y->flags & 3);
}
