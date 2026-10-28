/* LBPMATCH module=EBOOT.BIN start=0x088d3618 end=0x088d3670 symbol=FUN_088d3618 lang=c99 cc=gcc402t-Os */
/* Mechanical translation of Ghidra pseudocode (lbpgen.py tag g5); exact match verified; names and types await human review.; readability pass (lane rd3a, Claude Sonnet) */
struct FlagRec {
  unsigned int flags;
  unsigned char unk_04[0x24];
  unsigned int mode;   /* +0x28 */
};

/* Returns 1 when none of the flag bits 0x7c0, 0x800 and 0x20000 are set and mode is 1, 3 or 5. */
unsigned int FUN_088d3618(struct FlagRec *self)
{
  unsigned int flags;
  unsigned int mode;
  unsigned int result;

  flags = self->flags;
  result = 0;
  if (((flags & 0x7c0) == 0 && (flags & 0x800) == 0) && (flags & 0x20000) == 0) {
    mode = self->mode;
    if (mode == 1) {
      result = 1;
    }
    else if (mode == 3) {
      result = 1;
    }
    else if (mode == 5) {
      result = 1;
    }
  }
  return result;
}
