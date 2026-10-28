/* LBPMATCH module=EBOOT.BIN start=0x0880c2dc end=0x0880c31c symbol=FUN_0880c2dc lang=c99 cc=gcc171-Os */
/* Mechanical translation of Ghidra pseudocode (lbpgen.py tag g3); exact match verified; names and types await human review.; readability pass (lane rd4b, Claude Sonnet) */
struct Obj {
  char pad_00[0x5ec];
  char unk_5ec[4];   /* container searched below */
  char unk_5f0[4];   /* its end marker: FUN_0880c280 returns this address when the key is absent */
};

struct Key {
  char pad_00[4];
  unsigned int key;   /* +4 */
};

extern void *FUN_0880c280(void *container, unsigned int *key);

unsigned char FUN_0880c2dc(struct Obj *self, struct Key *other)
{
  void *found;
  unsigned int key[4];

  key[0] = other->key;
  found = FUN_0880c280(self->unk_5ec, key);
  return found != (void *)self->unk_5f0;
}
