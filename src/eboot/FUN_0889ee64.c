/* LBPMATCH module=EBOOT.BIN start=0x0889ee64 end=0x0889eeb8 symbol=FUN_0889ee64 lang=c99 cc=gcc402x-Os */
/* Mechanical translation of Ghidra pseudocode (lbpgen.py tag g6); exact match verified; names and types await human review.; readability pass (lane rd4b, Claude Sonnet) */
struct Buffer {
  void *data;            /* +0: allocation of `size` bytes, zero-filled */
  int unk_04;
  unsigned int size;     /* +8 */
};

extern void *memset(void *dst, int value, unsigned int count);
extern void FUN_0889df18(struct Buffer *self);
extern void *FUN_08a9e4a4(unsigned int size, int arg1, int arg2);

void FUN_0889ee64(struct Buffer *self, unsigned int size)
{
  void *data;

  FUN_0889df18(self);
  data = FUN_08a9e4a4(size, 0, 0);
  self->data = data;
  self->size = size;
  memset(data, 0, size);
  return;
}
