/* LBPMATCH module=EBOOT.BIN start=0x0880b31c end=0x0880b344 symbol=FUN_0880b31c lang=c99 cc=gcc171-Os */
/* Mechanical translation of Ghidra pseudocode (lbpgen.py tag g3); exact match verified; names and types await human review.; readability pass (lane rd4c, Claude Sonnet) */

struct Object {
  char unk_00[0x2e0];
  int state;                  /* +0x2e0 */
  char unk_2e4[0x358];
  unsigned char flag_63c;     /* +0x63c */
};

/* True unless the state is 6 or the flag at +0x63c is clear. */
unsigned int FUN_0880b31c(struct Object *self)
{
  unsigned int result;

  result = 1;
  if ((self->state == 6) || (self->flag_63c == 0)) {
    result = 0;
  }
  return result;
}
