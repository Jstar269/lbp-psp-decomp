/* LBPMATCH module=EBOOT.BIN start=0x089cc330 end=0x089cc3c4 symbol=FUN_089cc330 lang=c99 cc=gcc171-Os */
/* Mechanical translation of Ghidra pseudocode (lbpgen.py tag g10); exact match verified; names and types await human review; readability pass (lane rd2b, Claude Sonnet) */
#include "lbp/rd2b_flagsobj.h"

extern void *DAT_08befcac;                 /* object FUN_0895cba8 sets a boolean on */
extern struct FlagsObject *FUN_0895a96c(); /* accessor for the global flags object */
extern void FUN_0895cba8();                /* (object, boolean) */
extern unsigned int FUN_08974660();

/* The condition is evaluated as retail does, calling the accessor again for each flag test. */
unsigned int FUN_089cc330(int arg_a, int arg_b)
{
  struct FlagsObject *flags;

  flags = FUN_0895a96c();
  if ((flags->unk_50 == 0) ||
      ((flags = FUN_0895a96c(), flags->unk_51 != 0) &&
       (flags = FUN_0895a96c(), flags->unk_50 != 0))) {
    FUN_0895cba8(DAT_08befcac, 0);
    return FUN_08974660(arg_a, arg_b);
  }
  FUN_0895cba8(DAT_08befcac, 1);
  return 1;
}
