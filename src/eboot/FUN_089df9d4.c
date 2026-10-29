/* LBPMATCH module=EBOOT.BIN start=0x089df9d4 end=0x089dfaec symbol=FUN_089df9d4 lang=c99 rodata=0x08bab59c */
/* Hand-written reconstruction from the disassembly (lane lbp9b, Claude Sonnet 5.5); exact match verified; names and types await human review. Matching idiom: the sub-object address is spelled (char *)o + 24 where it is stored, which stops the compiler sharing one register with the first use. */
struct Slot {
  float a;
  float b;
  unsigned char flag;
  char pad[3];
};
struct Listener {
  void **vtable;
  int pad;
  struct Obj *owner;
};
struct Obj {
  void **vtable;            /* 0 */
  unsigned int flags;       /* 4 */
  char base[0x10];          /* 8 */
  char sub[8];              /* 24 */
  void *head;               /* 32 */
  void *tail;               /* 36 */
  int w40, w44, w48;        /* 40 */
  struct Listener *listener; /* 52 */
  int mode;                 /* 56 */
  int w60;                  /* 60 */
  int refs[4];              /* 64 */
  unsigned char used[4];    /* 80 */
  struct Slot slots[4];     /* 84 */
  int w132;                 /* 132 */
  float x;                  /* 136 */
  float y;                  /* 140 */
};
extern void *DAT_08bc1b50[];
extern void *DAT_08bc1bf8[];
extern void FUN_0896b21c(struct Obj *o);
extern void FUN_089d4ad0(void *sub);
extern void *FUN_08a9e838(int size);
extern void FUN_089e099c(struct Listener *l);

void FUN_089df9d4(struct Obj *o)
{
  int i;
  struct Slot *p;
  struct Listener *l;
  struct Listener *old;
  FUN_0896b21c(o);
  o->vtable = DAT_08bc1b50;
  FUN_089d4ad0(o->sub);
  o->mode = 6;
  o->head = 0;
  o->tail = 0;
  o->w40 = 0;
  o->w44 = 0;
  o->w48 = 0;
  o->listener = 0;
  o->w60 = 0;
  i = 4;
  p = o->slots;
  do {
    i--;
    p->b = 1.0f;
    p->flag = 0;
    p->a = 1.0f;
    p++;
  } while (i != 0);
  o->x = 1.0f;
  o->head = (char *)o + 24;
  o->y = 1.0f;
  o->tail = (char *)o + 24;
  o->flags |= 3;
  o->w132 = 0;
  l = FUN_08a9e838(24);
  FUN_089e099c(l);
  old = o->listener;
  l->vtable = DAT_08bc1bf8;
  if (old != 0)
    ((void (*)(struct Listener *))old->vtable[1])(old);
  o->listener = l;
  l->owner = o;
  i = 0;
  do {
    i++;
    o->refs[i - 1] = 0;
    o->used[i - 1] = 0;
  } while (i != 4);
}
