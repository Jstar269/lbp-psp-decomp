/* LBPMATCH module=EBOOT.BIN start=0x08839a4c end=0x08839ab4 symbol=FUN_08839a4c lang=c99 cc=gcc402t-Os */
/* Mechanical translation of Ghidra pseudocode (lbpgen.py tag g5); exact match verified; names and types await human review; readability pass (lane rd2b, Claude Sonnet) */
#include "lbp/rd2b_flagsobj.h"

struct StateObject {
  char unk_00[0x10];
  int unk_10;                  /* compared with 0 and 10 */
  char unk_14[0x78];
  unsigned char unk_8c;
  unsigned char unk_8d;
};

extern struct FlagsObject *FUN_0895a96c();   /* accessor for the global flags object */

/* Returns 0 only when the global flag at +0x50 is clear, unk_10 is 0 or 10, and both byte flags are clear. */
unsigned int FUN_08839a4c(struct StateObject *self)
{
  struct FlagsObject *flags;
  unsigned char flag;

  flags = FUN_0895a96c();
  if (flags->unk_50 == 0) {
    if (self->unk_10 == 0) {
      flag = self->unk_8c;
    }
    else {
      if (self->unk_10 != 10) {
        return 1;
      }
      flag = self->unk_8c;
    }
    if ((flag == 0) && (self->unk_8d == 0)) {
      return 0;
    }
  }
  return 1;
}
