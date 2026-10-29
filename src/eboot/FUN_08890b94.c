/* LBPMATCH module=EBOOT.BIN start=0x08890b94 end=0x08890c44 symbol=FUN_08890b94 lang=c99 */
/* Clone of src/eboot/FUN_08886b74.c (lbpclone.py tag c17): addresses substituted; exact match verified; names and types await human review. */
/* Hand-written reconstruction from the disassembly (lane lbp9b, Claude Sonnet 5.5); exact match verified; names and types await human review. */
struct Queue {
  unsigned int tail;
  unsigned int head;
  unsigned int size;
  unsigned char active;
  char pad[3];
  char pool[1];
};
struct List {
  int pad0;
  int sentinel;
  int pad2;
  struct List *first;
};
struct Obj {
  int pad0;
  void (*callback)(char *, int);
  int arg;
  struct Queue *queue;
  struct List list;
};
extern char *FUN_08b898a0(char *node);
extern void FUN_0888ffe0(struct List *list);
extern void FUN_08886ad4(char *pool);

void FUN_08890b94(struct Obj *o)
{
  struct Queue *q;
  char *n;
  unsigned int i;
  if (o->callback != 0) {
    struct List *l = &o->list;
    for (n = (char *)l->first; n != (char *)&l->sentinel; n = FUN_08b898a0(n))
      o->callback(n + 36, o->arg);
  }
  FUN_0888ffe0(&o->list);
  q = o->queue;
  if (q != 0) {
    for (i = q->head; i != q->tail; i = (i + 1) & (q->size - 1))
      ;
    q->head = 0;
    q->tail = 0;
    FUN_08886ad4(q->pool);
    q->active = 0;
  }
}
