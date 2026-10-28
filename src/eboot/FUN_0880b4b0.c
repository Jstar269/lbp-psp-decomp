/* LBPMATCH module=EBOOT.BIN start=0x0880b4b0 end=0x0880b568 symbol=FUN_0880b4b0 lang=c99 cc=gcc404xs-Os */
/* Mechanical translation of Ghidra pseudocode (lbpgen.py tag g14); exact match verified; names and types await human review; readability pass (lane rd1c, Claude Sonnet) */
struct KindedObject {
  char unk_00[0x44];
  int kind;                  /* +0x44: one of a small set of ids (meaning unknown) */
};

/* Returns 1 when the object's kind is one of 14 listed ids, else 0. */
unsigned int FUN_0880b4b0(void *unused, struct KindedObject *object)
{
  int kind;

  kind = object->kind;
  if (kind == 0x1f || kind == 0x28 || kind == 0x2c || kind == 0x29 || kind == 0x14 ||
      kind == 0x15 || kind == 0x2b || kind == 0x36 || kind == 5 || kind == 4 ||
      kind == 0x17 || kind == 0x38 || kind == 0xe || kind == 10) {
    return 1;
  }
  return 0;
}
