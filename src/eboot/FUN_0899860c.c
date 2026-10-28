/* LBPMATCH module=EBOOT.BIN start=0x0899860c end=0x08998850 symbol=FUN_0899860c lang=c99 cc=gcc402x-Os */
/* Mechanical translation of Ghidra pseudocode (lbpgen.py tag g9); exact match verified; names and types await human review.; readability pass (lane rd1a, Claude Sonnet) */

/* Looks up a sub-object of self by kind with FUN_08974aa4, then passes one entry of its pointer table to
   FUN_089d4c58; the table is indexed relative to its index_base. Same sequence for ten fixed (kind, index) pairs,
   plus a final one when flag is set. */
struct Table0899860c {
  char pad[0x28];
  int **entries;
  short index_base;
};

struct Holder0899860c {
  char pad[0x14];
  struct Table0899860c *table;
};

extern struct Holder0899860c *FUN_08974aa4(void *self, int kind);
extern void FUN_089d4c58(int *entry);

void FUN_0899860c(void *self, unsigned char flag)
{
  struct Holder0899860c *holder;

  holder = FUN_08974aa4(self, 9);
  FUN_089d4c58(holder->table->entries[4 - holder->table->index_base]);
  holder = FUN_08974aa4(self, 15);
  FUN_089d4c58(holder->table->entries[18 - holder->table->index_base]);
  holder = FUN_08974aa4(self, 15);
  FUN_089d4c58(holder->table->entries[20 - holder->table->index_base]);
  holder = FUN_08974aa4(self, 15);
  FUN_089d4c58(holder->table->entries[19 - holder->table->index_base]);
  holder = FUN_08974aa4(self, 15);
  FUN_089d4c58(holder->table->entries[21 - holder->table->index_base]);
  holder = FUN_08974aa4(self, 9);
  FUN_089d4c58(holder->table->entries[8 - holder->table->index_base]);
  holder = FUN_08974aa4(self, 9);
  FUN_089d4c58(holder->table->entries[9 - holder->table->index_base]);
  holder = FUN_08974aa4(self, 9);
  FUN_089d4c58(holder->table->entries[6 - holder->table->index_base]);
  holder = FUN_08974aa4(self, 10);
  FUN_089d4c58(holder->table->entries[14 - holder->table->index_base]);
  holder = FUN_08974aa4(self, 10);
  FUN_089d4c58(holder->table->entries[13 - holder->table->index_base]);
  if (flag != 0) {
    holder = FUN_08974aa4(self, 1);
    FUN_089d4c58(holder->table->entries[-holder->table->index_base]);
  }
}
