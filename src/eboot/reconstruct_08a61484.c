/* LBPMATCH module=EBOOT.BIN start=0x08a61484 end=0x08a61514 symbol=FUN_08a61484 lang=c99 cc=gcc404xs-O2 */
/* Hand-written reconstruction from the disassembly (lane lbp6a, Claude Sonnet 5.5); exact match verified; names and types await human review. */
struct Node { struct Node *next; struct Node *prev; void *item; };
struct Res { char pad[8]; unsigned int id; };
struct Obj { char pad0[0xbc]; struct Res *res; char pad1[0x234 - 0xc0]; struct Node head; };
extern unsigned int FUN_089ed9ec(unsigned int);
extern int FUN_089edad8(unsigned int);
extern void FUN_089ef61c(int, void *, int);
extern void FUN_08a20ec0(void *, void *, int);
void FUN_08a61484(struct Obj *o, void *p2, int p3)
{
  struct Node *end = &o->head;
  struct Node *n = end->next;
  while (end != n) {
    FUN_08a20ec0(n->item, p2, p3);
    n = n->next;
  }
  FUN_089ef61c(FUN_089edad8(FUN_089ed9ec(o->res->id)), p2, p3);
}
