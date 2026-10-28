/* LBPMATCH module=EBOOT.BIN start=0x088dc4b4 end=0x088dc4fc symbol=FUN_088dc4b4 lang=c99 cc=gcc402t-Os */
/* Mechanical translation of Ghidra pseudocode (lbpgen.py tag g5); exact match verified; names and types await human review.; readability pass (lane rd4b, Claude Sonnet) */
#include "lbp/rd4b_ptrlist.h"

struct Record {
  char data[0x34];
};

struct Inner {
  char pad_00[0x10];
  unsigned short unk_10;   /* index into the owner's record table */
};

struct Item {
  char pad_00[0x18];
  struct Inner *inner;   /* +0x18 */
};

struct Owner {
  char pad_00[0x160];
  struct Record *records;   /* +0x160: table of 0x34-byte records */
};

extern struct PtrListHolder *DAT_08beee0c;

/* Picks the record of `self` indexed by the last item of the DAT_08beee0c list (item 0 if the list is empty). */
struct Record *FUN_088dc4b4(struct Owner *self)
{
  struct Item *item;

  item = 0;
  if ((DAT_08beee0c != 0) && (DAT_08beee0c->begin != DAT_08beee0c->end)) {
    item = (struct Item *)DAT_08beee0c->end[-1];
  }
  return self->records + item->inner->unk_10;
}
