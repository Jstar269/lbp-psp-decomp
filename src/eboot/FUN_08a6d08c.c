/* LBPMATCH module=EBOOT.BIN start=0x08a6d08c end=0x08a6d0c8 symbol=FUN_08a6d08c lang=c99 cc=gcc402x-Os */
/* Mechanical translation of Ghidra pseudocode (lbpgen.py tag g6); exact match verified; names and types await human review.; readability pass (lane rd4c, Claude Sonnet) */

struct Object {
  char unk_00[0x2b8];
  unsigned char flag_2b8;
};

struct Singleton {
  char unk_00[0xf];
  unsigned char flag_0f;
};

extern struct Singleton *FUN_08918d48();
extern void FUN_08a6cf08();

/* Sets the flag at +0x2b8, sets the flag at +0xf of FUN_08918d48()'s result, then calls FUN_08a6cf08. */
void FUN_08a6d08c(struct Object *self)
{
  struct Singleton *other;

  self->flag_2b8 = 1;
  other = FUN_08918d48();
  other->flag_0f = 1;
  FUN_08a6cf08(self);
}
