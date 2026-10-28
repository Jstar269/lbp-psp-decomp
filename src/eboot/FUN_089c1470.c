/* LBPMATCH module=EBOOT.BIN start=0x089c1470 end=0x089c14d8 symbol=FUN_089c1470 lang=c99 cc=gcc402t-Os */
/* Mechanical translation of Ghidra pseudocode (lbpgen.py tag g5); exact match verified; names and types await human review; readability pass (lane rd2a, Claude Sonnet) */
#include "lbp/rd2a_entrytable.h"

struct SlotEntry {
  char unk_00[0x1c];
  int unk_1c;
  int *buffer;          /* +0x20: released through FUN_088050b8 */
  int unk_24;
};

struct EntryHolder {
  char unk_00[0x14];
  struct EntryTable *table;   /* +0x14 */
};

extern int DAT_08bf0380;
extern void FUN_088050b8();     /* release a buffer */
extern void FUN_089e15dc();     /* (DAT_08bf0380, &entry->buffer, entry->unk_1c) */

/* Takes the entry at the NEGATED selector (entries[-current]) and, if present, hands its buffer to
   FUN_089e15dc, releases it and clears the entry's buffer and +0x24 fields. */
void FUN_089c1470(struct EntryHolder *self)
{
  int *buffer;
  struct SlotEntry *entry;

  entry = (struct SlotEntry *)self->table->entries[-self->table->current];
  if (entry != 0) {
    FUN_089e15dc(DAT_08bf0380, &entry->buffer, entry->unk_1c);
    buffer = entry->buffer;
    entry->buffer = 0;
    if (buffer != 0) {
      FUN_088050b8(buffer);
    }
    entry->unk_24 = 0;
  }
}
