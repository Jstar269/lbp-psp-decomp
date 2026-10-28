/* LBPMATCH module=EBOOT.BIN start=0x089181e4 end=0x08918230 symbol=FUN_089181e4 lang=c99 cc=gcc402x-Os */
/* Mechanical translation of Ghidra pseudocode (lbpgen.py tag g6); exact match verified; names and types await human review; readability pass (lane rd2a, Claude Sonnet) */
#define FLAGS_FORWARDED 0xd   /* bits of the caller's flags passed on unchanged */
#define FLAG_IN 0x2           /* caller's flag that is turned into FLAG_OUT */
#define FLAG_OUT 0x10

extern unsigned int FUN_08ac9c40();   /* (arg2, flags, arg3, arg4, short5, short6): returns a value */

/* Thin wrapper: rewrites the flags word, forwards the call and, when `out` is non-null, stores the
   result there. unused_1, unused_7 and unused_8 are not used (they occupy argument slots). */
void FUN_089181e4(int unused_1, unsigned int arg2, int arg3, unsigned int arg4, short short5, short short6,
                  int unused_7, int unused_8, unsigned int flags, unsigned int *out)
{
  unsigned int new_flags;
  unsigned int result;

  new_flags = flags & FLAGS_FORWARDED | FLAG_OUT;
  if ((flags & FLAG_IN) == 0) {
    new_flags = flags & FLAGS_FORWARDED;
  }
  result = FUN_08ac9c40(arg2, new_flags, arg3, arg4, short5, short6);
  if (out != 0) {
    *out = result;
  }
}
