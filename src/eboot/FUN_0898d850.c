/* LBPMATCH module=EBOOT.BIN start=0x0898d850 end=0x0898d8b4 symbol=FUN_0898d850 lang=c99 cc=gcc402x-Os */
/* Mechanical translation of Ghidra pseudocode (lbpgen.py tag g6); exact match verified; names and types await human review; readability pass (lane rd1c, Claude Sonnet) */
#define NAME_CAPACITY 0x40   /* 63 characters copied plus a forced terminator */

struct NamedEntry {          /* 0x4c bytes */
  unsigned int a;
  unsigned int b;
  unsigned int c;
  char name[NAME_CAPACITY];
};

struct NamedEntryList {
  int unk_00;
  int count;                 /* +4: number of entries in use */
  struct NamedEntry *entries; /* +8 */
};

extern char *FUN_08ba10e8();  /* strncpy-like: (dest, src, length) */

/* Appends one entry; the caller must have reserved room. */
void FUN_0898d850(struct NamedEntryList *list, unsigned int a, unsigned int b, unsigned int c, char *name)
{
  struct NamedEntry *entry;

  entry = list->entries + list->count;
  list->count = list->count + 1;
  entry->a = a;
  entry->b = b;
  entry->c = c;
  FUN_08ba10e8(entry->name, name, NAME_CAPACITY - 1);
  entry->name[NAME_CAPACITY - 1] = 0;
  return;
}
