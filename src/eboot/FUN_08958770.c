/* LBPMATCH module=EBOOT.BIN start=0x08958770 end=0x08958794 symbol=FUN_08958770 lang=c99 cc=gcc171-Os */
/* Mechanical translation of Ghidra pseudocode (lbpgen.py tag g3); exact match verified; names and types await human review.; readability pass (lane rd4c, Claude Sonnet) */

struct Link {
  char unk_00[0x10];
  unsigned char flag;            /* +0x10 */
};

struct Object {
  char unk_00[8];
  struct Link *link;             /* +8: may be null */
};

/* True when a link exists and its flag is set. */
unsigned int FUN_08958770(struct Object *self)
{
  unsigned int result;

  result = 1;
  if ((self->link == 0) || (self->link->flag == 0)) {
    result = 0;
  }
  return result;
}
