/* LBPMATCH module=EBOOT.BIN start=0x0895945c end=0x089594f0 symbol=FUN_0895945c lang=c99 cc=gcc402x-Os */
/* Mechanical translation of Ghidra pseudocode (lbpgen.py tag g6); exact match verified; names and types await human review; readability pass (lane rd1c, Claude Sonnet) */
struct Iface;

/* Only the vtable slots this function uses are named; the rest are unknown. */
struct IfaceVtbl {
  int unk_00;
  void (*slot_04)(struct Iface *self, unsigned int arg, unsigned int out_word, int zero_a, int zero_b);
  char pad_08[0x1c];
  void (*slot_24)(struct Iface *self, int zero, int one);
  void (*slot_28)(struct Iface *self, int zero, int one);
  char pad_2c[0xc];
  void (*slot_38)(struct Iface *self, unsigned int *out, unsigned int arg);
};

struct Iface {
  const struct IfaceVtbl *vtbl;
};

struct Holder {
  int unk_00;
  struct Iface *target;     /* +4: the object every call goes to */
};

void FUN_0895945c(struct Holder *self, unsigned int arg)
{
  unsigned int out[4];

  self->target->vtbl->slot_24(self->target, 0, 1);
  self->target->vtbl->slot_28(self->target, 0, 1);
  self->target->vtbl->slot_38(self->target, out, arg);
  self->target->vtbl->slot_04(self->target, arg, out[0], 0, 0);
  return;
}
