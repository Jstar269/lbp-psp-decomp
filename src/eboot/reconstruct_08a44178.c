/* LBPMATCH module=EBOOT.BIN start=0x08a44178 end=0x08a441f4 symbol=FUN_08a44178 lang=c99 cc=gcc404xs-O2 */
/* Hand-written reconstruction from the disassembly (lane lbp6a, Claude Sonnet 5.5); exact match verified; names and types await human review. */
struct Target { char pad[0x160]; void (*cb)(void); };
struct Obj;
struct ObjVt { void *slot[23]; struct Target *(*get)(struct Obj *); };
struct Obj { const struct ObjVt *vt; };
struct Node { struct Node *next; struct Node *prev; unsigned int key[2]; };
struct Owner { char pad[0x30]; struct Node head; };
extern void *FUN_08a50fbc(void);
extern struct Obj *FUN_08a52bb8(void *, unsigned int *);
extern void FUN_08a70c6c(void);
void FUN_08a44178(struct Owner *o)
{
  struct Node *n;
  for (n = o->head.next; n != &o->head; n = n->next) {
    struct Obj *obj = FUN_08a52bb8(FUN_08a50fbc(), n->key);
    if (obj != 0) obj->vt->get(obj)->cb = FUN_08a70c6c;
  }
}
