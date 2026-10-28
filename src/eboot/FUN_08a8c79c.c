/* LBPMATCH module=EBOOT.BIN start=0x08a8c79c end=0x08a8c808 symbol=FUN_08a8c79c lang=c99 cc=gcc402x-Os */
/* Mechanical translation of Ghidra pseudocode (lbpgen.py tag g6); exact match verified; names and types await human review; readability pass (lane rd2b, Claude Sonnet) */
struct Obj318Owner {
  char unk_000[0x2e8];
  unsigned int key;            /* +0x2e8: looked up in the registry below */
  char unk_2ec[0x2c];
  unsigned int result;         /* +0x318: value the registry returned for key */
};

extern void *FUN_08a50fbc();          /* returns a global registry pointer */
extern unsigned int FUN_08a52a88();   /* registry lookup: (registry, category, &key) -> value */
extern void FUN_08a9bff8();           /* releases the buffer a FUN_08a9d390 temporary holds at +8 */
extern void *FUN_08a9d390();

#define REGISTRY_CATEGORY 0x16        /* second argument of the lookup; meaning not yet known */

void FUN_08a8c79c(struct Obj318Owner *self)
{
  void *registry;
  unsigned int temp[6];     /* temporary built from the key and released again; its value is never read */
  unsigned int key[2];      /* only key[0] is used (the retail frame has the two-word array) */

  registry = FUN_08a50fbc();
  key[0] = self->key;
  FUN_08a9d390(temp, key[0]);
  FUN_08a9bff8(temp);
  self->result = FUN_08a52a88(registry, REGISTRY_CATEGORY, key);
}
