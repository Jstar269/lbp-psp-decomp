/* LBPMATCH module=EBOOT.BIN start=0x08a69538 end=0x08a695b0 symbol=FUN_08a69538 lang=c99 cc=gcc402x-O2 */
/* Mechanical translation of Ghidra pseudocode (lbpgen.py tag g8); exact match verified; names and types await human review; readability pass (lane rd2a, Claude Sonnet) */
struct ScreenOwner {
  char unk_000[0x27c];
  unsigned int unk_27c;     /* +0x27c: forwarded to FUN_089ead84 */
};

extern struct ScreenOwner *DAT_08bf70b8;   /* remembers the last owner passed in */
extern void *DAT_08be85fc;
extern void *FUN_08970dbc();   /* (DAT_08be85fc, 0x85): looks up an entry by id */
extern void *FUN_089ecaa8();   /* the object FUN_089ead84 is called on */
extern void FUN_089ead84();    /* (obj, entry, value, 0x100, callback_a, callback_b, 0) */
extern void FUN_08a68fcc();    /* callback: an empty function (jr ra) */
extern void FUN_08a6908c();    /* callback */

/* Remembers `owner` in DAT_08bf70b8, then registers entry 0x85 with the two callbacks above. */
void FUN_08a69538(int unused, struct ScreenOwner *owner)
{
  void *entry;
  unsigned int value;
  void *target;

  DAT_08bf70b8 = owner;
  entry = FUN_08970dbc(DAT_08be85fc, 0x85);
  value = owner->unk_27c;
  target = FUN_089ecaa8();
  FUN_089ead84(target, entry, value, 0x100, FUN_08a68fcc, FUN_08a6908c, 0);
}
