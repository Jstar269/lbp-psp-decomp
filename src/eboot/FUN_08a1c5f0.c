/* LBPMATCH module=EBOOT.BIN start=0x08a1c5f0 end=0x08a1c648 symbol=FUN_08a1c5f0 lang=c99 cc=gcc410-Os */
/* Mechanical translation of Ghidra pseudocode (lbpgen.py tag g2); exact match verified; names and types await human review.; readability pass (lane rd3d, Claude Sonnet) */
/* Destroys the object owned at +0xa8: frees its buffer at +0x24 (FUN_08a9e0c4), tears down its member at
   +0xc (FUN_08a1b424), frees it (FUN_08a9e0cc) and clears the owner's pointer. */
struct Owned {
  char pad[0xc];
  char member_0c[0x18];      /* +0xc */
  unsigned int buffer_24;    /* +0x24 */
};

struct Owner {
  char pad[0xa8];
  struct Owned *owned;       /* +0xa8 */
};

extern void FUN_08a1b424();
extern void FUN_08a9e0c4();
extern void FUN_08a9e0cc();

void FUN_08a1c5f0(struct Owner *self)
{
  struct Owned *owned;

  owned = self->owned;
  if (owned != 0) {
    if (owned->buffer_24 != 0) {
      FUN_08a9e0c4(owned->buffer_24);
    }
    FUN_08a1b424(owned->member_0c);
    FUN_08a9e0cc(owned);
    self->owned = 0;
  }
  return;
}
