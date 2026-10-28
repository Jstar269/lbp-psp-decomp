/* LBPMATCH module=EBOOT.BIN start=0x0894fccc end=0x0894fd10 symbol=FUN_0894fccc lang=c99 cc=gcc410-Os */
/* Mechanical translation of Ghidra pseudocode (lbpgen.py tag g2); exact match verified; names and types await human review; readability pass (lane rd2a, Claude Sonnet) */
struct FixupDesc {
  int unk_00;
  int table_offset;   /* +4: offset of the fixup table from `base` */
  int table_size;     /* +8: size of the table in bytes */
};

/* Converts self-relative offsets into absolute pointers. Each word of the fixup table (located at
   base + table_offset) holds the offset, relative to that word, of a field; a non-zero field is then
   rebased by adding its own address. Always returns 0. */
int FUN_0894fccc(struct FixupDesc *desc, int base)
{
  int *field;
  int *entry;
  int *table_end;

  entry = (int *)(base + desc->table_offset);
  table_end = (int *)((int)entry + desc->table_size);
  while (entry < table_end) {
    field = (int *)((int)entry + *entry);
    entry = entry + 1;
    if (field != 0 && *field != 0) {
      *field = *field + (int)field;
    }
  }
  return 0;
}
