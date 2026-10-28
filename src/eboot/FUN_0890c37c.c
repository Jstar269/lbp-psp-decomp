/* LBPMATCH module=EBOOT.BIN start=0x0890c37c end=0x0890c3cc symbol=FUN_0890c37c lang=c99 cc=gcc171-Os */
/* Mechanical translation of Ghidra pseudocode (lbpgen.py tag g3); exact match verified; names and types await human review.; readability pass (lane rd3d, Claude Sonnet) */
/* Frees the owned pointers at +0x40 and +0x38 (if set) with FUN_08a9e0cc and clears them. */
struct OwnsBuffers {
  char pad[0x38];
  unsigned int buffer_38;
  char pad2[4];
  unsigned int buffer_40;
};

extern void FUN_08a9e0cc();

void FUN_0890c37c(struct OwnsBuffers *self)
{
  if (self->buffer_40 != 0) {
    FUN_08a9e0cc(self->buffer_40);
    self->buffer_40 = 0;
  }
  if (self->buffer_38 != 0) {
    FUN_08a9e0cc(self->buffer_38);
    self->buffer_38 = 0;
  }
  return;
}
