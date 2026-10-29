/* LBPMATCH module=EBOOT.BIN start=0x08842a24 end=0x08842ab0 symbol=FUN_08842a24 lang=c99 */
/* Hand-written reconstruction from the disassembly (lane lbp6d, Claude Sonnet 5.5); exact match verified; names and types await human review. */
extern void FUN_088d3104(void *, unsigned, int);
struct Ent { int a; int b; int c; int d[4]; };
struct M { int pad; struct Ent *ents; int pad2; char flag; };
struct P { char pad[0x24]; int idx; int type; };
void FUN_08842a24(struct M *m, struct P *p, int v)
{
  if (p != 0 && (p->type == 3 || p->type == 5 || p->type == 4)) {
    int i = p->idx - 1;
    if (v != 0)
      m->ents[i].c = v;
    FUN_088d3104(&m->ents[i], 0x800000, 1);
    m->flag = 1;
  }
}
