/* LBPMATCH module=EBOOT.BIN start=0x0880bef0 end=0x0880bf6c symbol=FUN_0880bef0 lang=c99 cc=gcc402t-Os */
/* Mechanical translation of Ghidra pseudocode (lbpgen.py tag g5); exact match verified; names and types await human review; readability pass (lane rd2b, Claude Sonnet) */
/* Registry entry as seen here: only the word at +0x44 is read. */
struct RegistryEntry {
  char unk_00[0x44];
  int unk_44;
};

#define INVALID_ID 0xffffffffu

extern int FUN_0880be24();
extern unsigned int FUN_08a34b44();               /* value -> id, INVALID_ID when it has none */
extern void *FUN_08a50fbc();                      /* returns a global registry pointer */
extern struct RegistryEntry *FUN_08a52bb8();      /* (registry, &id) -> entry, or null */

/* Returns `value` unchanged unless its id resolves to an entry whose word at +0x44 is 0x23;
   then the result of FUN_0880be24 for that entry replaces it. */
int FUN_0880bef0(void *context, int value)
{
  struct RegistryEntry *entry;
  unsigned int id;

  id = FUN_08a34b44(value);
  if (id != INVALID_ID) {
    entry = FUN_08a52bb8(FUN_08a50fbc(), &id);
    if ((entry != 0) && (entry->unk_44 == 0x23)) {
      value = FUN_0880be24(context, entry);
    }
  }
  return value;
}
