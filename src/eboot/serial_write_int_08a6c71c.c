/* LBPMATCH module=EBOOT.BIN start=0x08a6c71c end=0x08a6c7b8 symbol=FUN_08a6c71c lang=c99 */
/* Hand-written reconstruction from the disassembly (lane lbp10b, Sonnet 5.5); exact match verified; names and types await human review. */
/* Matching idiom: the value goes through an addressable local and __builtin_memcpy to the char* write pointer, which gives retail's stack slot plus swl/swr store. */
struct Stream { char pad0[4]; char *ptr; char pad1[12]; int count; char pad2[24]; void *owner; };
struct Obj { char pad0[0x98]; int value; char block[1]; };
extern void FUN_0895541c();
extern void FUN_08a34774();
extern void FUN_08954e6c();
extern unsigned char FUN_08954cc4();

void FUN_08a6c71c(struct Obj *self, struct Stream **stream)
{
  FUN_08a34774(self, stream, 0x53564f4d);
  struct Stream *s = *stream;
  int v = self->value;
  if (FUN_08954cc4(s->owner) == 0) {
    __builtin_memcpy(s->ptr, &v, 4);
  }
  s->ptr += 4;
  s->count += 4;
  FUN_08954e6c(*stream, self->block, 1, 80);
  FUN_0895541c(stream);
}
