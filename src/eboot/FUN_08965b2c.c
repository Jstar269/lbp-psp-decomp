/* LBPMATCH module=EBOOT.BIN start=0x08965b2c end=0x08965b48 symbol=FUN_08965b2c lang=c99 cc=gcc410-Os */
/* Mechanical translation of Ghidra pseudocode (lbpgen.py tag g2); exact match verified; names and types await human review.; readability pass (lane rd4d, Claude Sonnet) */
/* 'MAIN' as a little-endian word. */
#define TAG_MAIN 0x4e49414d

struct Tagged {
  int tag;
};

struct Target {
  int unk_00;
  int unk_04;
};

/* Copies `value` into the target only when the tag is TAG_MAIN; always returns 0. */
int FUN_08965b2c(struct Tagged *tagged, int value, struct Target *target)
{
  if (tagged->tag == TAG_MAIN) {
    target->unk_04 = value;
  }
  return 0;
}
