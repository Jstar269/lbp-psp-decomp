/* LBPMATCH module=EBOOT.BIN start=0x08a2d05c end=0x08a2d090 symbol=FUN_08a2d05c lang=c99 cc=gcc402x-Os */
/* Mechanical translation of Ghidra pseudocode (lbpgen.py tag g6); exact match verified; names and types await human review.; readability pass (lane rd3a, Claude Sonnet) */
extern struct SlotTable *DAT_08bf6a6c;
extern void FUN_08a2c4f4();

struct Slot {
  unsigned int unk_00;
  unsigned int unk_04;
  unsigned int unk_08;
};

/* Table object: one word followed by three 12-byte slots. */
struct SlotTable {
  unsigned int unk_00;
  struct Slot slots[3];
};

/* Records the table in a global, zeroes it, then calls FUN_08a2c4f4 on it. */
void FUN_08a2d05c(struct SlotTable *table)
{
  struct Slot *slot;
  int remaining;

  remaining = 3;
  slot = table->slots;
  DAT_08bf6a6c = table;
  table->unk_00 = 0;
  do {
    remaining = remaining - 1;
    slot->unk_00 = 0;
    slot->unk_04 = 0;
    slot->unk_08 = 0;
    slot = slot + 1;
  } while (remaining != 0);
  FUN_08a2c4f4(table);
}
