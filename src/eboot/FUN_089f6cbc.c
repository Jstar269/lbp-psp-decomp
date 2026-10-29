/* LBPMATCH module=EBOOT.BIN start=0x089f6cbc end=0x089f6d6c symbol=FUN_089f6cbc lang=c99 cc=gcc404xs-O2 */
/* Hand-written reconstruction from the disassembly (lane lbp12b, Claude Sonnet 5.5); exact match verified; names and types await human review. This unit is gcc404xs-O2 (duplicated epilogue before the tail call). */
struct Obj {
  int level;
  int f4;
  int step_count;
  int sum_a;
  int sum_b;
  char pad14;
  char pad15[7];
  float f1c;
  char pad20[8];
  void *target;
};
extern float DAT_08bab5c8;
extern void FUN_0897f4b0(void *t);
extern void FUN_0897c25c(void *t);

void FUN_089f6cbc(struct Obj *o)
{
  int step = 50;
  if (*(unsigned char *)((char *)o + 20)) {
    o->f1c = DAT_08bab5c8;
    step = 100;
  }
  o->sum_a = step + o->sum_a;
  o->step_count++;
  o->sum_b = step + o->sum_b;
  if (o->step_count == 5) {
    o->step_count = 0;
    o->level++;
    if (o->level > 100) o->level = 100;
    FUN_0897f4b0(o->target);
  }
  o->f4 = 0;
  FUN_0897c25c(o->target);
}
