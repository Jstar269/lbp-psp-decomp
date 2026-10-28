/* LBPMATCH module=EBOOT.BIN start=0x088d7f9c end=0x088d7fc4 symbol=FUN_088d7f9c lang=c99 cc=gcc410-Os */
/* Mechanical translation of Ghidra pseudocode (lbpgen.py tag g2); exact match verified; names and types await human review.; readability pass (lane rd4c, Claude Sonnet) */

struct WordStack {
  char unk_00[0x1c];
  unsigned int *begin;           /* +0x1c */
  unsigned int *end;             /* +0x20: one past the last word */
};

extern struct WordStack *DAT_08beee0c;

/* Last word of the global's list, or 0 when there is no global or the list is empty. */
unsigned int FUN_088d7f9c(void)
{
  unsigned int result;

  result = 0;
  if ((DAT_08beee0c != 0) && (DAT_08beee0c->begin != DAT_08beee0c->end)) {
    result = DAT_08beee0c->end[-1];
  }
  return result;
}
