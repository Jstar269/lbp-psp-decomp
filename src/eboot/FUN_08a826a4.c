/* LBPMATCH module=EBOOT.BIN start=0x08a826a4 end=0x08a826e8 symbol=FUN_08a826a4 lang=c99 cc=gcc402x-O2 */
/* Mechanical translation of Ghidra pseudocode (lbpgen.py tag g8); exact match verified; names and types await human review.; readability pass (lane rd4d, Claude Sonnet) */
struct Globals {
  char unk_00[0x28];
  int unk_28;
};

struct Obj {
  char unk_00[0xa0];
  unsigned char unk_a0;
  char unk_a1[3];
  int unk_a4;
};

extern void FUN_0897d7d0();
extern struct Globals *FUN_089f683c();

/* When the byte at +0xa0 is set and the word at +0xa4 is 7, passes the word at +0x28 of the FUN_089f683c result on. */
void FUN_08a826a4(struct Obj *self)
{
  struct Globals *globals;

  if ((self->unk_a0 != 0) && (self->unk_a4 == 7)) {
    globals = FUN_089f683c();
    FUN_0897d7d0(globals->unk_28);
    return;
  }
  return;
}
