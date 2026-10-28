/* LBPMATCH module=EBOOT.BIN start=0x0891edf8 end=0x0891ee6c symbol=FUN_0891edf8 lang=c99 cc=gcc410-Os */
/* Mechanical translation of Ghidra pseudocode (lbpgen.py tag g4); exact match verified; names and types await human review.; readability pass (lane rd3a, Claude Sonnet) */
#include "lbp/rd3a_uintmap.h"

extern struct UIntMapNode *FUN_0891dc4c();
extern struct UIntMapNode *FUN_0891ec4c();

/* Lookup-or-insert on an unsigned-int keyed map: returns the address of the mapped value.
   FUN_0891dc4c finds the first node not below the key; FUN_0891ec4c inserts a default-valued entry. */
void *FUN_0891edf8(struct UIntMap *map, unsigned int *key)
{
  struct UIntMapNode *node;
  struct UIntMapPair entry;

  node = FUN_0891dc4c(map, key);
  if (node == &map->end_node || *key < node->key) {
    entry.key = *key;
    entry.value[0] = 0;
    node = FUN_0891ec4c(map, node, &entry);
  }
  return (char *)node + UINTMAP_VALUE_OFFSET;
}
