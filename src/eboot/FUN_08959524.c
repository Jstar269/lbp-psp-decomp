/* LBPMATCH module=EBOOT.BIN start=0x08959524 end=0x08959580 symbol=FUN_08959524 lang=c99 cc=gcc402x-Os */
/* Mechanical translation of Ghidra pseudocode (lbpgen.py tag g6); exact match verified; names and types await human review.; readability pass (lane rd3c, Claude Sonnet) */
struct Holder {
  char pad[0x58];
  void *unk_58;
  char pad2[0x48];
  void *unk_a4;
};

extern int FUN_08958770();
extern int FUN_0895d3a4();

/* Returns 1 when either sub-object that is present fails its own check. */
int FUN_08959524(struct Holder *self)
{
  int ok;

  if (self->unk_58 != 0 && (ok = FUN_0895d3a4(self->unk_58), ok == 0)) {
    return 1;
  }
  if (self->unk_a4 != 0 && (ok = FUN_08958770(self->unk_a4), ok == 0)) {
    return 1;
  }
  return 0;
}
