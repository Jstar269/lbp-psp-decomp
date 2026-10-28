/* LBPMATCH module=EBOOT.BIN start=0x0891048c end=0x089104b4 symbol=FUN_0891048c lang=c99 cc=gcc410-Os */
/* Mechanical translation of Ghidra pseudocode (lbpgen.py tag g2); exact match verified; names and types await human review.; readability pass (lane rd3c, Claude Sonnet) */
/* A table of 20 pointer-sized slots that starts out empty, plus a flag byte that is set on reset. */
struct SlotTable {
  unsigned int unk_00[2];
  unsigned char flag_08;
  int slot[20];            /* +0xc */
};

void FUN_0891048c(struct SlotTable *table)
{
  int count = 0;
  struct SlotTable *cursor = table;   /* advances one word per pass, as the retail loop does */

  do {
    count = count + 1;
    cursor->slot[0] = 0;
    cursor = (struct SlotTable *)((char *)cursor + 4);
  } while (count != 20);
  table->flag_08 = 1;
}
