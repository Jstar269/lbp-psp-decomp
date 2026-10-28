/* LBPMATCH module=EBOOT.BIN start=0x0887c0e4 end=0x0887c14c symbol=FUN_0887c0e4 lang=c99 cc=gcc402x-Os */
/* Mechanical translation of Ghidra pseudocode (lbpgen.py tag g6); exact match verified; names and types await human review; readability pass (lane rd2a, Claude Sonnet) */
#include "lbp/rd2a_object.h"

struct ChannelSlot {
  struct VObject *obj;   /* +0 */
  int unk_04;
  int unk_08;
};

struct ChannelBank {
  char unk_00[0x2c];
  struct ChannelSlot slots[17];   /* +0x2c, stride 0xc; count inferred from the next field's offset */
  char unk_f8[8];
  unsigned int active_mask;       /* +0x100: bit i set = slots[i] is in use */
};

/* Calls virtual slot 7 (vtable + 0x1c) of every active slot's object with `value`. */
void FUN_0887c0e4(struct ChannelBank *self, unsigned char value)
{
  unsigned int bit;
  unsigned int mask;
  struct ChannelSlot *slot;

  slot = self->slots;
  mask = self->active_mask;
  while (bit = mask & 1, mask != 0) {
    mask = mask >> 1;
    if (bit != 0) {
      (*slot->obj->vtable[7])(slot->obj, value);
    }
    slot = slot + 1;
  }
}
