/* LBPMATCH module=EBOOT.BIN start=0x08a46198 end=0x08a461f0 symbol=FUN_08a46198 lang=c99 cc=gcc410-Os */
/* Mechanical translation of Ghidra pseudocode (lbpgen.py tag g2); exact match verified; names and types await human review.; readability pass (lane rd3d, Claude Sonnet) */
/* Looks up the object's field +0x10 through FUN_08a52bb8 (on the FUN_08a50fbc object); returns early when it is
   found and FUN_08a45408 accepts the object, otherwise runs FUN_08a45f14. */
struct Rec46198 {
  char pad[0xc];
  int *unk_0c;
  unsigned int key_10;       /* +0x10: looked up, address-taken */
};

extern int FUN_08a45408();
extern void FUN_08a45f14();
extern int FUN_08a50fbc();
extern int FUN_08a52bb8();

void FUN_08a46198(struct Rec46198 *self)
{
  int found;

  found = FUN_08a50fbc();
  found = FUN_08a52bb8(found, &self->key_10);
  if ((found != 0) && (found = FUN_08a45408(self, self->unk_0c), found == 0)) {
    return;
  }
  FUN_08a45f14(self);
  return;
}
