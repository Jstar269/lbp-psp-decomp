/* LBPMATCH module=EBOOT.BIN start=0x0896ae50 end=0x0896ae98 symbol=FUN_0896ae50 lang=c99 cc=gcc410-Os */
/* Mechanical translation of Ghidra pseudocode (lbpgen.py tag g2); exact match verified; names and types await human review.; readability pass (lane rd3a, Claude Sonnet) */
extern void FUN_0896a8c4();

struct StateRec {
  unsigned char unk_00[0x24];
  unsigned char flag_24;   /* +0x24 */
  unsigned char flag_25;   /* +0x25 */
  unsigned char unk_26;
  unsigned char state;     /* +0x27 */
};

/* Stores the new state; states 1 and 3 clear flag_24 and states 2 and 3 clear flag_25 (when they are 1). */
void FUN_0896ae50(struct StateRec *self, int state)
{
  if ((state == 1 || state == 3) && self->flag_24 == 1) {
    self->flag_24 = 0;
  }
  if (state - 2U < 2 && self->flag_25 == 1) {
    self->flag_25 = 0;
  }
  self->state = (unsigned char)state;
  FUN_0896a8c4(self);
}
