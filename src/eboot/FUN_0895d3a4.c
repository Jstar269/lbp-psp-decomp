/* LBPMATCH module=EBOOT.BIN start=0x0895d3a4 end=0x0895d3e0 symbol=FUN_0895d3a4 lang=c99 cc=gcc171-Os */
/* Mechanical translation of Ghidra pseudocode (lbpgen.py tag g3); exact match verified; names and types await human review.; readability pass (lane rd3c, Claude Sonnet) */
struct Flagged {
  char pad[0x10];
  unsigned char flag;       /* +0x10 */
};

struct Pair {
  char pad[0x50];
  struct Flagged *unk_50;
  struct Flagged *unk_54;
};

/* Returns 1 only when both members exist and both have their +0x10 flag set. */
int FUN_0895d3a4(struct Pair *self)
{
  int result;

  result = 0;
  if (((self->unk_54 != 0) && (self->unk_50 != 0)) &&
      ((result = 1, self->unk_54->flag == '\0') || (self->unk_50->flag == '\0'))) {
    result = 0;
  }
  return result;
}
