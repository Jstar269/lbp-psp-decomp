/* LBPMATCH module=EBOOT.BIN start=0x08918988 end=0x089189b4 symbol=FUN_08918988 lang=c99 cc=gcc410-Os */
/* Mechanical translation of Ghidra pseudocode (lbpgen.py tag g2); exact match verified; names and types await human review.; readability pass (lane rd4b, Claude Sonnet) */
struct Obj {
  char pad_00[4];
  int value;              /* +4 */
  unsigned int unk_08;    /* when non-zero (and unk_0c is set) the new value is forwarded to FUN_08ac98dc */
  unsigned char unk_0c;
};

extern void FUN_08ac98dc(unsigned int arg0, int value, int arg2);

void FUN_08918988(struct Obj *self, int value)
{
  self->value = value;
  if ((self->unk_0c != 0) && (self->unk_08 != 0)) {
    FUN_08ac98dc(self->unk_08, value, 0);
    return;
  }
  return;
}
