/* LBPMATCH module=EBOOT.BIN start=0x08891c90 end=0x08891d64 symbol=FUN_08891c90 lang=c99 */
struct N { char pad[0x14]; unsigned idx; };
struct K { unsigned v; unsigned pad[3]; };
struct Q { unsigned head; unsigned tail; unsigned mask; unsigned pad; unsigned map[6]; unsigned *buf; };
extern struct N *FUN_08891b40(void *, struct K *);
int FUN_08891c90(struct Q *q, struct K *key)
{
  struct K tmp;
  struct N *n1 = FUN_08891b40(q->map, key);
  tmp.v = q->buf[q->tail];
  struct N *n2 = FUN_08891b40(q->map, &tmp);
  unsigned i1 = n1->idx;
  unsigned head = q->head;
  unsigned *buf = q->buf;
  n2->idx = i1;
  unsigned k = key->v;
  n1->idx = q->head;
  unsigned head2 = q->head;
  unsigned tail = q->tail;
  unsigned mask = q->mask;
  buf[head] = k;
  buf[i1] = tmp.v;
  q->head = (head2 + 1) & (mask - 1);
  q->tail = (tail + 1) & (mask - 1);
  return 1;
}
// NEAR 4 words: loads/stores right; retail adds head+1 (a1) before tail+1 (a0) and reloads tmp (lw v1,0(sp)) after the masks. Tried typed key struct, statement permutations of the 4 stores and the 8 leading loads/locals, Ghidra form (9 words)
// near miss from lane lbp4b (unreviewed)
