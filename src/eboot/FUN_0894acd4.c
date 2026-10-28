/* LBPMATCH module=EBOOT.BIN start=0x0894acd4 end=0x0894ad08 symbol=FUN_0894acd4 lang=c99 cc=gcc410-Os */
/* Mechanical translation of Ghidra pseudocode (lbpgen.py tag g2); exact match verified; names and types await human review.; readability pass (lane rd3c, Claude Sonnet) */
struct Keyed {
  char pad[8];
  unsigned int key;         /* +8 */
};

struct Source {
  char pad[0x10];
  unsigned int value;       /* +0x10 */
};

extern char DAT_08bef988;
extern unsigned int *FUN_0883a940();

/* Stores source->value in the map entry (table at DAT_08bef988) found, or created, for self->key. */
void FUN_0894acd4(struct Keyed *self, struct Source *source)
{
  unsigned int *slot;
  unsigned int value;

  value = source->value;
  slot = FUN_0883a940(&DAT_08bef988, &self->key);
  *slot = value;
}
