/* LBPMATCH module=EBOOT.BIN start=0x08a5ff40 end=0x08a5ffdc symbol=FUN_08a5ff40 lang=c99 */
/* Hand-written reconstruction from the disassembly (lane lbp10a, Claude Sonnet 5.5); exact match verified; names and types await human review. Unaligned word store from __builtin_memcpy of a stack local (swl/swr). */
typedef struct Cursor {
  char pad0[4];
  char *ptr;
  char pad8[12];
  int count;
  char pad18[0x18];
  struct Mode *mode;
} Cursor;

typedef struct Stream { Cursor *cur; } Stream;

extern void FUN_08a34774(int *self, Stream *s, int tag);
extern void FUN_08a56ec8(int *self, Stream *s, int *owner);
extern void FUN_08a56b48(int *self, Stream *s, int *owner);
extern unsigned char FUN_08954cc4(struct Mode *m);
extern void FUN_0895541c(Stream *s);

void FUN_08a5ff40(int *self, Stream *s)
{
  FUN_08a34774(self, s, 0x53425247);
  FUN_08a56ec8(self + 0x2f, s, self);
  FUN_08a56b48(self + 0x94, s, self);
  Cursor *c = s->cur;
  int val = 0;
  if (!FUN_08954cc4(c->mode))
    __builtin_memcpy(c->ptr, &val, 4);
  c->ptr += 4;
  c->count += 4;
  FUN_0895541c(s);
}
