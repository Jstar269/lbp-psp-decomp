/* LBPMATCH module=EBOOT.BIN start=0x08a2d7f0 end=0x08a2d874 symbol=FUN_08a2d7f0 lang=c99 cc=gcc410-Os rodata=0x08bb08e8 */
/* Mechanical translation of Ghidra pseudocode (lbpgen.py tag g4); exact match verified; names and types await human review.; readability pass (lane rd4d, Claude Sonnet) */
#include "lbp/rd4d_globals.h"

struct Clock {
  char unk_00[0x24c];
  float unk_24c;
};

extern struct Clock *DAT_08bee648;
extern void FUN_089ea9e0();
extern void FUN_089eb1c4();
extern struct Rd4dGlobals *FUN_089ecaa8();
extern void FUN_08a23350();
extern void FUN_08a2337c();
extern void FUN_08a239e8();
extern void FUN_08a23adc();
extern void FUN_08a2478c();
extern void FUN_08a24a90();

/* Runs a fixed sequence of helpers, then advances the float at +0x24c of DAT_08bee648 by 1/30. */
void FUN_08a2d7f0(void)
{
  struct Rd4dGlobals *globals;

  FUN_08a2478c();
  FUN_08a24a90(1);
  FUN_08a23adc();
  globals = FUN_089ecaa8();
  FUN_089ea9e0(globals);
  FUN_08a23350(0);
  globals = FUN_089ecaa8();
  FUN_089eb1c4(globals);
  FUN_08a239e8(1);
  FUN_08a2337c();
  if (DAT_08bee648 != 0) {
    DAT_08bee648->unk_24c = DAT_08bee648->unk_24c + 0.033333335f;
  }
  return;
}
