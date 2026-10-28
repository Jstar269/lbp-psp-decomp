/* LBPMATCH module=EBOOT.BIN start=0x0887c06c end=0x0887c0e4 symbol=FUN_0887c06c lang=c99 cc=gcc402x-Os */
/* Mechanical translation of Ghidra pseudocode (lbpgen.py tag g6); exact match verified; names and types await human review; readability pass (lane rd1c, Claude Sonnet) */
struct SubObject;

struct SubObjectVtbl {
  void *unk_00[3];
  void (*slot_0c)(struct SubObject *self);
};

struct SubObject {
  const struct SubObjectVtbl *vtbl;
};

/* Pointee of each entry: an object with a SubObject embedded at +0xc. */
struct Member {
  char unk_00[0xc];
  struct SubObject sub;
};

struct MemberEntry {          /* 12 bytes */
  struct Member *member;
  unsigned int unk_04[2];
};

struct MemberSet {
  char unk_00[0x2c];
  struct MemberEntry entries[1];   /* +0x2c: one entry per bit of active_mask (bit i -> entries[i]) */
  char unk_38[0xc8];
  unsigned int active_mask;        /* +0x100 */
  char unk_104[0xbc];
  unsigned char done;              /* +0x1c0: set once the pass below has run */
  char unk_1c1[3];
  int state;                       /* +0x1c4: -1 means nothing to do */
};

/* One-shot pass: calls slot 3 of the embedded SubObject of every entry whose bit is set in active_mask. */
void FUN_0887c06c(struct MemberSet *self)
{
  unsigned int mask;
  unsigned int low_bit;
  struct MemberEntry *entry;

  if ((self->state != -1) &&
     (entry = self->entries, self->done == '\0')) {
    mask = self->active_mask;
    self->done = 1;
    while (low_bit = mask & 1, mask != 0) {
      mask = mask >> 1;
      if (low_bit != 0) {
        entry->member->sub.vtbl->slot_0c(&entry->member->sub);
      }
      entry = entry + 1;
    }
  }
  return;
}
