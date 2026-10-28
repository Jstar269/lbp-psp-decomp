/* LBPMATCH module=EBOOT.BIN start=0x08a9f7d8 end=0x08a9f84c symbol=FUN_08a9f7d8 lang=c99 cc=gcc410-Os */
/* Mechanical translation of Ghidra pseudocode (lbpgen.py tag g4); exact match verified; names and types await human review.; readability pass (lane rd3a, Claude Sonnet) */
#include "lbp/rd3a_uintmap.h"

extern struct UIntMapNode *FUN_08a9f478();
extern struct UIntMapNode *FUN_08a9f62c();

/* Lookup-or-insert on an unsigned-int keyed map: returns the address of the mapped value.
   FUN_08a9f478 finds the first node not below the key; FUN_08a9f62c inserts a default-valued entry. */
void *FUN_08a9f7d8(struct UIntMap *map, unsigned int *key)
{
  struct UIntMapNode *node;
  struct UIntMapPair entry;

  node = FUN_08a9f478(map, key);
  if (node == &map->end_node || *key < node->key) {
    entry.key = *key;
    entry.value[0] = 0;
    node = FUN_08a9f62c(map, node, &entry);
  }
  return (char *)node + UINTMAP_VALUE_OFFSET;
}
