/* LBPMATCH module=EBOOT.BIN start=0x08a51e74 end=0x08a51eb8 symbol=FUN_08a51e74 lang=c99 cc=gcc402x-Os */
/* Mechanical translation of Ghidra pseudocode (lbpgen.py tag g6); exact match verified; names and types await human review.; readability pass (lane rd3a, Claude Sonnet) */
#include "lbp/rd3a_uintmap.h"

extern struct UIntMapNode32 *FUN_08a51234();

struct MapOwner {
  unsigned char unk_00[0xc44];
  struct UIntMap map;   /* +0xc44 */
};

/* Looks the key up in the map embedded at +0xc44 (FUN_08a51234 finds the first node not below the key);
   returns the mapped word, or 0 when the end node comes back. */
unsigned int FUN_08a51e74(struct MapOwner *self, unsigned int key)
{
  struct UIntMapNode32 *node;
  unsigned int result;
  unsigned int key_copy[4];

  key_copy[0] = key;
  node = FUN_08a51234(&self->map, key_copy);
  result = 0;
  if (&node->node != &self->map.end_node) {
    result = node->value;
  }
  return result;
}
