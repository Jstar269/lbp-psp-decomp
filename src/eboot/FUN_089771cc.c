/* LBPMATCH module=EBOOT.BIN start=0x089771cc end=0x0897725c symbol=FUN_089771cc lang=c99 cc=gcc402x-Os */
/* Mechanical translation of Ghidra pseudocode (lbpgen.py tag g6); exact match verified; names and types await human review; readability pass (lane rd1c, Claude Sonnet) */
struct Slot {
  unsigned int unk_00[5];
  unsigned int payload;       /* +0x14: released here, then cleared */
};

extern void FUN_08975c1c();
extern unsigned int *FUN_08976458();
extern unsigned int FUN_0897656c();
extern void FUN_08a9e0cc();

/* Returns 1 when the payload was released, 0 when FUN_0897656c returned nonzero and the payload was kept. */
unsigned int FUN_089771cc(struct Slot *self, void *other, unsigned char check_first)
{
  int blocked;
  unsigned int result;
  unsigned int payload;

  if ((check_first == '\0') || (blocked = FUN_0897656c(self, other), blocked == 0)) {
    payload = self->payload;
    if (payload != 0) {
      FUN_08975c1c(payload);
      FUN_08a9e0cc(payload);
    }
    self->payload = 0;
    FUN_08976458(self, other);
    result = 1;
  }
  else {
    FUN_08976458(self, other);
    result = 0;
  }
  return result;
}
