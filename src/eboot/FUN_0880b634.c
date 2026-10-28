/* LBPMATCH module=EBOOT.BIN start=0x0880b634 end=0x0880b6b0 symbol=FUN_0880b634 lang=c99 cc=gcc402x-Os */
/* Mechanical translation of Ghidra pseudocode (lbpgen.py tag g6); exact match verified; names and types await human review.; readability pass (lane rd1b, Claude Sonnet) */

extern int FUN_08a50fbc();
extern struct Node * FUN_08a52bb8();

typedef struct Node {
  char pad_00[0x44];
  int state;          /* 0xd is skipped when picking the result */
  char pad_48[0x48];
  unsigned int next_key;   /* key of the next node in the chain */
} Node;

/* Walk the chain starting at start's key; *out_node ends up as the last node whose state is not 0xd. Returns 1 if the chain had any node. */
int FUN_0880b634(int unused_0, Node *start, Node **out_node)
{
  Node *node;
  int result;
  int manager;
  unsigned int key[4];

  key[0] = start->next_key;
  manager = FUN_08a50fbc();
  node = FUN_08a52bb8(manager,key);
  result = 0;
  if (node != 0) {
    do {
      if (node->state != 0xd) {
        *out_node = node;
      }
      manager = FUN_08a50fbc();
      node = FUN_08a52bb8(manager,&node->next_key);
    } while (node != 0);
    result = 1;
  }
  return result;
}
