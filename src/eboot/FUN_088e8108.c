/* LBPMATCH module=EBOOT.BIN start=0x088e8108 end=0x088e8154 symbol=FUN_088e8108 lang=c99 cc=gcc171-Os */
/* Mechanical translation of Ghidra pseudocode (lbpgen.py tag g3); exact match verified; names and types await human review.; readability pass (lane rd3c, Claude Sonnet) */
#include "lbp/rd3c_vobject.h"

struct Entry {
  char pad[0x14];
  struct VObject *object;   /* +0x14 */
};

extern char DAT_08beedf4;
extern struct Entry *FUN_088e7604();

/* Looks the id up in the table at DAT_08beedf4 and calls virtual slot 2 of the object found there. */
void FUN_088e8108(unsigned int *id, int arg)
{
  struct Entry *entry;
  unsigned int key[4];

  key[0] = *id;
  entry = FUN_088e7604(&DAT_08beedf4, key);
  ((void (*)(struct VObject *, int))entry->object->vtable[2])(entry->object, arg);
}
