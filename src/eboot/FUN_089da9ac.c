/* LBPMATCH module=EBOOT.BIN start=0x089da9ac end=0x089da9fc symbol=FUN_089da9ac lang=c99 cc=gcc402x-Os */
/* Mechanical translation of Ghidra pseudocode (lbpgen.py tag g6); exact match verified; names and types await human review.; readability pass (lane rd3d, Claude Sonnet) */
/* Replaces the owned object at +0x48: the old one is released through virtual slot 4, then the update
   function FUN_089da888 runs. */
struct VObject {
  void **vtable;             /* +0 */
};

struct Owner48 {
  char pad[0x48];
  struct VObject *object;    /* +0x48 */
};

extern void FUN_089da888();

void FUN_089da9ac(struct Owner48 *self, struct VObject *new_object)
{
  struct VObject *old_object;

  old_object = self->object;
  if (old_object != (struct VObject *)0x0) {
    ((void (*)(struct VObject *))old_object->vtable[4 / 4])(old_object);
  }
  self->object = new_object;
  FUN_089da888(self);
  return;
}
