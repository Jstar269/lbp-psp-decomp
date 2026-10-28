/* LBPMATCH module=EBOOT.BIN start=0x08a372bc end=0x08a37300 symbol=FUN_08a372bc lang=c99 cc=gcc402x-Os */
/* Mechanical translation of Ghidra pseudocode (lbpgen.py tag g6); exact match verified; names and types await human review.; readability pass (lane rd3c, Claude Sonnet) */
struct Record {
  char pad[0x9c];
  char unk_9c[0x30];
  int unk_cc;
};

extern void FUN_08a3543c();
extern void FUN_08a5553c();

/* Copies the part of the record that FUN_08a3543c does not handle: the sub-block at +0x9c and the word at +0xcc. */
void FUN_08a372bc(struct Record *dest, struct Record *source, void *extra)
{
  FUN_08a3543c(dest, source, extra);
  FUN_08a5553c(source->unk_9c, dest->unk_9c);
  dest->unk_cc = source->unk_cc;
}
