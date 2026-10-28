/* LBPMATCH module=EBOOT.BIN start=0x0889a888 end=0x0889a8c0 symbol=FUN_0889a888 lang=c99 cc=gcc410-Os */
/* Mechanical translation of Ghidra pseudocode (lbpgen.py tag g2); exact match verified; names and types await human review.; readability pass (lane rd4d, Claude Sonnet) */
struct Obj {
  char unk_00[8];
  unsigned char unk_08;
  char unk_09[2];
  unsigned char unk_0b;
};

extern struct Obj *FUN_0889a3bc();

/* Sets the byte at +0xb to 1 when the byte at +8 is set. */
void FUN_0889a888(void)
{
  struct Obj *obj;

  obj = FUN_0889a3bc();
  if (obj->unk_08 != 0) {
    obj = FUN_0889a3bc();
    obj->unk_0b = 1;
  }
  return;
}
