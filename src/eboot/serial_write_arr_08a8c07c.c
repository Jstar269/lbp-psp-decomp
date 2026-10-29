/* LBPMATCH module=EBOOT.BIN start=0x08a8c07c end=0x08a8c170 symbol=FUN_08a8c07c lang=c99 cc=gcc404xs-O2 */
/* Hand-written reconstruction from the disassembly (lane lbp10b, Sonnet 5.5); exact match verified; names and types await human review. */
/* Matching idiom: the value goes through an addressable local and __builtin_memcpy to the char* write pointer, which gives retail's stack slot plus swl/swr store. */
struct Stream { char pad0[4]; char *ptr; char pad1[12]; int count; char pad2[24]; void *owner; };
struct Arr { int pad0; int count; void *data; };
struct Obj { char pad0[0x300]; struct Arr arr; };
extern void FUN_0895541c();
extern void FUN_08a34774();
extern void FUN_08a56ec8();
extern void FUN_08a56b48();
extern void FUN_08955588();
extern unsigned char FUN_08954cc4();

void FUN_08a8c07c(struct Obj *self, int **stream)
{
  FUN_08a34774(self, stream, 0x534b5453);
  FUN_08a56ec8((char *)self + 0xbc, stream, self);
  FUN_08a56b48((char *)self + 0x250, stream, self);
  struct Arr *a = &self->arr;
  if (a->count != 0) {
    FUN_08955588(*stream, a->data, a->count + 1, stream[2]);
  } else {
    struct Stream *s = (struct Stream *)*stream;
    int v = 0;
    if (FUN_08954cc4(s->owner) == 0) {
      __builtin_memcpy(s->ptr, &v, 4);
    }
    s->ptr += 4;
    s->count += 4;
  }
  FUN_0895541c(stream);
}
