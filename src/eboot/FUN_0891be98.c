/* LBPMATCH module=EBOOT.BIN start=0x0891be98 end=0x0891bee0 symbol=FUN_0891be98 lang=c99 cc=gcc171-Os */
/* Mechanical translation of Ghidra pseudocode (lbpgen.py tag g3); exact match verified; names and types await human review.; readability pass (lane rd4b, Claude Sonnet) */
struct Buffer {
  char pad_00[4];
  void *data;           /* +4: allocation, or 0 when it failed */
  unsigned int size;    /* +8: requested size, or 0 when the allocation failed */
};

extern void *FUN_08a9e4a4(unsigned int size, int arg1, int arg2);

void FUN_0891be98(struct Buffer *self, unsigned int size)
{
  void *data;

  data = FUN_08a9e4a4(size, 0, 0);
  if (data == 0) {
    size = 0;
  }
  self->size = size;
  self->data = data;
  return;
}
