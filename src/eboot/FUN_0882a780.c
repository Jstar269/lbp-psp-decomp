/* LBPMATCH module=EBOOT.BIN start=0x0882a780 end=0x0882a7a4 symbol=FUN_0882a780 lang=c99 cc=gcc410-Os */
/* Mechanical translation of Ghidra pseudocode (lbpgen.py tag g1); exact match verified; names and types await human review.; readability pass (lane rd3c, Claude Sonnet) */
struct Item {
  char pad[0x68];
  int unk_68;
  char pad2[0x1cc];
  unsigned char unk_238;
  char pad3[0x5f];
  unsigned char unk_298;
};

extern void FUN_0882a2b4();

/* Stores the new value, marks the item (+0x238), and runs FUN_0882a2b4 once if the +0x298 flag was set. */
void FUN_0882a780(struct Item *self, int value)
{
  self->unk_68 = value;
  self->unk_238 = 1;
  if (self->unk_298 != 0) {
    self->unk_298 = 0;
    FUN_0882a2b4(self);
  }
}
