/* LBPMATCH module=EBOOT.BIN start=0x089f676c end=0x089f67e8 symbol=FUN_089f676c lang=c99 cc=gcc404xs-Os */
/* Hand-written reconstruction from the disassembly (lane lbp6a, Claude Sonnet 5.5); exact match verified; names and types await human review. */
struct Obj { int count; int pad4; int f8; int pos; int stride; int pad14[5]; void *buf; };
extern void FUN_0897c25c(void *, int);
extern void FUN_0897f590(void *, int);
extern void FUN_08ac216c(int, int);
void FUN_089f676c(struct Obj *o)
{
  if (o->count > 1) {
    FUN_0897f590(o->buf, o->count);
    o->pos += (o->count - 1) * o->stride;
    FUN_0897c25c(o->buf, o->stride);
  }
  o->stride = 0;
  FUN_08ac216c(0x16, 0);
  o->count = 1;
  o->f8 = 0;
}
// 8 words differ: retail computes pos += (count-1)*stride as mtlo v1; madd v0,a1; mflo v1 (and loads pos first); ours mult/mflo/addu. Tried operand order forms, O2, gcc171-Os/O2, gcc402x-Os, gcc410-Os: none emit madd.
// near miss from lane lbp6a (unreviewed)
