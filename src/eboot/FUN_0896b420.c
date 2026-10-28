/* LBPMATCH module=EBOOT.BIN start=0x0896b420 end=0x0896b4a0 symbol=FUN_0896b420 lang=c99 cc=gcc402x-Os */
/* Mechanical translation of Ghidra pseudocode (lbpgen.py tag g6); exact match verified; names and types await human review; readability pass (lane rd1c, Claude Sonnet) */
/* Heap object with a 16-bit reference count at +6. */
struct Counted {
  char unk_00[6];
  short refcount;
};

struct IndexedTable {
  int *entries;
  short index;               /* +4: selected entry, -1 when none */
  short unk_06;
};

extern void FUN_08970b6c();  /* drops one reference of a Counted */
extern unsigned int FUN_08979e88();

/* Looks up the selected entry and calls FUN_08979e88 with it and a temporary extra reference to *handle_ptr.
   Returns 1 without calling when nothing is selected. */
unsigned int FUN_0896b420(struct IndexedTable *table, struct Counted **handle_ptr)
{
  int entry;
  unsigned int result;
  struct Counted *handle;

  result = 1;
  if (table->index != -1) {
    handle = *handle_ptr;
    entry = table->entries[table->index];
    if (handle != 0) {
      handle->refcount = handle->refcount + 1;
    }
    result = FUN_08979e88(entry, &handle);
    if (handle != 0) {
      FUN_08970b6c(handle);
    }
  }
  return result;
}
