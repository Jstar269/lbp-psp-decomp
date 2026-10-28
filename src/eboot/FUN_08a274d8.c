/* LBPMATCH module=EBOOT.BIN start=0x08a274d8 end=0x08a27524 symbol=FUN_08a274d8 lang=c99 cc=gcc402x-O2 */
/* Mechanical translation of Ghidra pseudocode (lbpgen.py tag g8); exact match verified; names and types await human review.; readability pass (lane rd4d, Claude Sonnet) */
#define ELEM_COUNT 9

struct Elem {
  char unk_00[0xb0];
};

extern void FUN_08a289bc();

/* Runs FUN_08a289bc on each of 9 consecutive 0xb0-byte elements. */
void FUN_08a274d8(struct Elem *elem)
{
  int count;

  count = 0;
  do {
    count = count + 1;
    FUN_08a289bc(elem);
    elem = elem + 1;
  } while (count != ELEM_COUNT);
  return;
}
