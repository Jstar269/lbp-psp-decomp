/* LBPMATCH module=EBOOT.BIN start=0x0891bde0 end=0x0891be2c symbol=FUN_0891bde0 lang=c99 cc=gcc402x-Os */
/* Mechanical translation of Ghidra pseudocode (lbpgen.py tag g6); exact match verified; names and types await human review.; readability pass (lane rd4d, Claude Sonnet) */
struct Obj {
  char unk_00[0x38];
  int unk_38;
};

extern int FUN_08916d40();
extern void FUN_08916ffc();

/* Acts only when the word at +0x38 is non-negative and FUN_08916d40 accepts it. */
void FUN_0891bde0(struct Obj *self)
{
  int accepted;

  if ((-1 < self->unk_38) && (accepted = FUN_08916d40(self->unk_38), accepted != 0)) {
    FUN_08916ffc(self->unk_38);
    return;
  }
  return;
}
