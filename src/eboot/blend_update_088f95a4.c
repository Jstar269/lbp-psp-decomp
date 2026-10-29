/* LBPMATCH module=EBOOT.BIN start=0x088f95a4 end=0x088f9604 symbol=FUN_088f95a4 lang=c99 rodata=0x08bab59c */
/* Hand-written reconstruction from the disassembly (lane lbp6b, Claude Sonnet 5.5); exact match verified; names and types await human review. */
typedef struct S { int pad; float pos; float blend; int cur; } S;
void FUN_088f95a4(float v, S *s, int idx)
{
  if (s->blend < 1.0f) {
    if (idx != s->cur) {
      s->cur = idx;
      s->blend = 1.0f - s->blend;
    }
    s->pos = v - v * s->blend;
  } else if (idx != s->cur) {
    s->cur = idx;
    s->pos = v;
    s->blend = 0.0f;
  }
}
