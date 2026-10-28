/* LBPMATCH module=EBOOT.BIN start=0x08916d40 end=0x08916d70 symbol=FUN_08916d40 lang=c99 cc=gcc402t-Os */
/* Mechanical translation of Ghidra pseudocode (lbpgen.py tag g5); exact match verified; names and types await human review.; readability pass (lane rd4c, Claude Sonnet) */

struct EntryHead {
  char unk_00[0x10];
  int unk_10;
};

struct TableEntry {            /* 16 bytes */
  struct EntryHead *head;        /* +0 */
  int unk_04;
  char *chars;                   /* +8 */
  int unk_0c;
};

extern struct TableEntry *DAT_08bef4b4;

/* First character of entry `index` when its head's count (+0x10) is positive, else 0. */
int FUN_08916d40(int index)
{
  struct TableEntry *entry;
  int result;

  entry = DAT_08bef4b4 + index;
  result = 0;
  if (0 < entry->head->unk_10) {
    result = (int)*entry->chars;
  }
  return result;
}
