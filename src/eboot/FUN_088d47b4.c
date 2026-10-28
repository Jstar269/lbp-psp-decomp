/* LBPMATCH module=EBOOT.BIN start=0x088d47b4 end=0x088d48cc symbol=FUN_088d47b4 lang=c99 cc=gcc402x-Os */
/* Mechanical translation of Ghidra pseudocode (lbpgen.py tag g9); exact match verified; names and types await human review.; readability pass (lane rd1a, Claude Sonnet) */

#include "lbp/tagged_rec.h"

/* Resets a TaggedRec to its initial state: tag and defaults set, everything else zero, byte table 0xff. */
extern void *memset(void *dst, int value, unsigned int count);

void FUN_088d47b4(struct TaggedRec *rec)
{
  struct TaggedRecEntry *entry;
  int remaining;

  rec->tag = 0x31324546;
  remaining = 10;
  rec->mode = 3;
  rec->unk_38 = 0xffff;
  rec->unk_7c = 0xffff;
  rec->unk_82 = 0xff;
  rec->unk_00 = 0;
  rec->unk_04 = 0;
  rec->unk_08 = 0;
  rec->unk_0c = 0;
  rec->unk_10 = 0;
  rec->unk_14 = 0;
  rec->unk_16 = 0;
  rec->unk_18 = 0;
  rec->unk_1a = 0;
  rec->unk_20 = 0;
  rec->unk_24 = 0;
  rec->unk_64 = 0;
  rec->unk_68 = 0;
  rec->unk_6c = 0;
  rec->unk_70 = 0;
  rec->unk_74 = 0;
  rec->unk_78 = 0;
  rec->unk_7e = 0;
  rec->unk_80 = 0;
  rec->unk_8e = 0;
  rec->unk_8f = 0;
  entry = rec->entries;
  do {
    remaining = remaining + -1;
    entry->byte0 = 0;
    entry->byte1 = 0;
    entry->half2 = 0;
    entry->word4 = 0;
    entry = entry + 1;
  } while (remaining != 0);
  rec->unk_2c = 0;
  rec->unk_30 = 0;
  rec->unk_34 = 0;
  memset(rec->bytes_84, 0xff, 10);
  memset(rec->entries, 0, 0x50);
  memset(rec->block_3c, 0, 0x14);
  memset(rec->block_50, 0, 0x14);
}
