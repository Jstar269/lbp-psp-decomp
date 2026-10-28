/* LBPMATCH module=EBOOT.BIN start=0x0885a5d8 end=0x0885a600 symbol=FUN_0885a5d8 lang=c99 cc=gcc171-Os */
/* Mechanical translation of Ghidra pseudocode (lbpgen.py tag g3); exact match verified; names and types await human review.; readability pass (lane rd4c, Claude Sonnet) */

struct Link {
  char unk_00[4];
  int state;             /* +4 */
};

struct Object {
  char unk_00[200];
  struct Link *link;     /* +200: may be null */
};

/* True when a link exists and its state is not 6. */
unsigned int FUN_0885a5d8(struct Object *self)
{
  unsigned int result;

  result = 1;
  if ((self->link == 0) || (self->link->state == 6)) {
    result = 0;
  }
  return result;
}
