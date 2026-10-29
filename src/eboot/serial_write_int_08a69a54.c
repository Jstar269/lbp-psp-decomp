/* LBPMATCH module=EBOOT.BIN start=0x08a69a54 end=0x08a69aec symbol=FUN_08a69a54 lang=c99 */
/* Hand-written reconstruction from the disassembly (lane lbp10b, Sonnet 5.5); exact match verified; names and types await human review. */
/* Matching idiom: the value goes through an addressable local and __builtin_memcpy to the char* write pointer, which gives retail's stack slot plus swl/swr store. */
typedef struct { int v; } __attribute__((packed)) UInt;
struct Stream { char pad0[4]; char *ptr; char pad1[12]; int count; char pad2[24]; void *owner; };
struct Obj { char pad[0x24c]; int value; };
extern void FUN_0895541c();
extern void FUN_08a34774();
extern void FUN_08a56ec8();
extern unsigned char FUN_08954cc4();

void FUN_08a69a54(struct Obj *self, struct Stream **stream)
{
  FUN_08a34774(self, stream, 0x4b47414d);
  FUN_08a56ec8((char *)self + 0xbc, stream, self);
  struct Stream *s = *stream;
  int v = self->value;
  if (FUN_08954cc4(s->owner) == 0) {
    __builtin_memcpy(s->ptr, &v, 4);
  }
  s->ptr += 4;
  s->count += 4;
  FUN_0895541c(stream);
}
