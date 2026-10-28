/* LBPMATCH module=EBOOT.BIN start=0x08870680 end=0x088706f4 symbol=FUN_08870680 lang=c99 cc=gcc410-Os */
/* Mechanical translation of Ghidra pseudocode (lbpgen.py tag g4); exact match verified; names and types await human review.; readability pass (lane rd3a, Claude Sonnet) */
#include "lbp/rd3a_uintmap.h"

extern struct UIntMapNode *FUN_0886f6e8();
extern struct UIntMapNode *FUN_088704d4();

/* Lookup-or-insert on an unsigned-int keyed map: returns the address of the mapped value.
   FUN_0886f6e8 finds the first node not below the key; FUN_088704d4 inserts a default-valued entry. */
void *FUN_08870680(struct UIntMap *map, unsigned int *key)
{
  struct UIntMapNode *node;
  struct UIntMapPair entry;

  node = FUN_0886f6e8(map, key);
  if (node == &map->end_node || *key < node->key) {
    entry.key = *key;
    entry.value[0] = 0;
    node = FUN_088704d4(map, node, &entry);
  }
  return (char *)node + UINTMAP_VALUE_OFFSET;
}
