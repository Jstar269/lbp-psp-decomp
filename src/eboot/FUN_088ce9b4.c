/* LBPMATCH module=EBOOT.BIN start=0x088ce9b4 end=0x088ce9d8 symbol=FUN_088ce9b4 lang=c99 cc=gcc402x-O1 */
/* Mechanical translation of Ghidra pseudocode (lbpgen.py tag g13); exact match verified; names and types await human review.; readability pass (lane rd3b, Claude Sonnet) */

struct Table {
  unsigned int words[0x40];
  unsigned int unk_100;
  unsigned char unk_104;
};

/* Clear the whole structure. */
void FUN_088ce9b4(struct Table *self)
{
  unsigned int *word;
  int remaining;

  remaining = 0x40;
  word = self->words;
  do {
    remaining--;
    *word = 0;
    word++;
  } while (remaining != 0);
  self->unk_104 = 0;
  self->unk_100 = 0;
}
