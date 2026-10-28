/* LBPMATCH module=EBOOT.BIN start=0x08a148e8 end=0x08a14954 symbol=FUN_08a148e8 lang=c99 cc=gcc402x-O2 */
/* Mechanical translation of Ghidra pseudocode (lbpgen.py tag g8); exact match verified; names and types await human review.; readability pass (lane rd4c, Claude Sonnet) */

struct Object {
  char unk_00[0x94];
  float unk_94;
  char unk_98[4];
  float unk_9c;
};

extern void FUN_08a14210();
extern void FUN_08a14454();
extern void FUN_08a145d4();

/* Runs the handlers for the non-zero floats at +0x94 and +0x9c, then FUN_08a14210. */
void FUN_08a148e8(struct Object *self)
{
  if (self->unk_94 != 0.0f) {
    FUN_08a14454(self);
  }
  if (self->unk_9c != 0.0f) {
    FUN_08a145d4(self);
  }
  FUN_08a14210(self);
}
