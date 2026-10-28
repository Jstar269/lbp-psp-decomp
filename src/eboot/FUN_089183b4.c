/* LBPMATCH module=EBOOT.BIN start=0x089183b4 end=0x089183e8 symbol=FUN_089183b4 lang=c99 cc=gcc171-Os */
/* Mechanical translation of Ghidra pseudocode (lbpgen.py tag g3); exact match verified; names and types await human review.; readability pass (lane rd4b, Claude Sonnet) */
extern int FUN_08ac980c(int arg);

/* The first parameter is unused. Stores FUN_08ac980c(arg) through `out` when `out` is not null. */
void FUN_089183b4(int unused, int arg, int *out)
{
  int value;

  if (out != 0) {
    value = FUN_08ac980c(arg);
    *out = value;
  }
  return;
}
