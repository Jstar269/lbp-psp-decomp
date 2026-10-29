/* LBPMATCH module=EBOOT.BIN start=0x08b8d47c end=0x08b8d514 symbol=FUN_08b8d47c lang=c99 cc=gcc404xs-O2 */
/* Hand-written reconstruction from the disassembly (lane lbp6b, Claude Sonnet 5.5); exact match verified; names and types await human review. */
typedef struct A A;
typedef struct B B;
struct B { struct BV { int s0, s1; int (*m2)(B *); } *vt; };
struct A { struct AV { int s0, s1, s2, s3; int (*m4)(A *, B *, int **, int); } *vt; };
int FUN_08b8d47c(A *a, B *b, int **out)
{
  int *cur = *out;
  int ok = 0;
  if (b->vt->m2(b) != 0)
    cur = (int *)*cur;
  if (a->vt->m4(a, b, &cur, 1) != 0) {
    *out = cur;
    ok = 1;
  }
  return ok;
}
// cc=gcc404xs-O2 (batch hint Os was wrong); virtual calls through vtable structs.
