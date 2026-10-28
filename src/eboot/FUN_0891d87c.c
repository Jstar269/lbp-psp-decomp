/* LBPMATCH module=EBOOT.BIN start=0x0891d87c end=0x0891d8bc symbol=FUN_0891d87c lang=c99 cc=gcc402x-Os */
/* Mechanical translation of Ghidra pseudocode (lbpgen.py tag g6); exact match verified; names and types await human review.; readability pass (lane rd4d, Claude Sonnet) */
struct Iface;

struct IfaceVtable {
  char unk_00[0x18];
  void (*slot_18)(struct Iface *self);
};

struct Iface {
  struct IfaceVtable *vtable;
};

struct Owner {
  char unk_00[0xb4];
  struct Iface *unk_b4;
};

extern void FUN_08aac034();

/* Calls virtual slot +0x18 of the object at +0xb4 when present, then FUN_08aac034. */
void FUN_0891d87c(struct Owner *self)
{
  struct Iface *iface;

  iface = self->unk_b4;
  if (iface != 0) {
    iface->vtable->slot_18(iface);
  }
  FUN_08aac034(self);
  return;
}
