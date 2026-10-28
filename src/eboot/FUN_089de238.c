/* LBPMATCH module=EBOOT.BIN start=0x089de238 end=0x089de274 symbol=FUN_089de238 lang=c99 cc=gcc402t-Os */
/* Mechanical translation of Ghidra pseudocode (lbpgen.py tag g5); exact match verified; names and types await human review.; readability pass (lane rd3c, Claude Sonnet) */
struct Checked {
  char pad[0x24];
  unsigned int flags;
};

extern int FUN_089d97b0();

/* When any of the bits in mask are set in the object's flags, returns whether FUN_089d97b0 accepts it. */
int FUN_089de238(struct Checked *self, unsigned int mask)
{
  int accepted;
  int result;

  result = 0;
  if ((self->flags & mask) != 0) {
    accepted = FUN_089d97b0(self);
    result = 1;
    if (accepted == 0) {
      result = 0;
    }
  }
  return result;
}
