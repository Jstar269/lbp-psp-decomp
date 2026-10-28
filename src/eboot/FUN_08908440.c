/* LBPMATCH module=EBOOT.BIN start=0x08908440 end=0x08908504 symbol=FUN_08908440 lang=c99 cc=gcc402x-Os */
/* Mechanical translation of Ghidra pseudocode (lbpgen.py tag g6); exact match verified; names and types await human review; readability pass (lane rd1c, Claude Sonnet) */
/* Writes the five 32-bit words of a record to a stream, one write call per word. */
struct FiveWords {
  unsigned int w[5];
};

extern void FUN_0894b568();  /* (stream, buffer, element size, element count) */

void FUN_08908440(struct FiveWords *record, void *stream)
{
  unsigned int tail[3];
  unsigned int head;

  head = record->w[0];
  FUN_0894b568(stream, &head, 4, 1);
  head = record->w[1];
  FUN_0894b568(stream, &head, 4, 1);
  tail[0] = record->w[2];
  FUN_0894b568(stream, tail, 4, 1);
  tail[0] = record->w[3];
  FUN_0894b568(stream, tail, 4, 1);
  tail[0] = record->w[4];
  FUN_0894b568(stream, tail, 4, 1);
  return;
}
