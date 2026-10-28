/* LBPMATCH module=EBOOT.BIN start=0x089dd2bc end=0x089dd318 symbol=FUN_089dd2bc lang=c99 cc=gcc171-Os */
/* Mechanical translation of Ghidra pseudocode (lbpgen.py tag g3); exact match verified; names and types await human review.; readability pass (lane rd4c, Claude Sonnet) */

struct Target {
  char unk_00[0x48];
  void *unk_48;          /* +0x48: optional, handed to FUN_089dcee8 */
};

struct FlagWord {
  unsigned int unk_00;
  unsigned int flags;    /* +4 */
};

extern unsigned int FUN_089d361c();
extern void FUN_089dcee8();

/* When bit 11 of the flags is set and +0x48 is non-null, notify it first; then forward to FUN_089d361c. */
void FUN_089dd2bc(struct Target *self, struct FlagWord *info)
{
  if (((info->flags & 0x800) != 0) && (self->unk_48 != 0)) {
    FUN_089dcee8(self->unk_48, self);
  }
  FUN_089d361c(self, info);
}
