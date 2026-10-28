/* LBPMATCH module=EBOOT.BIN start=0x08895698 end=0x08895724 symbol=FUN_08895698 lang=c99 cc=gcc402x-Os */
/* Mechanical translation of Ghidra pseudocode (lbpgen.py tag g6); exact match verified; names and types await human review; readability pass (lane rd2a, Claude Sonnet) */
extern char *FUN_08882764();   /* returns a constant string */
extern char *FUN_08882770();   /* returns a second constant string */
extern unsigned short *FUN_08889048();   /* general lookup: (out, name, arg, scratch[4]) */
extern int FUN_08ba0d98();     /* strcmp-style three-way compare of two C strings */

/* Resolves `name` into a 16-bit value stored in *out. The two names returned by FUN_08882764 and
   FUN_08882770 map straight to 0; anything else goes through FUN_08889048. Returns out. */
unsigned short *FUN_08895698(unsigned short *out, const char *name, int arg)
{
  char *special;
  int scratch[4];

  special = FUN_08882764();
  if (FUN_08ba0d98(name, special) == 0) {
    *out = 0;
  }
  else {
    special = FUN_08882770();
    if (FUN_08ba0d98(name, special) == 0) {
      *out = 0;
    }
    else {
      FUN_08889048(out, name, arg, scratch);
    }
  }
  return out;
}
