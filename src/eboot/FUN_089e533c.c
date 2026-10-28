/* LBPMATCH module=EBOOT.BIN start=0x089e533c end=0x089e5380 symbol=FUN_089e533c lang=c99 cc=gcc402x-Os */
/* Mechanical translation of Ghidra pseudocode (lbpgen.py tag g6); exact match verified; names and types await human review.; readability pass (lane rd4c, Claude Sonnet) */

struct SourceObject {
  char unk_00[0xa8];
  int unk_a8;
};

struct SourceRef {
  struct SourceObject *object;   /* +0 */
};

struct SlotTable {
  char unk_00[0x310];
  unsigned int *entry[1];        /* +0x310: one word per index; length not known */
};

extern unsigned int *FUN_0899a3ec();

/* Stores FUN_0899a3ec(source->object->unk_a8) in slot `index` of the table. */
void FUN_089e533c(struct SlotTable *table, int index, struct SourceRef *source)
{
  unsigned int *value;

  value = FUN_0899a3ec(source->object->unk_a8);
  table->entry[index] = value;
}
