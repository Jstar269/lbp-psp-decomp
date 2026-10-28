/* LBPMATCH module=EBOOT.BIN start=0x0880cf2c end=0x0880cfa8 symbol=FUN_0880cf2c lang=c99 cc=gcc402x-Os */
/* Mechanical translation of Ghidra pseudocode (lbpgen.py tag g6); exact match verified; names and types await human review; readability pass (lane rd2b, Claude Sonnet) */
#include "lbp/rd2b_rbkeymap.h"

/* Holder of three keyed trees, at +0x18, +0x58 and +0x90 (only these offsets are used here). */
struct TripleMapHolder {
  char unk_00[0x18];
  struct RbU32Map map_18;
  char unk_30[0x28];
  struct RbU32Map map_58;
  char unk_70[0x20];
  struct RbU32Map map_90;
};

/* An entry whose search key sits at +4. */
struct KeyedEntry {
  unsigned int unk_00;
  unsigned int key;
};

/* Each of these searches a tree for the key and returns its header (end) when nothing is found. */
extern struct RbU32Node *FUN_0880c5ec();
extern struct RbU32Node *FUN_0880c640();
extern struct RbU32Node *FUN_0880ced8();

/* Returns 1 when the entry's key is found in any of the three trees, 0 when in none. */
unsigned int FUN_0880cf2c(struct TripleMapHolder *self, struct KeyedEntry *entry)
{
  unsigned int *key;
  struct RbU32Node *hit;

  key = &entry->key;
  hit = FUN_0880c5ec(&self->map_58, key);
  if (hit == &self->map_58.header) {
    hit = FUN_0880ced8(&self->map_18, key);
    if ((hit == &self->map_18.header) &&
        (hit = FUN_0880c640(&self->map_90, key), hit == &self->map_90.header)) {
      return 0;
    }
  }
  return 1;
}
