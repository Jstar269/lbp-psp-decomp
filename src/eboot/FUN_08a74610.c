/* LBPMATCH module=EBOOT.BIN start=0x08a74610 end=0x08a74690 symbol=FUN_08a74610 lang=c99 cc=gcc402x-O2 */
/* Mechanical translation of Ghidra pseudocode (lbpgen.py tag g8); exact match verified; names and types await human review.; readability pass (lane rd3b, Claude Sonnet) */

struct Flagged {
  unsigned int flags;
};

struct Registry {
  unsigned int unk_00;
  struct Flagged *unk_04;
};

struct Obj {
  int (**vtable)();
};

extern struct Registry *FUN_08a10f1c();

/* 1 when the object's vtable slot 0x94 result equals the registry's unk_04 and has flag 0x40 set. */
int FUN_08a74610(struct Obj *self)
{
  struct Flagged *kind;
  struct Registry *registry;
  struct Flagged *flagged;

  kind = (struct Flagged *)self->vtable[0x94 / 4](self);
  registry = FUN_08a10f1c();
  if (kind == registry->unk_04) {
    flagged = (struct Flagged *)self->vtable[0x94 / 4](self);
    if ((flagged->flags & 0x40) != 0) {
      return 1;
    }
  }
  return 0;
}
