/* LBPMATCH module=EBOOT.BIN start=0x08a9b92c end=0x08a9b964 symbol=FUN_08a9b92c lang=c99 cc=gcc410-Os */
/* Mechanical translation of Ghidra pseudocode (lbpgen.py tag g2); exact match verified; names and types await human review.; readability pass (lane rd3c, Claude Sonnet) */
extern void *FUN_08b9e8cc();

/* Copies the bytes [first, last) so that they end at dest_end (overlap-safe copy FUN_08b9e8cc) and returns the new start. */
char *FUN_08a9b92c(char *first, char *last, char *dest_end)
{
  char *dest;

  dest = dest_end - (last - first);
  FUN_08b9e8cc(dest, first, last - first);
  return dest;
}
