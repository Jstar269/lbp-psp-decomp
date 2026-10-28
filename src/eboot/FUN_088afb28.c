/* LBPMATCH module=EBOOT.BIN start=0x088afb28 end=0x088afb38 symbol=FUN_088afb28 lang=c99 cc=gcc410-Os */
/* Mechanical translation of Ghidra pseudocode (lbpgen.py tag g2); exact match verified; names and types await human review.; readability pass (lane rd4a, Claude Sonnet) */

/* Header of a record: a word, a halfword, and a byte flag at +0x2a that is cleared on init. */
struct Record {
  unsigned int value;
  unsigned short count;
  char unk_06[0x24];
  unsigned char flag_2a;
};

void FUN_088afb28(struct Record *self,unsigned int value,unsigned short count)
{
  self->value = value;
  self->count = count;
  self->flag_2a = 0;
  return;
}
