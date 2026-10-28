/* LBPMATCH module=EBOOT.BIN start=0x08b89924 end=0x08b89984 symbol=FUN_08b89924 lang=c99 cc=gcc402x-O2 */
/* Mechanical translation of Ghidra pseudocode (lbpgen.py tag g8); exact match verified; names and types await human review.; readability pass (lane rd1a, Claude Sonnet) */

/* Node links as word indexes (node is a plain address: typing it as a struct pointer changes the schedule). The node
   layout is that of struct RbNode in lbp/rbnode.h: colour, parent, left, right. */
#define PARENT(n) (((int *)(n))[1])
#define LEFT(n) (((int *)(n))[2])
#define RIGHT(n) (((int *)(n))[3])

/* Red-black tree left rotation: the right child of node takes its place; *root is updated when node was the root. */
void FUN_08b89924(int node, int *root)
{
  int inner;
  int child;

  child = RIGHT(node);
  inner = LEFT(child);
  RIGHT(node) = inner;
  if (inner != 0) {
    PARENT(inner) = node;
  }
  PARENT(child) = PARENT(node);
  if (node == *root) {
    *root = child;
    PARENT(node) = child;
    LEFT(child) = node;
    return;
  }
  inner = PARENT(node);
  if (node == LEFT(inner)) {
    LEFT(inner) = child;
    PARENT(node) = child;
    LEFT(child) = node;
    return;
  }
  RIGHT(inner) = child;
  PARENT(node) = child;
  LEFT(child) = node;
}
