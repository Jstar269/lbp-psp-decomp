/* LBPMATCH module=EBOOT.BIN start=0x0880e5d0 end=0x0880e644 symbol=FUN_0880e5d0 lang=c99 cc=gcc410-Os */
/* Mechanical translation of Ghidra pseudocode (lbpgen.py tag g4); exact match verified; names and types await human review.; readability pass (lane rd3a, Claude Sonnet) */
#include "lbp/rd3a_uintmap.h"

extern struct UIntMapNode *FUN_0880c03c();
extern struct UIntMapNode *FUN_0880e424();

/* Lookup-or-insert on an unsigned-int keyed map: returns the address of the mapped value.
   FUN_0880c03c finds the first node not below the key; FUN_0880e424 inserts a default-valued entry. */
void *FUN_0880e5d0(struct UIntMap *map, unsigned int *key)
{
  struct UIntMapNode *node;
  struct UIntMapPair entry;

  node = FUN_0880c03c(map, key);
  if (node == &map->end_node || *key < node->key) {
    entry.key = *key;
    entry.value[0] = 0;
    node = FUN_0880e424(map, node, &entry);
  }
  return (char *)node + UINTMAP_VALUE_OFFSET;
}
