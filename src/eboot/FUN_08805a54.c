/* LBPMATCH module=EBOOT.BIN start=0x08805a54 end=0x08805ac8 symbol=FUN_08805a54 lang=c99 cc=gcc410-Os */
/* Mechanical translation of Ghidra pseudocode (lbpgen.py tag g4); exact match verified; names and types await human review.; readability pass (lane rd3a, Claude Sonnet) */
#include "lbp/rd3a_uintmap.h"

extern struct UIntMapNode *FUN_08805014();
extern struct UIntMapNode *FUN_088058a8();

/* Lookup-or-insert on an unsigned-int keyed map: returns the address of the mapped value.
   FUN_08805014 finds the first node not below the key; FUN_088058a8 inserts a default-valued entry. */
void *FUN_08805a54(struct UIntMap *map, unsigned int *key)
{
  struct UIntMapNode *node;
  struct UIntMapPair entry;

  node = FUN_08805014(map, key);
  if (node == &map->end_node || *key < node->key) {
    entry.key = *key;
    entry.value[0] = 0;
    node = FUN_088058a8(map, node, &entry);
  }
  return (char *)node + UINTMAP_VALUE_OFFSET;
}
