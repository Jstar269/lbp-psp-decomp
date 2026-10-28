/* LBPMATCH module=EBOOT.BIN start=0x08a46124 end=0x08a46198 symbol=FUN_08a46124 lang=c99 cc=gcc402x-Os */
/* Mechanical translation of Ghidra pseudocode (lbpgen.py tag g6); exact match verified; names and types await human review.; readability pass (lane rd3d, Claude Sonnet) */
/* Looks up the object's field +0x10 through FUN_08a52bb8 (on the FUN_08a50fbc object); when found, runs the
   FUN_08a45114 / FUN_08a44b84 / FUN_08a44af8 / FUN_08a45f14 sequence on the object. */
struct Rec46124 {
  char pad[0xc];
  int *unk_0c;
  unsigned int key_10;       /* +0x10: looked up, address-taken */
  char pad2[0x2c];
  int sub_40[1];             /* +0x40: embedded sub-object */
};

extern void FUN_08a44af8();
extern void FUN_08a44b84();
extern int FUN_08a45114();
extern void FUN_08a45f14();
extern int FUN_08a50fbc();
extern int FUN_08a52bb8();

void FUN_08a46124(struct Rec46124 *self)
{
  int found;

  found = FUN_08a50fbc();
  found = FUN_08a52bb8(found, &self->key_10);
  if (found != 0) {
    FUN_08a45114(self, self->unk_0c);
    FUN_08a44b84(self->sub_40);
    FUN_08a44af8(self->sub_40);
    FUN_08a45f14(self);
    return;
  }
  return;
}
