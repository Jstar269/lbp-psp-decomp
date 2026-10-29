/* LBPMATCH module=EBOOT.BIN start=0x089e0558 end=0x089e05e0 symbol=FUN_089e0558 lang=c99 */
/* Hand-written reconstruction (lane lbp4a); NEAR. */
typedef unsigned int uint;
struct Info { int pad; uint flags; };
struct Node { void *a; void *b; struct Info *info; };
struct Owner { int pad0; uint flags; char pad1[0x10]; char end[8]; struct Node *cur; struct Node *prev; char pad2[0x0c]; int *x; };
extern struct Node *FUN_089def60(struct Owner *, short *);
extern void FUN_089e0608(int *);

void FUN_089e0558(struct Owner *param_1, short *param_2)
{
  struct Node *n = FUN_089def60(param_1, param_2);
  if (n != (struct Node *)param_1->end && n != param_1->cur) {
    struct Info *info = n->info;
    uint f = info->flags;
    if ((f & 0x400) == 0 && (f & 4) != 0) {
      param_1->prev = param_1->cur;
      param_1->cur = n;
      if ((param_1->flags & 0x200) != 0)
        FUN_089e0608(param_1->x);
      param_1->flags |= 0x1000;
    }
  }
}
// NEAR 5 words: retail keeps cur in a2 and node->info in a1 (v0 = flags); ours cur=a1, info=v0. Tried: double info access, flag order, cur local, hoisting info load (worse), O2 (worse).
// near miss from lane lbp4a (unreviewed)
