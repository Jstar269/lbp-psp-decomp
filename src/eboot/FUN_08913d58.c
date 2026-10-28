/* LBPMATCH module=EBOOT.BIN start=0x08913d58 end=0x08913d74 symbol=FUN_08913d58 lang=c99 cc=gcc171-Os */
/* Mechanical translation of Ghidra pseudocode (lbpgen.py tag g3); exact match verified; names and types await human review.; readability pass (lane rd3b, Claude Sonnet) */

struct Obj {
  char pad_00[0x30];
  int unk_30;
};

extern unsigned char FUN_08918a18();

void FUN_08913d58(struct Obj *self)
{
  FUN_08918a18(self->unk_30);
}
