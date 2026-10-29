/* LBPMATCH module=EBOOT.BIN start=0x08a6482c end=0x08a648e8 symbol=FUN_08a6482c lang=c99 */
/* Hand-written reconstruction from the disassembly (lane lbp10b, Sonnet 5.5); exact match verified; names and types await human review. */
/* Matching idiom: the value goes through an addressable local and __builtin_memcpy to the char* write pointer, which gives retail's stack slot plus swl/swr store. */
struct Stream { char pad0[4]; char *ptr; char pad1[12]; int count; char pad2[24]; void *owner; };
struct Obj2 { char pad0[0x24c]; int value; int pad1; int count; void *arr; };
extern void FUN_0895541c();
extern void FUN_08a34774();
extern void FUN_08a56ec8();
extern void FUN_08955588();
extern unsigned char FUN_08954cc4();

void FUN_08a6482c(struct Obj2 *self, int **stream)
{
  void *arr = self->arr;
  FUN_08a34774(self, stream, 0x59454b4c);
  FUN_08a56ec8((char *)self + 0xbc, stream, self);
  struct Stream *s = (struct Stream *)*stream;
  int v = self->value;
  if (FUN_08954cc4(s->owner) == 0) {
    __builtin_memcpy(s->ptr, &v, 4);
  }
  s->count += 4;
  s->ptr += 4;
  FUN_08955588(*stream, arr, self->count + 1, stream[2]);
  FUN_0895541c(stream);
}
