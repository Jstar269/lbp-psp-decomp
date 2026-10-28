/* LBPMATCH module=EBOOT.BIN start=0x0881138c end=0x088113ac symbol=FUN_0881138c lang=c99 cc=gcc171-Os */
/* Mechanical translation of Ghidra pseudocode (lbpgen.py tag g3); exact match verified; names and types await human review.; readability pass (lane rd3b, Claude Sonnet) */

struct Obj {
  char pad_00[0xc];
  unsigned int unk_0c[3];
  unsigned int unk_18;
  unsigned int unk_1c;
};

void FUN_0881138c(struct Obj *self)
{
  unsigned int *word;
  int remaining;

  word = self->unk_0c;
  remaining = 3;
  do {
    remaining--;
    *word = 0;
    word++;
  } while (remaining != 0);
  self->unk_1c = 0;
}
