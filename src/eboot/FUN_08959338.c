/* LBPMATCH module=EBOOT.BIN start=0x08959338 end=0x089593a4 symbol=FUN_08959338 lang=c99 cc=gcc402x-Os */
/* Mechanical translation of Ghidra pseudocode (lbpgen.py tag g6); exact match verified; names and types await human review.; readability pass (lane rd3d, Claude Sonnet) */
/* Tears down a holder of a buffer and an object: calls virtual slot 0x48 (with 2) and then slot 0x10 of the
   object, clears the object pointer, and frees the buffer with FUN_08a9e0c4 when set. */
struct VObject {
  void **vtable;             /* +0 */
};

struct Holder {
  unsigned int buffer;       /* +0 */
  struct VObject *object;    /* +4 */
};

extern void FUN_08a9e0c4();

void FUN_08959338(struct Holder *self)
{
  struct VObject *object;

  ((void (*)(struct VObject *, int))self->object->vtable[0x48 / 4])(self->object, 2);
  object = self->object;
  if (object != (struct VObject *)0x0) {
    ((void (*)(struct VObject *))object->vtable[0x10 / 4])(object);
  }
  self->object = 0;
  if (self->buffer != 0) {
    FUN_08a9e0c4(self->buffer);
  }
  self->buffer = 0;
  return;
}
