/* LBPMATCH module=EBOOT.BIN start=0x08a35244 end=0x08a352f8 symbol=FUN_08a35244 lang=c99 cc=gcc402x-O2 */
/* Mechanical translation of Ghidra pseudocode (lbpgen.py tag g8); exact match verified; names and types await human review; readability pass (lane rd1c, Claude Sonnet) */
struct TreeNode {
  char unk_00[0x14];
  unsigned int value;           /* +0x14 */
};

struct TreeMap {
  unsigned int unk_00;
  struct TreeNode header;       /* +4: the end() sentinel node */
};

extern struct TreeNode *FUN_08a34c20();   /* find: (tree, &key) -> node or the header node */
extern void FUN_08a9bff8();
extern unsigned int *FUN_08a9d390();

/* Replaces *key_io with the value mapped to it in tree, or with 0xffffffff when it is absent. */
void FUN_08a35244(unsigned int *key_io, struct TreeMap *tree)
{
  struct TreeNode *node;
  unsigned int value;
  unsigned int scratch_found[8];
  unsigned int scratch_missing[6];
  unsigned int key[2];

  key[0] = *key_io;
  node = FUN_08a34c20(tree, key);
  if (node != &tree->header) {
    value = node->value;
    FUN_08a9d390(scratch_found, value);
    FUN_08a9bff8(scratch_found);
    *key_io = value;
    return;
  }
  FUN_08a9d390(scratch_missing, 0xffffffff);
  FUN_08a9bff8(scratch_missing);
  *key_io = 0xffffffff;
  return;
}
