/* LBPMATCH module=EBOOT.BIN start=0x088a0adc end=0x088a0b38 symbol=FUN_088a0adc lang=c99 cc=gcc410-Os */
/* Mechanical translation of Ghidra pseudocode (lbpgen.py tag g2); exact match verified; names and types await human review.; readability pass (lane rd3b, Claude Sonnet) */

struct Holder {
  char pad_00[8];
  void *buffer;
  char pad_0c[8];
  unsigned char owns_buffer;
};

extern void FUN_08a9e0c4();
extern void FUN_08a9e0cc();

/* Free the holder behind *ref (and its buffer when it owns one). *ref itself is left unchanged. */
void FUN_088a0adc(struct Holder **ref)
{
  struct Holder *holder;

  holder = *ref;
  if (holder == 0) {
    return;
  }
  if (holder->owns_buffer == 0) {
    holder->buffer = 0;
  }
  else {
    if (holder->buffer != 0) {
      FUN_08a9e0c4(holder->buffer);
    }
    holder->buffer = 0;
  }
  FUN_08a9e0cc(holder);
}
