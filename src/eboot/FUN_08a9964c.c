/* LBPMATCH module=EBOOT.BIN start=0x08a9964c end=0x08a99694 symbol=FUN_08a9964c lang=c99 cc=gcc410-Os */
/* Mechanical translation of Ghidra pseudocode (lbpgen.py tag g2); exact match verified; names and types await human review.; readability pass (lane rd1b, Claude Sonnet) */

extern void FUN_08a412a4();

typedef struct Obj9964c {
  char pad_000[0x1a8];
  unsigned int unk_1a8;
  unsigned int unk_1ac;
  unsigned int unk_1b0;
} Obj9964c;

/* Copy: the base part first (FUN_08a412a4), then the three words at 0x1a8..0x1b0. */
void FUN_08a9964c(Obj9964c *dst, Obj9964c *src, void *arg)
{
  unsigned int word_1a8;
  unsigned int word_1ac;

  FUN_08a412a4(dst,src,arg);
  word_1a8 = src->unk_1a8;
  word_1ac = src->unk_1ac;
  dst->unk_1b0 = src->unk_1b0;
  dst->unk_1a8 = word_1a8;
  dst->unk_1ac = word_1ac;
  return;
}
