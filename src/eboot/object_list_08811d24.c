/* LBPMATCH module=EBOOT.BIN start=0x08811d24 end=0x08811e14 symbol=FUN_08811d24 lang=c99 */
/* Hand-written reconstruction from the disassembly (lane lbp7a, Codex GPT-6); exact match verified; names and types await human review. */
typedef struct Obj Obj;
typedef struct Node { struct Node *next, *prev; Obj *obj; } Node;
struct Obj { void (**vtable)(); char pad[64]; int type; char pad2[80]; Obj *parent; Node list; };
extern void FUN_08811c40(Obj *);
extern void FUN_08811f34(Obj *);
extern int FUN_08a43fe0(void);
extern int FUN_08a43fec(int, Obj *);
extern void FUN_08a49e54(Obj *);
void FUN_08811d24(Obj *p) {
 Obj *root = p->parent ? p->parent : p;
 Node *n, *end;
 if (root->type == 14) FUN_08811c40(root);
 else { FUN_08811f34(root); root->vtable[42](root,0); }
 n = root->list.next;
 end = &root->list;
 while (n != end) {
  Obj *o = n->obj;
  if (root->type == 14) FUN_08811c40(o);
  else { if (FUN_08a43fec(FUN_08a43fe0(),o)) FUN_08a49e54(o); FUN_08811f34(o); o->vtable[42](o,0); }
  n = n->next;
 }
}
