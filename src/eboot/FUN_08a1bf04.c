/* LBPMATCH module=EBOOT.BIN start=0x08a1bf04 end=0x08a1bf2c symbol=FUN_08a1bf04 lang=c99 cc=gcc402x-O1 */
/* Mechanical translation of Ghidra pseudocode (lbpgen.py tag g13); exact match verified; names and types await human review.; readability pass (lane rd4c, Claude Sonnet) */

struct ZeroBlock {
  unsigned int word[9];
};

/* Clears all nine words. */
void FUN_08a1bf04(struct ZeroBlock *block)
{
  block->word[8] = 0;
  block->word[0] = 0;
  block->word[1] = 0;
  block->word[2] = 0;
  block->word[3] = 0;
  block->word[4] = 0;
  block->word[5] = 0;
  block->word[6] = 0;
  block->word[7] = 0;
}
