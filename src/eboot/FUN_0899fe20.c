/* LBPMATCH module=EBOOT.BIN start=0x0899fe20 end=0x0899fe74 symbol=FUN_0899fe20 lang=c99 cc=gcc410-Os */
/* Mechanical translation of Ghidra pseudocode (lbpgen.py tag g2); exact match verified; names and types await human review.; readability pass (lane rd3d, Claude Sonnet) */
/* Marks the object at +0x30 (flag 0x200 in its flags word) and calls its virtual slot 0x24, then notifies the
   global DAT_08be85f8 if one is set. */
#define OBJ_FLAG_0x200 0x200

struct VObject {
  void **vtable;             /* +0 */
  unsigned int flags;        /* +4 */
};

struct Owner30 {
  char pad[0x30];
  struct VObject *object;    /* +0x30 */
};

extern int DAT_08be85f8;
extern void FUN_08967568();

void FUN_0899fe20(struct Owner30 *self)
{
  struct VObject *object;
  void (*slot_24)(struct VObject *);

  object = self->object;
  if (object != (struct VObject *)0x0) {
    slot_24 = (void (*)(struct VObject *))object->vtable[0x24 / 4];
    object->flags = object->flags | OBJ_FLAG_0x200;
    slot_24(object);
  }
  if (DAT_08be85f8 != 0) {
    FUN_08967568(DAT_08be85f8);
    return;
  }
  return;
}
