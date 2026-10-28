/* LBPMATCH module=EBOOT.BIN start=0x0897a4a4 end=0x0897a53c symbol=FUN_0897a4a4 lang=c99 cc=gcc402x-Os */
/* Mechanical translation of Ghidra pseudocode (lbpgen.py tag g6); exact match verified; names and types await human review; readability pass (lane rd1c, Claude Sonnet) */
struct VObject;

/* Vtable layout as far as this function needs it: slot 1 is the destructor. */
struct VObjectVtbl {
  void *unk_00;
  void (*destroy)(struct VObject *self);
};

struct VObject {
  const struct VObjectVtbl *vtbl;
};

/* Object that owns two heap objects (at +4 and +8). */
struct OwnerOfTwo {
  int unk_00;
  struct VObject *first;
  struct VObject *second;
};

extern unsigned int DAT_08bf03b8;
extern void FUN_0896f07c();

void FUN_0897a4a4(struct OwnerOfTwo *self)
{
  /* Each owned object is passed to FUN_0896f07c first, then destroyed through its vtable and cleared. */
  if (self->first != 0) {
    FUN_0896f07c(DAT_08bf03b8, 1, self->first);
    if (self->first != 0) {
      self->first->vtbl->destroy(self->first);
    }
    self->first = 0;
  }
  if (self->second != 0) {
    FUN_0896f07c(DAT_08bf03b8, 1, self->second);
    if (self->second != 0) {
      self->second->vtbl->destroy(self->second);
    }
    self->second = 0;
  }
  return;
}
