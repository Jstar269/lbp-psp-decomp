/* LBPMATCH module=EBOOT.BIN start=0x08b89984 end=0x08b899e4 symbol=FUN_08b89984 lang=c99 cc=gcc402x-O2 */
/* Mechanical translation of Ghidra pseudocode (lbpgen.py tag g8); exact match verified; names and types await human review.; readability pass (lane rd1a, Claude Sonnet) */

/* Node links as word indexes; see FUN_08b89924 (same layout, mirror image of its rotation). */
#define PARENT(n) (((int *)(n))[1])
#define LEFT(n) (((int *)(n))[2])
#define RIGHT(n) (((int *)(n))[3])

/* Red-black tree right rotation: the left child of node takes its place; *root is updated when node was the root. */
void FUN_08b89984(int node, int *root)
{
  int inner;
  int child;

  child = LEFT(node);
  inner = RIGHT(child);
  LEFT(node) = inner;
  if (inner != 0) {
    PARENT(inner) = node;
  }
  PARENT(child) = PARENT(node);
  if (node == *root) {
    *root = child;
    PARENT(node) = child;
    RIGHT(child) = node;
    return;
  }
  inner = PARENT(node);
  if (node == RIGHT(inner)) {
    RIGHT(inner) = child;
    PARENT(node) = child;
    RIGHT(child) = node;
    return;
  }
  LEFT(inner) = child;
  PARENT(node) = child;
  RIGHT(child) = node;
}
