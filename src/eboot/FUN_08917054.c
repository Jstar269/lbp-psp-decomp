/* LBPMATCH module=EBOOT.BIN start=0x08917054 end=0x089170c4 symbol=FUN_08917054 lang=c99 cc=gcc402x-Os */
/* Mechanical translation of Ghidra pseudocode (lbpgen.py tag g6); exact match verified; names and types await human review.; readability pass (lane rd3d, Claude Sonnet) */
/* Calls FUN_08916e64(DAT_08bef4b0, index) for every in-use entry (first word non-zero) of the table
   DAT_08bef4b4, which has DAT_08bef4d0 entries of 0x10 bytes. */
struct TableEntry {
  int used;                /* +0 */
  int unk_04;
  int unk_08;
  int unk_0c;
};

extern int *DAT_08bef4b0;
extern struct TableEntry *DAT_08bef4b4;
extern int DAT_08bef4d0;
extern void FUN_08916e64();

void FUN_08917054(void)
{
  int *context;
  int next_index;
  int index;

  context = DAT_08bef4b0;
  next_index = 0;
  while (index = next_index, index < DAT_08bef4d0) {
    next_index = index + 1;
    if (DAT_08bef4b4[index].used != 0) {
      FUN_08916e64(context, index);
    }
  }
  return;
}
