/* LBPMATCH module=EBOOT.BIN start=0x08a064e4 end=0x08a06548 symbol=FUN_08a064e4 lang=c99 */
/* Hand-written reconstruction from the disassembly (lane lbp11d, Claude Sonnet 5.5); exact match verified; names and types await human review. */
struct Vec { int begin; int end; };
extern void FUN_08b9e8cc(char *, char *, int);
char *FUN_08a064e4(struct Vec *v, char *first, char *last)
{
  FUN_08b9e8cc(first, last, v->end - (int)last);
  v->end -= ((int)last - (int)first) & ~3;
  return first;
}
// NEAR 3 words: retail loads this->end into v1 (ours v0) in the final end-update; tried int/char*/unsigned/int* end, local temps, return via local; int* ptr difference gives v1 but no ins.
// near miss from lane lbp11d (unreviewed)
