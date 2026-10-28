/* LBPMATCH module=EBOOT.BIN start=0x0891bf5c end=0x0891bfac symbol=FUN_0891bf5c lang=c99 cc=gcc410-Os */
/* Mechanical translation of Ghidra pseudocode (lbpgen.py tag g2); exact match verified; names and types await human review.; readability pass (lane rd3c, Claude Sonnet) */
/* Owned polymorphic object: vtable pointer first, a pointer member at +0xc. */
struct Owned {
  void **vtable;
  unsigned int unk_04;
  unsigned int unk_08;
  int *unk_0c;
};

struct Holder {
  char pad[0xa8];
  struct Owned *owned;      /* +0xa8 */
};

extern void FUN_08ac8e5c();

/* Releases the owned object: runs FUN_08ac8e5c on its +0xc member, calls its virtual slot 1, clears the pointer. */
void FUN_0891bf5c(struct Holder *self)
{
  struct Owned *obj;

  if (self->owned != 0) {
    FUN_08ac8e5c(self->owned->unk_0c);
    obj = self->owned;
    if (obj != 0) {
      ((void (*)(struct Owned *))obj->vtable[1])(obj);
    }
    self->owned = 0;
  }
}
