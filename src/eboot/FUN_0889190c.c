/* LBPMATCH module=EBOOT.BIN start=0x0889190c end=0x0889193c symbol=FUN_0889190c lang=c99 cc=gcc171-Os */
/* Mechanical translation of Ghidra pseudocode (lbpgen.py tag g3); exact match verified; names and types await human review.; readability pass (lane rd4d, Claude Sonnet) */
struct Obj {
  int unk_00;
  int unk_04;
  int unk_08;
  int unk_0c;
  char unk_10[0x28];
  int unk_38;
};

extern int FUN_08ad13f8();

/* True when FUN_08ad13f8 (given the members at +8 and +0xc, the word at +0x38 and the first word) returns 0. */
unsigned char FUN_0889190c(struct Obj *self)
{
  int status;

  status = FUN_08ad13f8(&self->unk_08, &self->unk_0c, self->unk_38, self->unk_00);
  return status == 0;
}
