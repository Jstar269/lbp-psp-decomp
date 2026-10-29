/* LBPMATCH module=EBOOT.BIN start=0x089dd09c end=0x089dd10c symbol=FUN_089dd09c lang=c99 */
extern char DAT_08bc1a80, DAT_08bab5b8;
extern void *DAT_08be84a0;
extern void FUN_08adbc24(void *, void *, int);
typedef struct Node { struct Node *next; } Node;
typedef struct Obj { void *vtable; int pad[2]; Node head; } Obj;
void FUN_089dd09c(Obj *self) {
 Node *p;
 self->vtable = &DAT_08bc1a80;
 p = self->head.next;
 while (p != &self->head) { Node *next = p->next; FUN_08adbc24(DAT_08be84a0, p, 16); p = next; }
 self->vtable = &DAT_08bab5b8;
}


// 25 words differ with Os; sentinel register allocation differs, O2 also tried.
// near miss from lane lbp14a (unreviewed)
