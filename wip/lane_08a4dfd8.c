/* LBPMATCH module=EBOOT.BIN start=0x08a4dfd8 end=0x08a4e08c symbol=FUN_08a4dfd8 lang=c99 */
typedef struct Obj Obj;
typedef struct Node { struct Node *next; int pad[3]; Obj *obj; } Node;
struct Obj { void (**vt)(Obj *, int); int key; char pad[60]; int kind; };
extern Obj **FUN_0880f178(void *, int *);
__attribute__((noinline)) void FUN_08a4dfd8(char *p, void *out) {
 Node *head = (Node *)(p + 0x360), *n;
 for (n = head->next; n != head; n = n->next) {
  Obj *o = n->obj;
  int key;
  o->vt[32](o, 1);
  key = o->key;
  *FUN_0880f178(out, &key) = o;
  if (o->kind == 13) FUN_08a4dfd8((char *)o, out);
 }
}
// 39 words differ; natural loop differs in loop layout and register allocation. noinline prevents recursive expansion; generated form also differs.
// near miss from lane lbp7b (unreviewed)
