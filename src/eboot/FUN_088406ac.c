/* LBPMATCH module=EBOOT.BIN start=0x088406ac end=0x088406cc symbol=FUN_088406ac lang=c99 cc=gcc410-Os */
/* Mechanical translation of Ghidra pseudocode (lbpgen.py tag g1); exact match verified; names and types await human review.; readability pass (lane rd4d, Claude Sonnet) */
struct PtrHolder {
  char unk_00[0x10];
  int *unk_10;
};

extern void FUN_088050b8();

/* Takes the pointer at +0x10, clears the field, then hands the pointer to FUN_088050b8. */
void FUN_088406ac(struct PtrHolder *self)
{
  int *ptr;

  ptr = self->unk_10;
  if (ptr != 0) {
    self->unk_10 = 0;
    FUN_088050b8(ptr);
    return;
  }
  return;
}
