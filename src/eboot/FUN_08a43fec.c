/* LBPMATCH module=EBOOT.BIN start=0x08a43fec end=0x08a4402c symbol=FUN_08a43fec lang=c99 cc=gcc402x-O2 */
/* Mechanical translation of Ghidra pseudocode (lbpgen.py tag g8); exact match verified; names and types await human review.; readability pass (lane rd4c, Claude Sonnet) */

struct Item {
  char unk_00[0x44];
  int kind;              /* +0x44 */
};

/* True for kinds 4, 5, 0x17 and 0x38. The first argument is unused. */
unsigned int FUN_08a43fec(unsigned int unused, struct Item *item)
{
  int kind;

  kind = item->kind;
  if (kind == 0x17) {
    return 1;
  }
  if (kind < 0x18) {
    if (kind - 4U < 2) {
      return 1;
    }
  }
  else if (kind == 0x38) {
    return 1;
  }
  return 0;
}
