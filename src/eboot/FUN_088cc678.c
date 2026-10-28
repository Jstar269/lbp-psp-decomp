/* LBPMATCH module=EBOOT.BIN start=0x088cc678 end=0x088cc6d8 symbol=FUN_088cc678 lang=c99 cc=gcc171-Os */
/* Mechanical translation of Ghidra pseudocode (lbpgen.py tag g3); exact match verified; names and types await human review; readability pass (lane rd2b, Claude Sonnet) */
/* Object with a vtable pointer first; only slot 1 (offset +4) is called here. */
struct VObject;
struct VTable {
  void *slot_0;
  void (*slot_1)(struct VObject *self);
};
struct VObject {
  const struct VTable *vtable;
};

/* Object holding two sub-objects at +0x18 and +0x1c. */
struct PairHolder {
  char unk_00[0x18];
  struct VObject *first;
  struct VObject *second;
};

/* Calls slot 1 of each held sub-object and clears the pointer. */
void FUN_088cc678(struct PairHolder *self)
{
  struct VObject *obj;

  obj = self->first;
  if (obj != 0) {
    obj->vtable->slot_1(obj);
    self->first = 0;
  }
  obj = self->second;
  if (obj != 0) {
    obj->vtable->slot_1(obj);
    self->second = 0;
  }
}
