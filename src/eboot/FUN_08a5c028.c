/* LBPMATCH module=EBOOT.BIN start=0x08a5c028 end=0x08a5c038 symbol=FUN_08a5c028 lang=c99 cc=gcc402x-O1 */
/* Mechanical translation of Ghidra pseudocode (lbpgen.py tag g13); exact match verified; names and types await human review.; readability pass (lane rd4d, Claude Sonnet) */
struct Obj {
  char unk_000[0x208];
  unsigned char unk_208;
  unsigned char unk_209;
  char unk_20a[0x1a];
  int unk_224;
};

void FUN_08a5c028(struct Obj *self)
{
  self->unk_209 = 0;
  self->unk_224 = 0;
  self->unk_208 = 0;
  return;
}
