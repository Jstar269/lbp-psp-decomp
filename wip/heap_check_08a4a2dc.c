/* LBPMATCH module=EBOOT.BIN start=0x08a4a2dc end=0x08a4a358 symbol=FUN_08a4a2dc lang=c99 cc=gcc404xs-O2 */
/* Hand-written reconstruction from the disassembly (lane lbp11d, Claude Sonnet 5.5); exact match verified; names and types await human review. */
struct Range { int begin; int end; int cap; };
struct Obj { char pad[472]; unsigned char flag; char pad2[3]; float val; };
extern struct Range *DAT_08bdc188;
extern void FUN_08a4149c(struct Obj *);
extern void FUN_08980cd8(struct Obj *, float);
static inline int used_(struct Range *r)
{
  if (r->end == 0) return 0;
  return r->end - r->begin;
}
void FUN_08a4a2dc(struct Obj *self)
{
  struct Range *r = DAT_08bdc188;
  if (r->cap - used_(r) > 0x6000) {
    FUN_08a4149c(self);
    if (self->flag == 1)
      FUN_08980cd8(self, self->val);
  }
}
// NEAR 4 words (cc=gcc404xs-O2, inline used_() helper): a1/a2 swapped (retail: used in a1, cap in a2; ours cap a1, used a2); tried temps/order variants. Os gives wrong block layout (22 words).
// near miss from lane lbp11d (unreviewed)
