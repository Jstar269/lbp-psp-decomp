/* LBPMATCH module=EBOOT.BIN start=0x089ed9ec end=0x089eda34 symbol=FUN_089ed9ec lang=c99 cc=gcc410-Os */
/* Mechanical translation of Ghidra pseudocode (lbpgen.py tag g2); exact match verified; names and types await human review.; readability pass (lane rd3a, Claude Sonnet) */
#include "lbp/rd3a_uintmap.h"

extern struct UIntMap DAT_08bf370c;
extern struct UIntMapNode *FUN_089ed98c();

/* Looks the key up in the global map (FUN_089ed98c finds the first node not below the key).
   Returns the word the mapped pointer refers to, or -1 when the end node is returned. */
int FUN_089ed9ec(unsigned int key)
{
  struct UIntMapNode *node;
  int result;
  unsigned int key_copy[4];

  key_copy[0] = key;
  node = FUN_089ed98c(&DAT_08bf370c, key_copy);
  result = -1;
  if (node != &DAT_08bf370c.end_node) {
    result = **(int **)((char *)node + UINTMAP_VALUE_OFFSET);
  }
  return result;
}
