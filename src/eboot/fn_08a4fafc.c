/* LBPMATCH module=EBOOT.BIN start=0x08a4fafc end=0x08a4fb98 symbol=FUN_08a4fafc lang=c99 cc=gcc404xs-O2 */
/* Hand-written reconstruction from the disassembly (lane lbp4b, Claude Sonnet 5.5): list walk with two temporaries, cc=gcc404xs-O2; exact match verified; names and types await human review. */
struct Node { struct Node *next; int pad; char *obj; };
extern void FUN_08a34d40(char *);
extern void FUN_08a9bff8(void *);
extern void *FUN_08a9d390(void *, int);
void FUN_08a4fafc(char *p)
{
  struct Node *head = (struct Node *)(p + 0x30c);
  struct Node *n;
  unsigned b[6];
  unsigned a[6];
  FUN_08a34d40(p);
  for (n = head->next; n != head; n = n->next) {
    char *o = n->obj;
    if (o) {
      FUN_08a9d390(a, -1);
      FUN_08a9bff8(a);
      FUN_08a9d390(b, -1);
      FUN_08a9bff8(b);
      *(int *)(o + 0x90) = -1;
    }
  }
}
