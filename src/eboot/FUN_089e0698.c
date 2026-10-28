/* LBPMATCH module=EBOOT.BIN start=0x089e0698 end=0x089e06a8 symbol=FUN_089e0698 lang=c99 cc=gcc410-Os */
/* Mechanical translation of Ghidra pseudocode (lbpgen.py tag g2); exact match verified; names and types await human review.; readability pass (lane rd3c, Claude Sonnet) */
struct Tracked {
  char pad[0xc];
  int current;
  int previous;
};

/* Stores a new value and keeps the one it replaces. */
void FUN_089e0698(struct Tracked *self, int value)
{
  int old = self->current;

  self->current = value;
  self->previous = old;
}
