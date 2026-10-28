/* LBPMATCH module=EBOOT.BIN start=0x088e6c10 end=0x088e6cb8 symbol=FUN_088e6c10 lang=c99 cc=gcc410-Os */
/* Mechanical translation of Ghidra pseudocode (lbpgen.py tag g4); exact match verified; names and types await human review.; readability pass (lane rd1b, Claude Sonnet) */

extern unsigned int DAT_08bf03b8;
extern int FUN_0896f06c();
extern struct Holder * FUN_08974aa4();

typedef struct Item {
  char pad_00[0x68];
  unsigned int unk_68;
} Item;

/* items[i - first_index] holds the entry for index i. */
typedef struct ItemTable {
  char pad_00[0x58];
  Item **items;
  short first_index;
} ItemTable;

typedef struct Holder {
  char pad_00[0x14];
  ItemTable *table;
} Holder;

/* Sets unk_68 to 0xffffff on the entries for index 10 (of holder 2) and index 11 (of holder 4), when present. */
void FUN_088e6c10(void)
{
  Item *item_b;
  Item *item_a;
  ItemTable *table;
  Holder *holder;
  int handle;

  handle = FUN_0896f06c(DAT_08bf03b8);
  holder = FUN_08974aa4(handle,2);
  table = holder->table;
  handle = FUN_0896f06c(DAT_08bf03b8);
  holder = FUN_08974aa4(handle,4);
  item_a = holder->table->items[0xb - holder->table->first_index];
  item_b = table->items[10 - table->first_index];
  if (item_a != 0) {
    item_a->unk_68 = 0xffffff;
  }
  if (item_b != 0) {
    item_b->unk_68 = 0xffffff;
  }
  return;
}
