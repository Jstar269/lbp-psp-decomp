/* LBPMATCH module=EBOOT.BIN start=0x088974d8 end=0x08897588 symbol=FUN_088974d8 lang=c99 */
/* Clone of src/eboot/lane13a_0887ac18.c (lbpclone.py tag c20): addresses substituted; exact match verified; names and types await human review. */
/* Hand-written reconstruction from the disassembly (lane lbp13a, Codex GPT-6); exact match verified; names and types await human review. */
typedef struct Ring { unsigned first, last, size; char active; char pad[3]; } Ring;
typedef struct Obj { int unused; void (*callback)(void *, void *); void *arg; Ring *ring; char list[16]; } Obj;
extern void *FUN_08b898a0(void *);
extern void FUN_08896124(void *), FUN_0887ab78(void *);
void FUN_088974d8(Obj *p) {
 char *n;
 Ring *r;
 if (p->callback) {
  for (n = *(char **)(p->list + 12); n != p->list + 4; n = FUN_08b898a0(n))
   p->callback(n + 48, p->arg);
 }
 FUN_08896124(p->list);
 r = p->ring;
 if (r) {
  unsigned i;
  for (i = r->last; i != r->first; i = (i + 1) & (r->size - 1)) { }
  r->last = 0; r->first = 0;
  FUN_0887ab78((char *)r + 16);
  r->active = 0;
 }
}
