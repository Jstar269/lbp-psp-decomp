/* LBPMATCH module=EBOOT.BIN start=0x0896491c end=0x0896499c symbol=FUN_0896491c lang=c99 cc=gcc402x-Os */
/* Mechanical translation of Ghidra pseudocode (lbpgen.py tag g6); exact match verified; names and types await human review.; readability pass (lane rd4b, Claude Sonnet) */
#include "lbp/rd4b_dat08bf03b8.h"

struct Dat08be8480 {
  char pad_00[4];
  unsigned char unk_04;   /* +4: checked before the work below is done */
};

extern struct Dat08be8480 *DAT_08be8480;
extern struct Dat08bf03b8 *DAT_08bf03b8;
extern void FUN_08964514(unsigned int *pair);
extern void FUN_0896f85c(struct Dat08bf03b8 *arg0, int arg1, unsigned int arg2);

/* `pair` is cleared; when DAT_08be8480 exists and its flag at +4 is set, FUN_08964514 fills `pair` and both
   entries are then passed on to FUN_0896f85c. */
void FUN_0896491c(unsigned int *pair)
{
  struct Dat08be8480 *state;

  state = DAT_08be8480;
  pair[0] = 0;
  pair[1] = 0;
  if ((state != 0) && (state->unk_04 != 0)) {
    FUN_08964514(pair);
    FUN_0896f85c(DAT_08bf03b8, 0, pair[1]);
    FUN_0896f85c(DAT_08bf03b8, 0, pair[0]);
    return;
  }
  return;
}
